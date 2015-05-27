/*
 * CommandBase.cpp
 *
 *  Created on: May 27, 2015
 *      Author: williamcoon
 */

#include "CommandBase.h"

CommandBase::CommandBase()
	:	parallel(false){

}

bool CommandBase::isParallel(){
	return parallel;
}

void CommandBase::setParallel(bool isParallel){
	parallel = isParallel;
}

