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
#define PINKY_CONTROL_PIN 3
#define RING_CONTROL_PIN 4
#define MIDDLE_CONTROL_PIN 5
#define INDEX_CONTROL_PIN 6
#define THUMB_CONTROL_PIN 7

#define WRIST_CONTROL_PIN 10

//Counter pin definitions
#define PINKY_COUNT_PIN 2 //Interrupt 0
#define RING_COUNT_PIN 3 //Interrupt 1
#define MIDDLE_COUNT_PIN 21 //Interrupt 2
#define INDEX_COUNT_PIN 20 //Interrupt 3
#define THUMB_COUNT_PIN 19 //Interrupt 4

//DriveTrain Definitions
#define TANK_LEFT_CONTROL_PIN 8
#define TANK_RIGHT_CONTROL_PIN 9

#endif /* PINDEFINITIONS_H_ */
