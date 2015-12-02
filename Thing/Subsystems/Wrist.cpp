/*
 * Wrist.cpp
 *
 *  Created on: May 4, 2015
 *      Author: billcoon
 */

#include "Wrist.h"

Wrist* Wrist::instance = NULL;

Wrist::Wrist()
	:	wristMotor(WRIST_CONTROL_PIN)
{
	// TODO Auto-generated constructor stub

}

Wrist::~Wrist(){
	// TODO Auto-generated destructor stub
}

Wrist* Wrist::getInstance(){
	if(!instance)
		instance = new Wrist();
	return instance;
}

void Wrist::init(){
	wristMotor.startServo();
}

/*
 * startMotion(int speed, bool direction)
 * speed: Integer between -100 and 100
 * direction: true:FWD, false:REV
 */

void Wrist::startMotion(int speed, bool direction){
	if(direction==FWD){
		wristMotor.setSpeed(speed);
	}else{
		wristMotor.setSpeed(-speed);
	}
}

void Wrist::stopMotion(){
	wristMotor.setSpeed(0);
}
