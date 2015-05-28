/*
 * Ejector.cpp
 *
 *  Created on: May 28, 2015
 *      Author: williamcoon
 */

#include <Ejector.h>

Ejector * Ejector::instance = NULL;

Ejector::Ejector()
	:ejectorPin(EJECTOR_PIN) {
	// TODO Auto-generated constructor stub
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
	pinMode(ejectorPin, OUTPUT);
	digitalWrite(ejectorPin, LOW);
}

void Ejector::extend(){
	digitalWrite(ejectorPin, HIGH);
}

void Ejector::retract(){
	digitalWrite(ejectorPin, LOW);
}

