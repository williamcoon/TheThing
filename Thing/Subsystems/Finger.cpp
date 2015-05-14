/*
 * Finger.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: williamcoon
 */

#include <Finger.h>
#define TICK_TIMEOUT 500 //TODO: Calculate timeout based on speed

Finger::Finger(int controlPin)
	:	fingerMotor(controlPin),
		targetPos(0),
		currentPos(0),
		direction(FWD),
		finished(true),
		lastTickTime(0),
		enabled(true)
{

}

void Finger::startMotion(int targetPosition, int motionSpeed){
	//int targetPosition: The desired counter value to move to
	//double motionSpeed: The speed to move (number between 0 and 100)
	if(enabled){
		finished = false;
		targetPos = targetPosition;
		direction = (targetPos>currentPos)?FWD:REV;
		lastTickTime = millis();
		if(direction==FWD){
			fingerMotor.setSpeed(motionSpeed);
		}else{
			fingerMotor.setSpeed(-motionSpeed);
		}
	}else{
		Serial.print("Motor has been disabled due to no readings from hall effect sensor.");
	}
}

void Finger::stopMotion(){
	//Set motor speed to zero;
	fingerMotor.setSpeed(0);
	finished = true;
}

void Finger::disableMotor(){
	//Call this if we're not seeing any sensor "ticks" even though we are powering the motor.
	//This is to prevent destroying a finger in the case that there is a fault in the hall effect sensor
	fingerMotor.setSpeed(0);
	finished = true;
	enabled = false;
	Serial.println("Motor has been disabled");
}

void Finger::update(){
	//Check if we're at the target position
	if(!finished){
		if((millis()-lastTickTime)>TICK_TIMEOUT){
			disableMotor();
		}
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
	lastTickTime = millis(); //Reset counter to detect sensor malfunction
//	Serial.print("Count: ");
//	Serial.println(currentPos);
}

