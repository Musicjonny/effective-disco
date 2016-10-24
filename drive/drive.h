//drive.h
#include <Arduino.h>

#ifndef DRIVE_H
#define DRIVE_H

#define L_EN 7 //Pin Motor Left
#define L_FWD 8
#define L_BWD 9
#define R_EN 10 //Pin Motor Right
#define R_FWD 11
#define R_BWD 12
#define FWD 0
#define BWD 1
#define RIGHT 2
#define LEFT 3
#define STOP

void setup_motor();

void drive(int, int);

#endif
