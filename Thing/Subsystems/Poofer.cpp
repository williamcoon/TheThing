/*
 * Poofer.cpp
 *
 *  Created on: May 28, 2015
 *      Author: williamcoon
 */

#include "Poofer.h"

Poofer* Poofer::instance = NULL;

Poofer::Poofer()
	:pooferPin(POOFER_PIN){
	// TODO Auto-generated constructor stub
}

Poofer::~Poofer() {
	// TODO Auto-generated destructor stub
}

Poofer* Poofer::getInstance(){
	if(!instance)
		instance = new Poofer();
	return instance;
}

void Poofer::init(){
	pinMode(pooferPin, OUTPUT);
	digitalWrite(pooferPin, LOW);
}

void Poofer::openFire(){
	digitalWrite(pooferPin, HIGH);
}

void Poofer::ceaseFire(){
	digitalWrite(pooferPin, LOW);
}
