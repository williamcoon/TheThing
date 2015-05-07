/*
 * Finger.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: williamcoon
 */

#include <Finger.h>

Finger::Finger(int controlPin)
	:	fingerMotor(controlPin),
		targetPos(0),
		currentPos(0),
		direction(FWD),
		finished(true)
{

}

void Finger::startMotion(int targetPosition, int motionSpeed){
	//int targetPosition: The desired counter value to move to
	//double motionSpeed: The speed to move (number between 0 and 100)
	finished = false;
	targetPos = targetPosition;
	direction = (targetPos>currentPos)?FWD:REV;
	if(direction==FWD){
		fingerMotor.setSpeed(motionSpeed);
	}else{
		fingerMotor.setSpeed(-motionSpeed);
	}
}

void Finger::stopMotion(){
	//Set motor speed to zero;
	fingerMotor.setSpeed(0);
	finished = true;
}

void Finger::update(){
	//Check if we're at the target position
	if(!finished){
		if((direction&&currentPos>=targetPos)|(!direction&&currentPos<=targetPos)){
			stopMotion();
		}
	}
}

bool Finger::isFinished(){
	return finished;
}

void Finger::init(){
	fingerMotor.startServo();
}

void Finger::incrementCount(){
	currentPos += (direction==FWD) ? 1:-1; //Increment or decrement based on fwd/rev direction
}

