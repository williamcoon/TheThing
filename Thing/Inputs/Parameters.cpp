/*
 * Parameters.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: williamcoon
 */

#include <Parameters.h>

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
	parameters[paramIndex] = &param;
}

int Parameters::getInt(int paramIndex){
	if(parameters[paramIndex] != NULL){
		if(parameters[paramIndex]->val_type==int_type){
			return parameters[paramIndex]->val.intVal;
		}
	}
	return NULL;
}

String Parameters::getString(int paramIndex){
	if(parameters[paramIndex] != NULL){
		if(parameters[paramIndex]->val_type==string_type){
			char *str = parameters[paramIndex]->val.strVal;
			String ret(str);
			return ret;
		}
	}
	return "";
}

bool Parameters::getBool(int paramIndex){
	if(parameters[paramIndex] != NULL){
		if(parameters[paramIndex]->val_type==bool_type){
			return parameters[paramIndex]->val.boolVal;
		}
	}
	return NULL;
}



