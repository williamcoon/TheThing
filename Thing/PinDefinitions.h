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

#define WRIST_CONTROL_PIN 30

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
#define TANK_RIGHT_CONTROL_PIN 28

//Buttons
#define START_BUTTON A8
#define START_LED 31
#define STOP_BUTTON A9
#define STOP_LED 29

//Joystick
#define X_AXIS_PIN A11
#define Y_AXIS_PIN A12

//Other Pins
#define STATUS_PIN 13
#define EJECTOR_EXTEND_PIN 0 //unused
#define EJECTOR_RETRACT_PIN 0 //unused
#define BEANIE_LED_PIN 37
#define POOFER_PIN 15
#define RFID_RESET_PIN 27
#define RFID_RX_PIN 17

//Speed Constants
#define PINKY_FWD_SPEED 40
#define PINKY_REV_SPEED 80
#define RING_FWD_SPEED 50
#define RING_REV_SPEED 90
#define MIDDLE_FWD_SPEED 40
#define MIDDLE_REV_SPEED 80
#define INDEX_FWD_SPEED 50
#define INDEX_REV_SPEED 80
#define THUMB_FWD_SPEED 50
#define THUMB_REV_SPEED 70

#endif /* PINDEFINITIONS_H_ */
