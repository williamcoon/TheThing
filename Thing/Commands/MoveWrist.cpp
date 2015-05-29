/*
 * MoveWrist.cpp
 *
 *  Created on: May 29, 2015
 *      Author: williamcoon
 */

#include <MoveWrist.h>

Wrist* MoveWrist::wrist = Wrist::getInstance();

MoveWrist::MoveWrist(int speed, bool direction, unsigned long time)
	:	finished(false),
		speed(speed),
		direction(direction),
		time(time),
		startTime(0)
{
}

MoveWrist::~MoveWrist() {
	// TODO Auto-generated destructor stub
}

void MoveWrist::init(){
	wrist->startMotion(speed, direction);
	startTime = millis();
}

void MoveWrist::execute(){
	unsigned long current = millis();
	if((current - startTime) >= time){
		stop();
	}
}

bool MoveWrist::isFinished(){
	return finished;
}

void MoveWrist::stop(){
	wrist->stopMotion();
	finished = true;
}
