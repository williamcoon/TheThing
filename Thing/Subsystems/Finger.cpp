/*
 * Finger.cpp
 *
 *  Created on: Apr 22, 2015
 *      Author: williamcoon
 */

#include <Finger.h>
#define TICK_TIMEOUT 500 //TODO: Calculate timeout based on speed

Finger::Finger(int controlPin, int reed_pin, String name)
	:	fingerMotor(controlPin),
		targetPos(0),
		currentPos(0),
		direction(FWD),
		finished(true),
		lastTickTime(0),
		enabled(true),
		reed_pin(reed_pin),
		name(name)
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
		Serial.print(name);
		Serial.println(" is disabled.");
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
	Serial.print(name);
	Serial.println(" has been disabled due to bad hall reading");
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
		if(direction==REV&&!digitalRead(reed_pin)){
			stopMotion();
			Serial.print(name);
			Serial.println(" stopped motion due to reed limit");
			setHomePosition();
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
}

void Finger::setHomePosition(){
	currentPos = 0;
}

