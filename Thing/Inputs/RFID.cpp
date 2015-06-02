/*
 * RFID.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: williamcoon
 */

#include <RFID.h>

#define TIMEOUT 5000

CommandCreator* RFID::commandCreator = CommandCreator::getInstance();
RFID* RFID::instance = NULL;

RFID::RFID()
	: serial(&Serial1),
	  tagID(""),
	  reading(false),
	  lastEjectTime(0),
	  lastReadTime(0)
{
}

RFID* RFID::getInstance(){
	if(!instance)
		instance = new RFID();
	return instance;
}

void RFID::init(){
	pinMode(RFID_RESET_PIN, OUTPUT);
	digitalWrite(RFID_RESET_PIN, HIGH);
}

void RFID::startReading(){
	reading = true;
	clearSerial(); //Get rid of any junk in the buffer
	resetReader(); //Reset the reader to re-read the currently present tag
}

void RFID::clearSerial(){
	while(serial->available() > 0){
		serial->read();
	}
}

void RFID::resetReader(){
	digitalWrite(RFID_RESET_PIN, LOW);
	digitalWrite(RFID_RESET_PIN, HIGH);
}

void RFID::setLastEjectTime(){
	lastEjectTime = millis();
}

String RFID::readSerial(){
	char newChar = 0;
	String str = "";
	while((serial->available()) > 0){
		newChar = serial->read();
		str+=newChar;
	}
	return str;
}

void RFID::createTagCommand(String tag){
	if(!commandCreator->createCommand(tag, NULL)){
		Serial.println("RFID tag does not have a matching function");
		Serial.print("Tag ID: ");
		Serial.println(tag);
		commandCreator->createCommand("eject", NULL);
	}
}

void RFID::update(){
	tagID += readSerial();
	//TODO: This should be more robust. Could check for beginning/end of tag,
	//and I think the last two bytes are a checksum too
	if(tagID.length() >= 16){
		lastReadTime = millis();
		if(reading){
			createTagCommand(tagID.substring(1,13));
		}else{
			Serial.print("Tag ID: ");
			Serial.print(tagID.substring(1,13));
			Serial.println(" (RFID execution currently not enabled)");
		}
		tagID = "";
	}else if(lastEjectTime>lastReadTime && reading){
		if((millis() - lastEjectTime)>TIMEOUT){
			//No new blocks to read, stop reading and stop everything
			reading = false;
			Serial.println("No more blocks");
			commandCreator->createCommand("stop", NULL);
		}
	}
}


