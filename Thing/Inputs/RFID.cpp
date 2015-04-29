/*
 * RFID.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: williamcoon
 */

#include <RFID.h>

RFID::RFID(HardwareSerial *s)
	: serial(s),
	  tagID(""),
	  commandCreator()
{
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
	if(!commandCreator.createCommand(tag, NULL)){
		Serial.println("RFID tag does not have a matching function");
		Serial.print("Tag ID: ");
		Serial.println(tag);
	}
}

void RFID::update(){
	tagID += readSerial();
	//TODO: This should be more robust. Could check for beginning/end of tag,
	//and I think the last two bytes are a checksum too
	if(tagID.length() >= 16){
		createTagCommand(tagID.substring(1,13));
		tagID = "";
	}
}


