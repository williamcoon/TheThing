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
	//Serial.print("X: ");
	//Serial.println(x);
//	Serial.print("   Y: ");
//	Serial.println(y);
	double right = y - x*TURN_DAMP;
	double left = y + x*TURN_DAMP;
	//Serial.print("Right : ");
	//Serial.println(right);
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
	//Serial.print("Right speed: ");
	//Serial.println(rightSpeed);
	leftSpeed = round(left*MAX_SPEED);
}

int Joystick::getLeftSpeed(){
	return leftSpeed;
}

int Joystick::getRightSpeed(){
	return rightSpeed;
}

double Joystick::getX(){
	return (mapValue(analogRead(xAxisPin)));
}

double Joystick::getY(){
	return (mapValue(analogRead(yAxisPin)));
}

/*
 * Returns double from 0 to 1.0 based on raw digital read
 */
double Joystick::mapValue(int rawVal, bool squared){
	//If within dead zone, just return zero to ignore noise.
	if(rawVal < (POT_ZERO + DEAD_ZONE) && (rawVal > (POT_ZERO - DEAD_ZONE))){
		return 0;
	}
	//Serial.print("Raw: ");
	//Serial.println(rawVal);
	double val = ((double)(rawVal-POT_ZERO))/POT_ZERO;

	//Square then inputs to make driving less jerky
	if(val < 0){
		val = -1*(val*val);
	}else{
		val = val*val;
	}
	//Serial.print("Val: ");
	//Serial.println(val);
	return val;
}
