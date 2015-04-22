/*
 * Finger.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: williamcoon
 */

#include <Finger.h>

Finger::Finger(int pwmPin, int counterPin):counter(counterPin) {
	Finger::pwmPin = pwmPin;
	pinMode(pwmPin, OUTPUT);
	analogWrite(pwmPin, CENTER_PWM);
	targetPos = 0;
	currentPos = 0;
	direction = FWD;
	finished = true;
}

void Finger::startMotion(int targetPosition, double motionSpeed){
	//int targetPosition: The desired counter value to move to
	//double motionSpeed: The speed to move (number between 0 and 1)
	finished = false;
	targetPos = targetPosition;
	direction = (targetPos>currentPos)?FWD:REV;
	//Resolve speed/direction into a PWM duty cycle between 0 and 255;
	int pwmVal;
	if(direction==FWD){
		pwmVal = CENTER_PWM + (int)(motionSpeed*MAX_PWM);
	}else{
		pwmVal = CENTER_PWM - (int)(motionSpeed*MAX_PWM);
	}
	analogWrite(pwmPin, pwmVal);
}

void Finger::stopMotion(){
	//Set motor speed to zero;
	analogWrite(pwmPin, CENTER_PWM);
	finished = true;
}

void Finger::update(){
	counter.update(direction);
	currentPos = counter.getCount();
	if((direction&&currentPos>=targetPos)|(!direction&&currentPos<=targetPos)){
		stopMotion();
	}
}

bool Finger::isFinished(){
	return finished;
}

Finger::~Finger() {
	// TODO Auto-generated destructor stub
}

