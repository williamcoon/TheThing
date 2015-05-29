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
#include "Victor.h"
#include "BackAndForth.h"
#include "FindHome.h"
#include "WiggleFingers.h"
#include "EjectBlock.h"
#include "Poof.h"
#include "StopAll.h"

class CommandCreator {
public:
	static CommandCreator* getInstance();
	virtual ~CommandCreator();
	bool createCommand(String command, Parameters *params);
	bool createCommand(String command);
private:
	CommandCreator();
	static CommandCreator* instance;
	static CommandCenter *commandCenter;
	StringHashTable commandHash;
	static bool printSomething(Parameters *params);
	static bool moveFinger(Parameters *params);
	static bool moveHand(Parameters *params);
	static bool drive(Parameters *params);
	static bool rfidDrive1(Parameters *params);
	static bool rfidDrive2(Parameters *params);
	static bool rfidDrive3(Parameters *params);
	static bool calibrateVictor(Parameters *params);
	static bool backAndForth(Parameters *params);
	static bool findHome(Parameters *params);
	static bool wiggleFingers(Parameters *params);
	static bool testParallel(Parameters *params);
	static bool smallPoof(Parameters *params);
	static bool stopAll(Parameters *params);
};

#endif /* COMMANDS_COMMANDCREATOR_H_ */
