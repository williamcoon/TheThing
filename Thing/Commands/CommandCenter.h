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
#include "StopAll.h"

class CommandCenter {
public:
	virtual ~CommandCenter();
	void addCommand(CommandBase *command);
	void update();
	void stopAll();
	static CommandCenter* getInstance();
private:
	QueueList <CommandBase *> commands;
	CommandBase **currentCommands;
	int currentSize;
	CommandCenter();
	static CommandCenter *instance;
	void stageCommands();
	void executeRunningCommands();
};

#endif /* COMMANDCENTER_H_ */
