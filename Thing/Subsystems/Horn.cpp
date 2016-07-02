/*
 * Horn.cpp
 *
 *  Created on: May 29, 2016
 *      Author: billcoon
 */

#include <Horn.h>
#include "Arduino.h"

Horn::Horn(int hornPin)
	:hornPin(hornPin)
{

}

Horn::~Horn() {
	// TODO Auto-generated destructor stub
}

void Horn::init(){
	pinMode(hornPin, OUTPUT);
	digitalWrite(hornPin, LOW);
}

void Horn::turnOn(){
	digitalWrite(hornPin, HIGH);
}

void Horn::turnOff(){
	digitalWrite(hornPin, LOW);
}

