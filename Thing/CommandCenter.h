/*
 * CommandCenter.h
 *
 *  Created on: Apr 23, 2015
 *      Author: williamcoon
 */

#ifndef COMMANDCENTER_H_
#define COMMANDCENTER_H_
#include "QueueList.h"
#include "CommandBase.h"

class CommandCenter {
public:
	virtual ~CommandCenter();
	void addCommand(CommandBase *command);
	void update();
	static CommandCenter* getInstance();
private:
	QueueList <CommandBase *> commands;
	CommandBase *currentCommand;
	CommandCenter();
	static CommandCenter *instance;
};

#endif /* COMMANDCENTER_H_ */
