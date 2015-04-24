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

class SerialHandler {
public:
	SerialHandler(HardwareSerial *s);
	void update();
private:
	String readSerial();
	Parameters *getParameters(String paramString);
	void executeNextCommand();
	HardwareSerial *serial;
	const unsigned int MAX_SIZE;
	String buffer;
	const String DELIMETER;
};

#endif /* INPUTS_SERIALHANDLER_H_ */
