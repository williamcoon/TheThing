/*
 * EjectBlock.cpp
 *
 *  Created on: May 28, 2015
 *      Author: williamcoon
 */

#include <EjectBlock.h>

#define EJECT_TIME 500UL //Amount of time(ms) to extend for ejection
Ejector* EjectBlock::ejector = Ejector::getInstance();
RFID* EjectBlock::rfidReader = RFID::getInstance();

EjectBlock::EjectBlock()
{
	// TODO Auto-generated constructor stub
	finished = false;
	startTime = millis();
	ejector->extend();
}

EjectBlock::~EjectBlock() {
	// TODO Auto-generated destructor stub
}

void EjectBlock::execute(){
	unsigned long currentTime = millis();
	if((currentTime-startTime) >= EJECT_TIME){
		stop();
	}
}

bool EjectBlock::isFinished(){
	rfidReader->setLastEjectTime();
	return finished;
}

void EjectBlock::stop(){
	ejector->retract();
	finished = true;
}
