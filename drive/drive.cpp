#include "drive.h"

void setup_motor(){
  pinMode(MOTOR_R_ENABLE, OUTPUT);
  pinMode(MOTOR_R_FWD, OUTPUT);
  pinMode(MOTOR_R_BWD, OUTPUT);
  pinMode(MOTOR_L_ENABLE, OUTPUT);
  pinMode(MOTOR_L_FWD, OUTPUT);
  pinMode(MOTOR_L_BWD, OUTPUT);
}

void drive(int i){
  if (i == BWD){
    digitalWrite(MOTOR_R_FWD,LOW);
    digitalWrite(MOTOR_R_BWD,HIGH);
    digitalWrite(MOTOR_L_FWD,LOW);
    digitalWrite(MOTOR_L_BWD,HIGH);
    digitalWrite(MOTOR_R_ENABLE,HIGH);
    digitalWrite(MOTOR_L_ENABLE, HIGH);
    delay(1000);
    digitalWrite(MOTOR_R_ENABLE,LOW);
    digitalWrite(MOTOR_L_ENABLE,LOW);
    delay(1000);
  }
  else if (i == FWD){
    analogWrite(MOTOR_R_FWD,100);
    digitalWrite(MOTOR_R_BWD,LOW);
    analogWrite(MOTOR_L_FWD,100);
    digitalWrite(MOTOR_L_BWD,LOW);
    digitalWrite(MOTOR_R_ENABLE,HIGH);
    digitalWrite(MOTOR_L_ENABLE, HIGH);
    delay(1000);
    digitalWrite(MOTOR_R_ENABLE,LOW);
    digitalWrite(MOTOR_L_ENABLE,LOW);
    delay(1000);
  }
  else if (i == LEFT){
    digitalWrite(MOTOR_L_FWD,LOW);
    digitalWrite(MOTOR_L_BWD,HIGH);
    digitalWrite(MOTOR_L_ENABLE, HIGH);
    delay(1000);
    digitalWrite(MOTOR_L_ENABLE,LOW);
    delay(1000);
  }
  else if (i == RIGHT){
    digitalWrite(MOTOR_R_FWD,LOW);
    digitalWrite(MOTOR_R_BWD,HIGH);
    digitalWrite(MOTOR_R_ENABLE, HIGH);
    delay(1000);
    digitalWrite(MOTOR_R_ENABLE,LOW);
    delay(1000);
  }
}
