/*
 * TankDrive.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: williamcoon
 */

#include "TankDrive.h"

TankDrive* TankDrive::instance = NULL;

TankDrive::TankDrive()
	:	leftMotor(TANK_LEFT_CONTROL_PIN),
		rightMotor(TANK_RIGHT_CONTROL_PIN)
{

}

TankDrive::~TankDrive() {
	// TODO Auto-generated destructor stub
}

TankDrive* TankDrive::getInstance(){
	if(!instance)
		instance = new TankDrive();
	return instance;
}

void TankDrive::init(){
	leftMotor.startServo();
	rightMotor.startServo();
}

/*
 * drive(int leftSpeed, int rightSpeed)
 * int leftSpeed: Integer between -100 and 100 corresponding to 0 to 100% power in FWD or REV
 * int rightSpeed: Integer between -100 and 100 corresponding to 0 to 100% power in FWD or REV
 */
void TankDrive::drive(int leftSpeed, int rightSpeed){
	leftMotor.setSpeed(leftSpeed);
	rightMotor.setSpeed(-rightSpeed);
}

void TankDrive::stop(){
	leftMotor.setSpeed(0);
	rightMotor.setSpeed(0);
}

