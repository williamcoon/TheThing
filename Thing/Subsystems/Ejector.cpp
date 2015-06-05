/*
 * Ejector.cpp
 *
 *  Created on: May 28, 2015
 *      Author: williamcoon
 */

#include <Ejector.h>


Ejector * Ejector::instance = NULL;

Ejector::Ejector()
	:	solenoid(new Solenoid(EJECTOR_EXTEND_PIN, EJECTOR_RETRACT_PIN)),
		lastRetractTime(0)
{
}

Ejector::~Ejector() {
	// TODO Auto-generated destructor stub
}

Ejector* Ejector::getInstance(){
	if(!instance)
		instance = new Ejector();
	return instance;
}

void Ejector::init(){
	solenoid->init();
}

void Ejector::extend(){
	solenoid->extend();
}

void Ejector::retract(){
	solenoid->retract();
	lastRetractTime = millis();
}

void Ejector::turnOff(){
	solenoid->turnOff();
}

unsigned long Ejector::getLastRetractTime(){
	return lastRetractTime;
}

