/*
 * Horn.h
 *
 *  Created on: May 29, 2016
 *      Author: billcoon
 */

#ifndef SUBSYSTEMS_HORN_H_
#define SUBSYSTEMS_HORN_H_

class Horn {
public:
	Horn(int hornPin);
	virtual ~Horn();
	void init();
	void turnOn();
	void turnOff();
private:
	int hornPin;
};

#endif /* SUBSYSTEMS_HORN_H_ */
