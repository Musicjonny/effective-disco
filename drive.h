//drive.h
#include <Arduino.h>

#ifndef DRIVE_H
#define DRIVE_H

#define MOTOR_L_ENABLE //Pin Motor Left
#define MOTOR_L_FWD
#define MOTOR_L_BWD
#define MOTOR_R_ENABLE //Pin Motor Right
#define MOTOR_R_FWD
#define MOTOR_R_BWD

void setup_motor(){
  pinMode(MOTOR_R_ENABLE, OUTPUT);
  pinMode(MOTOR_R_FWD);
  pinMode(MOTOR_R_BWD);
}

void drive(){
  digitalWrite(MOTOR_R_FWD,LOW);
  digitalWrite(MOTOR_R_BWD,HIGH);
  digitalWrite(MOTOR_R_ENABLE,HIGH);
  delay(1000);
  digitalWrite(MOTOR_R_ENABLE,LOW);
  delay(1000);
}

#endif
