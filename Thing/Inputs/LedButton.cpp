/*
 * LedButton.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: billcoon
 */

#include "LedButton.h"

LedButton::LedButton(int inputPin, int ledPin, bool latching, bool hasLed)
	: inputPin(inputPin),
	  ledPin(ledPin),
	  latched(false),
	  enabled(false),
	  latching(latching),
	  hasLed(hasLed)
{
}

LedButton::~LedButton() {
	// TODO Auto-generated destructor stub
}

void LedButton::init(){
	pinMode(inputPin, INPUT);
	digitalWrite(inputPin, HIGH);
	if(hasLed){
		pinMode(ledPin, OUTPUT);
		digitalWrite(ledPin, LOW);
	}
}

void LedButton::enable(){
	if(hasLed){
		digitalWrite(ledPin, HIGH);
	}
	enabled = true;
}

void LedButton::disable(){
	if(hasLed){
		digitalWrite(ledPin, LOW);
	}
	enabled = false;
}

void LedButton::poll(){
	if(enabled){
		if(!digitalRead(inputPin)){
			latched = true;
		}
	}
}

bool LedButton::readButton(){
	if(latching){
		bool ret = latched;
		latched = false;
		return ret;
	}else{
		return digitalRead(inputPin);
	}
}




