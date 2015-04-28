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
	char strVal[20];
	bool boolVal;
}VALUE;

struct parameter_t{
	VALUE val;
	VALUE_TYPE val_type;
};

class Parameters {
public:
	Parameters();
	bool getInt(int paramIndex, int *val);
	bool getString(int paramIndex, String *val);
	bool getBool(int paramIndex, bool *val);
	void setValue(int paramIndex, String val);
private:
	parameter_t parameters[10];
};

#endif /* INPUTS_PARAMETERS_H_ */
