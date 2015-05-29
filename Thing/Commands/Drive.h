/*
 * Drive.h
 *
 *  Created on: Apr 28, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_DRIVE_H_
#define COMMANDS_DRIVE_H_

#include <CommandBase.h>
#include "TankDrive.h"

class Drive: public CommandBase {
public:
	Drive(int leftSpeed, int rightSpeed, int time);
	virtual ~Drive();
	void init();
	void execute();
	bool isFinished();
	void stop();
private:
	bool finished;
	int leftSpeed;
	int rightSpeed;
	int time;
	unsigned long driveTime;
	unsigned long startTime;
	static TankDrive *tankDrive;
};

#endif /* COMMANDS_DRIVE_H_ */
