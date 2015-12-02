/*
 * Drive.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: williamcoon
 */

#include "Drive.h"

TankDrive* Drive::tankDrive = TankDrive::getInstance();

Drive::Drive(int leftSpeed, int rightSpeed, int time)
	: finished(false),
	  leftSpeed(leftSpeed),
	  rightSpeed(rightSpeed),
	  time(time),
	  driveTime(0),
	  startTime(0)
{
}

Drive::~Drive() {
	// TODO Auto-generated destructor stub
}

void Drive::init(){
	tankDrive->drive(leftSpeed, rightSpeed);
	if(time<0){
		//Don't keep time, just set speed forever. Drivetrain will continue until
		//the next Drive command comes in and changes speeds
		finished = true;
	}else{
		driveTime = (unsigned long)time*1000; //Convert to milliseconds
		startTime = millis();
		finished = false;
	}
}

void Drive::execute(){
	unsigned long currentTime = millis();
	if((currentTime-startTime) >= driveTime){
		stop();
	}
}

bool Drive::isFinished(){
	return finished;
}

void Drive::stop(){
	tankDrive->stop();
	finished = true;
}
