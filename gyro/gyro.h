#include <Arduino.h>
#include <Wire.h>
#include <L3G.h>

#ifndef GYRO_H
#define GYRO_H

int rotation = 0;

void setup_gyro();

void read_rotation();

int add_rotation();

#endif
