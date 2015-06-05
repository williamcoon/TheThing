/*
 * SerialHandler.h
 *
 *  Created on: Apr 24, 2015
 *      Author: williamcoon
 */

#ifndef INPUTS_SERIALHANDLER_H_
#define INPUTS_SERIALHANDLER_H_

#include "Arduino.h"

class SerialHandler {
public:
	SerialHandler(HardwareSerial *, unsigned long);
	void init();
	String checkForCommand();
	static const char* NO_COMMAND;
private:
	String readSerial();
	String parseCommand();
	HardwareSerial *serial;
	const unsigned int MAX_SIZE;
	String buffer;
	unsigned long baud;
};

#endif /* INPUTS_SERIALHANDLER_H_ */
