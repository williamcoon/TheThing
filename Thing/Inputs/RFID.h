/*
 * RFID.h
 *
 *  Created on: Apr 29, 2015
 *      Author: williamcoon
 */

#ifndef INPUTS_RFID_H_
#define INPUTS_RFID_H_

#include "Arduino.h"
#include "CommandCreator.h"
#include "StopAll.h"
#include "CommandBase.h"

class CommandCreator;

class RFID {
public:
	static RFID* getInstance();
	void update();
	void init();
	void startReading();
	void setLastEjectTime();
private:
	RFID();
	static RFID *instance;
	HardwareSerial *serial;
	String readSerial();
	void clearSerial();
	void resetReader();
	String tagID;
	void createTagCommand(String string);
	static CommandCreator *commandCreator;
	bool reading;
	unsigned long lastEjectTime;
	unsigned long lastReadTime;
};

#endif /* INPUTS_RFID_H_ */
