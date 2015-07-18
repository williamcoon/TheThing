/*
 * CommandCenter.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: williamcoon
 */

#include <CommandCenter.h>

CommandCenter* CommandCenter::instance = NULL;

CommandCenter::CommandCenter() {
	currentCommands = NULL;
	currentSize = 0;
}

CommandCenter::~CommandCenter() {
	while(!commands.isEmpty()){
		CommandBase *cmd = commands.pop();
		delete cmd;
		cmd = NULL;
	}
}

CommandCenter* CommandCenter::getInstance(){
	if(!instance)
		instance = new CommandCenter();
	return instance;
}

void CommandCenter::addCommand(CommandBase *command){
	//Put the command in the back of the queue
	commands.push(command);
}

void CommandCenter::stageCommands(){
	//Check if there is a new command on the queue
	if(!commands.isEmpty()){
		QueueList <CommandBase*>commandStage;
		bool popNext = true;
		while(popNext){
			//Pop all of the commands into a new queue until you find one that isn't parallel
			CommandBase *newCommand = commands.pop();
			newCommand->init();
			commandStage.push(newCommand);
			if(!newCommand->isParallel()){
				popNext = false;
			}
		}
		//Allocate an array and put the new commands into it
		currentSize = commandStage.count();
		currentCommands = new CommandBase*[currentSize];
		for(int i=0; i<currentSize; i++){
			currentCommands[i] = commandStage.pop();
		}
	}
}

void CommandCenter::executeRunningCommands(){
	bool allFinished = true;
	for(int i=0; i<currentSize; i++){
		if(!currentCommands[i]->isFinished()){
			currentCommands[i]->execute();
			allFinished = false;
		}
	}
	if(allFinished){
		//Delete all of the commands and clear the currentCommands array
		Serial.println("All finished");
		for(int i=0; i<currentSize; i++){
			delete currentCommands[i];
		}
		currentSize = 0;
		delete[] currentCommands;
		currentCommands = NULL;
	}
}

void CommandCenter::update(){
	if(currentCommands == NULL){
		stageCommands();
	}
	if(currentCommands!= NULL){
		executeRunningCommands();
	}
}

void CommandCenter::clearCommands(){
	for(int i=0; i<currentSize; i++){
		currentCommands[i]->stop();
		delete currentCommands[i];
	}
	while(!commands.isEmpty()){
		commands.pop();
	}
	if(currentSize>0){
		delete[] currentCommands;
		currentCommands = NULL;
		currentSize = 0;
	}
}
