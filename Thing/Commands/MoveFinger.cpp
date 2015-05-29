/*
 * MoveFinger.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: williamcoon
 */

#include <MoveFinger.h>

Hand* MoveFinger::hand = Hand::getInstance();

MoveFinger::MoveFinger(int fingerIndex, int targetPosition, int speed)
	: finished(false),
	  fingerIndex(fingerIndex),
	  targetPosition(targetPosition),
	  speed(speed)
{
}

MoveFinger::~MoveFinger() {
	// TODO Auto-generated destructor stub
}

void MoveFinger::init(){
	hand->fingers[fingerIndex]->startMotion(targetPosition, speed);
}

void MoveFinger::execute(){
	//This command will be called periodically while the command is running
	if(hand->fingers[fingerIndex]->isFinished()){
		finished = true;
	}
}

bool MoveFinger::isFinished(){
	//Return true when the command is done. This function is called before the call
	//to execute, and if it is finished it will be deleted.
	return finished;
}

void MoveFinger::stop(){
	finished = true;
}
