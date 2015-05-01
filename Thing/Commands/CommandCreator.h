/*
 * CommandCreator.h
 *
 *  Created on: Apr 27, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_COMMANDCREATOR_H_
#define COMMANDS_COMMANDCREATOR_H_

#include "Arduino.h"
#include "Parameters.h"
#include "CommandCenter.h"
#include "StringHashTable.h"
#include "PrintCommand.h"
#include "MoveFinger.h"
#include "MoveHand.h"
#include "Drive.h"

class CommandCreator {
public:
	CommandCreator();
	virtual ~CommandCreator();
	bool createCommand(String command, Parameters *params);
	bool createCommand(String command);
private:
	static CommandCenter *commandCenter;
	StringHashTable commandHash;
	static bool printSomething(Parameters *params);
	static bool moveFinger(Parameters *params);
	static bool moveHand(Parameters *params);
	static bool drive(Parameters *params);
	static bool rfidDrive1(Parameters *params);
	static bool rfidDrive2(Parameters *params);
	static bool rfidDrive3(Parameters *params);
};

#endif /* COMMANDS_COMMANDCREATOR_H_ */
