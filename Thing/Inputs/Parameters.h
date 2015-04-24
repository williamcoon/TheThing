/*
 * Parameters.h
 *
 *  Created on: Apr 24, 2015
 *      Author: williamcoon
 */

#ifndef INPUTS_PARAMETERS_H_
#define INPUTS_PARAMETERS_H_

#include "Arduino.h"

typedef enum{int_type, string_type, bool_type} VALUE_TYPE;

typedef union{
	int intVal;
	char strVal[50];
	bool boolVal;
}VALUE;

struct parameter_t{
	VALUE val;
	VALUE_TYPE val_type;
};

class Parameters {
public:
	Parameters();
	int getInt(int paramIndex);
	String getString(int paramIndex);
	bool getBool(int paramIndex);
	void setValue(int paramIndex, String val);
private:
	parameter_t *parameters[5];
};

#endif /* INPUTS_PARAMETERS_H_ */
