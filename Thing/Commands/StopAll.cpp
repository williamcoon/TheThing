/*
 * StopAll.cpp
 *
 *  Created on: May 29, 2015
 *      Author: billcoon
 */

#include <StopAll.h>

TankDrive* StopAll::tankDrive = TankDrive::getInstance();
Hand* StopAll::hand = Hand::getInstance();
Poofer* StopAll::poofer = Poofer::getInstance();
Wrist* StopAll::wrist = Wrist::getInstance();

StopAll::StopAll()
	: finished(false)
{
}

StopAll::~StopAll() {
	// TODO Auto-generated destructor stub
}

void StopAll::init(){
	tankDrive->stop();
	hand->stop();
	poofer->ceaseFire();
	wrist->stopMotion();
	finished = true;
}

void StopAll::execute(){

}

void StopAll::stop(){

}

bool StopAll::isFinished(){
	return finished;
}

