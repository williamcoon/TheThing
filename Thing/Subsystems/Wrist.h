/*
 * Wrist.h
 *
 *  Created on: May 4, 2015
 *      Author: billcoon
 */

#ifndef SUBSYSTEMS_WRIST_H_
#define SUBSYSTEMS_WRIST_H_

#include "Victor.h"
#include "PinDefinitions.h"

class Wrist {
public:
	virtual ~Wrist();
	static Wrist* getInstance();
	void init();
	void startMotion(int speed, bool direction);
	void stopMotion();
private:
	Wrist();
	Victor wristMotor;
	static Wrist *instance;
};

#endif /* SUBSYSTEMS_WRIST_H_ */
