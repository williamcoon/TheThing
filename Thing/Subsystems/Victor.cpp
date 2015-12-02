/*
 * Victor.cpp
 *
 *  Created on: May 1, 2015
 *      Author: williamcoon
 */

#include "Victor.h"

Victor::Victor(int pin)
	:	servoPin(pin),
		servo()
{

}

Victor::~Victor() {
	// TODO Auto-generated destructor stub
}

void Victor::startServo(){
	//There was an issue with trying to do this in the constructor, it seemed some
	//global variables were not being initialized before the Victor constructor so
	//the servo wouldn't operate normally
	servo.attach(servoPin);
	servo.write(90);
}

/*
 * setSpeed(int speed)
 * speed: Integer from -100 to 100 mapping full reverse to full forward
 */

void Victor::setSpeed(int speed){
	servo.write(map(speed,-100,100,0,180));
}

/*
 * calibrate()
 * This will be used to calibrate each of the Victor 888 speed controllers.
 * Not for use during normal operation.
 */

void Victor::calibrate(){
	this->setSpeed(100);
	delay(2000);
	this->setSpeed(-100);
	delay(2000);
	this->setSpeed(100);
	delay(2000);
	this->setSpeed(-100);
	delay(2000);
	this->setSpeed(0);
	delay(2000);
}

