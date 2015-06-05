/*
 * LedButton.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: billcoon
 */

#include <LedButton.h>

LedButton::LedButton(int inputPin, int ledPin)
	: inputPin(inputPin),
	  ledPin(ledPin),
	  latched(false),
	  enabled(false)
{
}

LedButton::~LedButton() {
	// TODO Auto-generated destructor stub
}

void LedButton::init(){
	pinMode(inputPin, INPUT);
	digitalWrite(inputPin, HIGH);
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void LedButton::enable(){
	digitalWrite(ledPin, HIGH);
	enabled = true;
}

void LedButton::disable(){
	digitalWrite(ledPin, LOW);
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

	bool ret = latched;
	latched = false;
	return ret;
}




