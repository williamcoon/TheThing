/*
 * TankDrive.cpp
 *
 *  Created on: Apr 28, 2015
 *      Author: williamcoon
 */

#include <TankDrive.h>
#define CENTER_PWM 127
#define MAX_PWM 127

TankDrive* TankDrive::instance = NULL;

TankDrive::TankDrive()
	:	leftPWM(TANK_LEFT_PWM),
		rightPWM(TANK_RIGHT_PWM)
{
	pinMode(leftPWM, OUTPUT);
	pinMode(rightPWM, OUTPUT);
	analogWrite(leftPWM, CENTER_PWM);
	analogWrite(rightPWM, CENTER_PWM);
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
	int leftVal = CENTER_PWM + (int)((leftSpeed/100.0)*MAX_PWM);
	int rightVal = CENTER_PWM + (int)((rightSpeed/100.0)*MAX_PWM);
	analogWrite(leftPWM, leftVal);
	analogWrite(rightPWM, rightVal);
}

void TankDrive::stop(){
	analogWrite(leftPWM, CENTER_PWM);
	analogWrite(rightPWM, CENTER_PWM);
}

