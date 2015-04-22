#include "Thing.h"


//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
	pinMode(13, OUTPUT);
	Serial.begin(115200);
}

// The loop function is called in an endless loop
void loop()
{
	  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
	  Serial.println("HIGH");
	  delay(1000);              // wait for a second
	  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
	  Serial.println("LOW");
	  delay(1000);              // wait for a second
}


//Thing class functions will go here

Thing::Thing(){

}
