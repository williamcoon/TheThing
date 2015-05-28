/*
 * PinDefinitions.h
 *
 *  Created on: Apr 23, 2015
 *      Author: williamcoon
 */

#ifndef PINDEFINITIONS_H_
#define PINDEFINITIONS_H_

#define FWD true
#define REV false

//PWM pin definitions
#define PINKY_CONTROL_PIN 4
#define RING_CONTROL_PIN 5
#define MIDDLE_CONTROL_PIN 6
#define INDEX_CONTROL_PIN 7
#define THUMB_CONTROL_PIN 8

#define WRIST_CONTROL_PIN 11

//Counter pin definitions
#define PINKY_COUNT_PIN 2 //Interrupt 0
#define RING_COUNT_PIN 3 //Interrupt 1
#define MIDDLE_COUNT_PIN 21 //Interrupt 2
#define INDEX_COUNT_PIN 20 //Interrupt 3
#define THUMB_COUNT_PIN 19 //Interrupt 4

//Reed switch pin definitions
#define PINKY_REED_PIN 22
#define RING_REED_PIN 23
#define MIDDLE_REED_PIN 24
#define INDEX_REED_PIN 25
#define THUMB_REED_PIN 26

//DriveTrain Definitions
#define TANK_LEFT_CONTROL_PIN 9
#define TANK_RIGHT_CONTROL_PIN 10

//Other Pins
#define EJECTOR_PIN 12

#endif /* PINDEFINITIONS_H_ */
