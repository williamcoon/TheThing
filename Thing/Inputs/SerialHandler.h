/*
 * SerialHandler.h
 *
 *  Created on: Apr 24, 2015
 *      Author: williamcoon
 */

#ifndef INPUTS_SERIALHANDLER_H_
#define INPUTS_SERIALHANDLER_H_

#include "Arduino.h"
#include "Parameters.h"
#include "CommandCreator.h"

class SerialHandler {
public:
	SerialHandler(HardwareSerial *);
	void update();
	void init();
private:
	String readSerial();
	Parameters *getParameters(String paramString);
	void parseCommand();
	HardwareSerial *serial;
	const unsigned int MAX_SIZE;
	String buffer;
	static CommandCreator *commandCreator;
};

#endif /* INPUTS_SERIALHANDLER_H_ */
