/*
 * BeanieLed.cpp
 *
 *  Created on: May 27, 2016
 *      Author: williamcoon
 */

#include <BeanieLed.h>

BeanieLed* BeanieLed::instance = NULL;

BeanieLed::BeanieLed()
	: ledPin(BEANIE_LED_PIN)
{
}

BeanieLed::~BeanieLed() {
	// TODO Auto-generated destructor stub
}

BeanieLed* BeanieLed::getInstance(){
	if(!instance)
		instance = new BeanieLed();
	return instance;
}

void BeanieLed::init(){
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void BeanieLed::turnOn(){
	digitalWrite(ledPin, HIGH);
}

void BeanieLed::turnOff(){
	digitalWrite(ledPin, LOW);
}
