// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef Thing_H_
#define Thing_H_
#include "Arduino.h"
//add your includes for the project Thing here
#include "Counter.h"

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project Thing here

class Thing{
public:
	Thing();
}thing;


//Do not add code below this line
#endif /* Thing_H_ */
