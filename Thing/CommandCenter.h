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
	CommandCenter();
	virtual ~CommandCenter();
	void addCommand(CommandBase *command);
	void update();
private:
	QueueList <CommandBase *> commands;
	CommandBase *currentCommand;
};

#endif /* COMMANDCENTER_H_ */
