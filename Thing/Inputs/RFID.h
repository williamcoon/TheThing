/*
 * RFID.h
 *
 *  Created on: Apr 29, 2015
 *      Author: williamcoon
 */

#ifndef INPUTS_RFID_H_
#define INPUTS_RFID_H_

#include "Arduino.h"
#include "PinDefinitions.h"

class RFID {
public:
	static RFID *getInstance();
	void init(HardwareSerial *, unsigned long);
	void clearSerial();
	void resetReader();
	String getCurrentTag();
	static const char* NO_TAG;
private:
	RFID();
	static RFID *instance;
	HardwareSerial *serial;
	String readSerial();
	String tagID;
	unsigned long baud;
};

#endif /* INPUTS_RFID_H_ */
