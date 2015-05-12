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
	Finger(int controlPin);
	void startMotion(int targetPosition, int motionSpeed);
	void update();
	bool isFinished();
	void init();
	void incrementCount();
private:
	Victor fingerMotor;
	int targetPos;
	volatile int currentPos;
	bool direction;
	bool finished;
	volatile unsigned long lastTickTime;
	bool enabled;
	void stopMotion();
	void disableMotor();
};

#endif /* FINGER_H_ */
