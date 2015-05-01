/*
 * TankDrive.h
 *
 *  Created on: Apr 28, 2015
 *      Author: williamcoon
 */

#ifndef SUBSYSTEMS_TANKDRIVE_H_
#define SUBSYSTEMS_TANKDRIVE_H_

#include "Arduino.h"
#include "Victor.h"
#include "PinDefinitions.h"

class TankDrive {
public:
	static TankDrive *getInstance();
	virtual ~TankDrive();
	void drive(int leftSpeed, int rightSpeed);
	void stop();
private:
	TankDrive();
	static TankDrive *instance;
	Victor leftMotor;
	Victor rightMotor;
};

#endif /* SUBSYSTEMS_TANKDRIVE_H_ */
