/*
 * Victor.cpp
 *
 *  Created on: May 1, 2015
 *      Author: williamcoon
 */

#include <Victor.h>

Victor::Victor(uint8_t pin)
	:	servoPin(pin)
{
	// TODO Auto-generated constructor stub
	servo.attach(servoPin);
}

Victor::~Victor() {
	// TODO Auto-generated destructor stub
}

/*
 * setSpeed(int8_t speed)
 * speed: Integer from -100 to 100 mapping full reverse to full forward
 */

void Victor::setSpeed(int8_t speed){
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

