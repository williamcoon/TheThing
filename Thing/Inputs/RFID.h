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

class RFID {
public:
	RFID(HardwareSerial *);
	void update();
private:
	HardwareSerial *serial;
	String readSerial();
	String tagID;
	void createTagCommand(String string);
	CommandCreator commandCreator;
};

#endif /* INPUTS_RFID_H_ */
