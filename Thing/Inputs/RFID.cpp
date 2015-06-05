/*
 * RFID.cpp
 *
 *  Created on: Apr 29, 2015
 *      Author: williamcoon
 */

#include <RFID.h>
const char* RFID::NO_TAG = "NOTAG";

RFID::RFID(HardwareSerial *s, unsigned long baud)
	: serial(s),
	  tagID(""),
	  baud(baud)
{
}

void RFID::init(){
	serial->begin(baud);
	pinMode(RFID_RESET_PIN, OUTPUT);
	digitalWrite(RFID_RESET_PIN, HIGH);
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

String RFID::readSerial(){
	char newChar = 0;
	String str = "";
	while((serial->available()) > 0){
		newChar = serial->read();
		str+=newChar;
	}
	return str;
}

String RFID::getCurrentTag(){
	tagID += readSerial();
	//TODO: This should be more robust. Could check for beginning/end of tag,
	//and I think the last two bytes are a checksum too
	if(tagID.length() >= 16){
		String ret = tagID.substring(1,13);
		tagID = "";
		return ret;
	}else{
		return NO_TAG;
	}
}


