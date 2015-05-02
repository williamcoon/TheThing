/*
 * Finger.h
 *
 *  Created on: Apr 22, 2015
 *      Author: williamcoon
 */

#ifndef FINGER_H_
#define FINGER_H_

#include "Counter.h"
#include "Victor.h"

class Finger {
public:
	Finger(int controlPin, int counterPin);
	void startMotion(int targetPosition, int motionSpeed);
	void update();
	bool isFinished();
	void init();
private:
	Counter counter;
	Victor fingerMotor;
	int targetPos;
	int currentPos;
	bool direction;
	bool finished;
	void stopMotion();
};

#endif /* FINGER_H_ */
