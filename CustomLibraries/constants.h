#ifndef CUSTOMCONSTANTS_H
#define CUSTOMCONSTANTS_H

// Imports
#include <FEHMotor.h>
#include <FEHServo.h>
#include <FEHIO.h>

// No custom library imports needed (screws up all sorts of things, anyways)

// I/O 
FEHMotor leftMotor(FEHMotor::Motor0, 9.0);
FEHMotor rightMotor(FEHMotor::Motor1, 9.0);
FEHServo armServo(FEHServo::Servo0);
DigitalInputPin bumpSwitch(FEHIO::P0_1);
AnalogInputPin lightSensor(FEHIO::P0_0);

// Calibration values for RPS pathfinding
float TOKEN_X, TOKEN_Y, TOKEN_HEADING;
float DDR_BLUE_LIGHT_X, DDR_LIGHT_Y;
float RPS_BUTTON_X, RPS_BUTTON_Y, RPS_BUTTON_HEADING;
float FOOSBALL_START_X, FOOSBALL_START_Y, FOOSBALL_END_X, FOOSBALL_END_Y;
float LEVER_X, LEVER_Y, LEVER_HEADING;

// Motor Percentages & Sign Fixes
const int LEFT_MOTOR_SIGN_FIX = -1;
const int RIGHT_MOTOR_SIGN_FIX = 1;
const float DEFAULT_MOTOR_PERCENT = 100;
const float LEFT_MOTOR_PERCENT = LEFT_MOTOR_SIGN_FIX * DEFAULT_MOTOR_PERCENT;
const float RIGHT_MOTOR_PERCENT = RIGHT_MOTOR_SIGN_FIX * DEFAULT_MOTOR_PERCENT;

// Tracks what percentage the motors are currently at - Purely for debugging
float currentLeftMotorPercent = -1;
float currentRightMotorPercent = -1;

// Cardinal Headings 
const float NORTH = 90;
const float EAST = 0;
const float SOUTH = 270;
const float WEST = 180;

// Hardcoded tuning values for use with RPS deadzone mitigation
const float DEGREES_PER_SECOND = (1080 / 10.0);
const float SECONDS_PER_DEGREE = (10.0 / 1080);

// Global boolean that lets us conditionally skip RPS-dependent functions when in effective deadzone
bool hasExhaustedDeadzone = false;

// Basically cached RPS values that allow the robot to semi-intelligently get back to RPS from deadzone
float lastValidX, lastValidY, lastValidHeading;

// Used to account for differences between RPS coordinates and where our robot turns around (the centroid) 
const float DISTANCE_BETWEEN_RPS_AND_CENTROID = 0;

// Misc. Mathematical Constants
#define PI 3.14159265358979323846

#endif
