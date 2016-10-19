//drive.h
#include <Arduino.h>

#ifndef DRIVE_H
#define DRIVE_H

#define MOTOR_L_ENABLE 7 //Pin Motor Left
#define MOTOR_L_FWD 8
#define MOTOR_L_BWD 9
#define MOTOR_R_ENABLE 10 //Pin Motor Right
#define MOTOR_R_FWD 11
#define MOTOR_R_BWD 12
#define FWD 0
#define BWD 1
#define RIGHT 2
#define LEFT 3

void setup_motor();

void drive(int);

#endif
