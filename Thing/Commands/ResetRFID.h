/*
 * ResetRFID.h
 *
 *  Created on: May 27, 2016
 *      Author: williamcoon
 */

#ifndef COMMANDS_RESETRFID_H_
#define COMMANDS_RESETRFID_H_

#include <CommandBase.h>
#include "RFID.h"
#include "Arduino.h"

class ResetRFID: public CommandBase {
public:
	ResetRFID();
	virtual ~ResetRFID();
	void init();
	void execute();
	bool isFinished();
	void stop();
private:
	static RFID *rfid;
	bool finished;
};

#endif /* COMMANDS_RESETRFID_H_ */
