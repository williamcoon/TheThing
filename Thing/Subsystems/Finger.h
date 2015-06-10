/*
 * Finger.h
 *
 *  Created on: Apr 22, 2015
 *      Author: williamcoon
 */

#ifndef FINGER_H_
#define FINGER_H_

#include "PinDefinitions.h"
#include "Victor.h"

class Finger {
public:
	Finger(int controlPin, int reedPin, int forwardSpeed, int reverseSpeed, String name);
	void startMotion(int targetPosition, int motionSpeed);
	void startMotion(int targetPosition);
	void update();
	bool isFinished();
	void init();
	void incrementCount();
	void setHomePosition();
	void stopMotion();
private:
	Victor fingerMotor;
	int targetPos;
	int startPos;
	volatile int currentPos;
	int targetSpeed;
	bool direction;
	bool finished;
	volatile unsigned long lastTickTime;
	bool enabled;
	int reed_pin;
	int forwardSpeed;
	int reverseSpeed;
	String name;
	void disableMotor();
};

#endif /* FINGER_H_ */
