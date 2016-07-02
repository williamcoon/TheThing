/*
 * LedButton.h
 *
 *  Created on: Jun 4, 2015
 *      Author: billcoon
 */

#ifndef SUBSYSTEMS_LEDBUTTON_H_
#define SUBSYSTEMS_LEDBUTTON_H_

#include "Arduino.h"

class LedButton {
public:
	LedButton(int inputPin, int ledPin, bool latching=true, bool hasLed=true);
	virtual ~LedButton();
	void init();
	void poll();
	bool readButton();
	void enable();
	void disable();

private:
	void handleInterrupt();
	int inputPin;
	int ledPin;
	bool latched;
	bool enabled;
	bool latching;
	bool hasLed;
};

#endif /* SUBSYSTEMS_LEDBUTTON_H_ */
