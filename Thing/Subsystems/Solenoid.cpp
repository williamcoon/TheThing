/*
 * Solenoid.cpp
 *
 *  Created on: Jun 4, 2015
 *      Author: billcoon
 */

#include "Solenoid.h"

Solenoid::Solenoid(int extendPin, int retractPin)
	: extendPin(extendPin),
	  retractPin(retractPin)
{

}

Solenoid::~Solenoid() {
	// TODO Auto-generated destructor stub
}

void Solenoid::init(){
	pinMode(extendPin, OUTPUT);
	pinMode(retractPin, OUTPUT);
	digitalWrite(extendPin, LOW);
	digitalWrite(retractPin, LOW);
}

void Solenoid::extend(){
	digitalWrite(extendPin, HIGH);
	digitalWrite(retractPin, LOW);
}

void Solenoid::retract(){
	digitalWrite(extendPin, LOW);
	digitalWrite(retractPin, HIGH);
}

void Solenoid::turnOff(){
	digitalWrite(extendPin, LOW);
	digitalWrite(retractPin, LOW);
}
