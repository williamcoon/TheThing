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
	RFID(HardwareSerial *, unsigned long);
	void init();
	void clearSerial();
	void resetReader();
	String getCurrentTag();
	static const char* NO_TAG;
private:
	HardwareSerial *serial;
	String readSerial();
	String tagID;
	unsigned long baud;
};

#endif /* INPUTS_RFID_H_ */
