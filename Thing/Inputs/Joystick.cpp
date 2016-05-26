/*
 * Joystick.cpp
 *
 *  Created on: May 26, 2016
 *      Author: williamcoon
 */

#include <Joystick.h>

Joystick::Joystick(int xAxisPin, int yAxisPin)
	: xAxisPin(xAxisPin),
	  yAxisPin(yAxisPin),
	  leftSpeed(0),
	  rightSpeed(0)
{

}

Joystick::~Joystick() {
	// TODO Auto-generated destructor stub
}

void Joystick::init(){
	pinMode(xAxisPin, INPUT);
	pinMode(yAxisPin, INPUT);
}

void Joystick::readJoystick(){
	double x = getX();
	double y = getY();
	double right = y - TURN_DAMP*x;
	double left = y + TURN_DAMP*x;
	if(right >= 0){
		right = min(right, 1.0);
	}else{
		right = max(right, -1.0);
	}
	if(left >= 0){
		left = min(left, 1.0);
	}else{
		left = max(left, -1.0);
	}
	rightSpeed = round(right*MAX_SPEED);
	leftSpeed = round(left*MAX_SPEED);
}

int Joystick::getLeftSpeed(){
	return leftSpeed;
}

int Joystick::getRightSpeed(){
	return rightSpeed;
}

int Joystick::getX(){
	return (mapValue(digitalRead(xAxisPin)));
}

int Joystick::getY(){
	return (mapValue(digitalRead(yAxisPin)));
}

/*
 * Returns double from 0 to 1.0 based on raw digital read
 */
double Joystick::mapValue(int rawVal, bool squared){
	//If within dead zone, just return zero to ignore noise.
	if(rawVal < (POT_ZERO + DEAD_ZONE) && (rawVal > (POT_ZERO - DEAD_ZONE))){
		return 0;
	}
	double val = ((double)(rawVal-POT_ZERO))/POT_ZERO;
	//Square then inputs to make driving less jerky
	if(val < 0){
		val = -1*(val*val);
	}else{
		val = val*val;
	}
	return val;
}
