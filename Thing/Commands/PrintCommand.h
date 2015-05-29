/*
 * PrintCommand.h
 *
 *  Created on: Apr 23, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDS_PRINTCOMMAND_H_
#define COMMANDS_PRINTCOMMAND_H_

#include <Commands/CommandBase.h>
#include <Arduino.h>

class PrintCommand: public CommandBase {
public:
	PrintCommand(String s, int repeats);
	void init();
	void execute();
	bool isFinished();
	void stop();
private:
	String str;
	int repeats;
	int count;
	bool finished;
};

#endif /* COMMANDS_PRINTCOMMAND_H_ */
