/*
 * TankDrive.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: williamcoon
 */

#include <TankDrive.h>

TankDrive* TankDrive::instance = NULL;

TankDrive::TankDrive()
	:	leftMotor(TANK_LEFT_PWM),
		rightMotor(TANK_RIGHT_PWM)
{
	leftMotor.setSpeed(0);
	rightMotor.setSpeed(0);
}

TankDrive::~TankDrive() {
	// TODO Auto-generated destructor stub
}

TankDrive* TankDrive::getInstance(){
	if(!instance)
		instance = new TankDrive();
	return instance;
}

/*
 * drive(int leftSpeed, int rightSpeed)
 * int leftSpeed: Integer between -100 and 100 corresponding to 0 to 100% power in FWD or REV
 * int rightSpeed: Integer between -100 and 100 corresponding to 0 to 100% power in FWD or REV
 */
void TankDrive::drive(int leftSpeed, int rightSpeed){
	leftMotor.setSpeed(leftSpeed);
	rightMotor.setSpeed(rightSpeed);
}

void TankDrive::stop(){
	leftMotor.setSpeed(0);
	rightMotor.setSpeed(0);
}

