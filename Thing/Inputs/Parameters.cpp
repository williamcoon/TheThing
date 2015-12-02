/*
 * Parameters.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: williamcoon
 */

#include "Parameters.h"

Parameters::Parameters()
	:	parameters()
{

}

void Parameters::setValue(int paramIndex, String val){
	parameter_t  param;
	val.trim();
	if(val.indexOf("\"")>=0){
		//This is a string
		param.val_type = string_type;
		val.replace("\"", "");
		val.toCharArray(param.val.strVal, 50);
	}else if(val.equals("true")){
		//Bool type true
		param.val_type = bool_type;
		param.val.boolVal = true;
	}else if(val.equals("false")){
		//Bool type false
		param.val_type = bool_type;
		param.val.boolVal = false;
	}else{
		//Should be an integer
		param.val_type = int_type;
		char buf[val.length()+1];
		val.toCharArray(buf,val.length()+1);
		param.val.intVal = atoi(buf);
	}
	parameters[paramIndex] = param;
}

bool Parameters::getInt(int paramIndex, int *val){
	if(parameters[paramIndex].val_type==int_type){
		*val = parameters[paramIndex].val.intVal;
		return true;
	}
	Serial.print("Expected integer in parameters at index ");
	Serial.println(paramIndex);
	return false;
}

bool Parameters::getString(int paramIndex, String *val){
	if(parameters[paramIndex].val_type==string_type){
		char *str = parameters[paramIndex].val.strVal;
		String ret(str);
		*val = ret;
		return true;
	}
	Serial.print("Expected string in parameters at index ");
	Serial.println(paramIndex);
	return false;
}

bool Parameters::getBool(int paramIndex, bool *val){
	if(parameters[paramIndex].val_type==bool_type){
		*val = parameters[paramIndex].val.boolVal;
		return true;
	}
	Serial.print("Expected boolean(true/false) in parameters at index ");
	Serial.println(paramIndex);
	return false;
}



