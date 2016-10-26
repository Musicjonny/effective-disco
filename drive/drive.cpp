#include "drive.h"

void setup_motor(){
  pinMode(R_EN, OUTPUT);
  pinMode(R_FWD, OUTPUT);
  pinMode(R_BWD, OUTPUT);
  pinMode(L_EN, OUTPUT);
  pinMode(L_FWD, OUTPUT);
  pinMode(L_BWD, OUTPUT);
}

void drive(int i, int velocity){
  switch(i){

    case BWD:
      digitalWrite(R_FWD,LOW);
      digitalWrite(R_BWD,HIGH);
      digitalWrite(L_FWD,LOW);
      digitalWrite(L_BWD,HIGH);
      digitalWrite(R_EN,HIGH);
      digitalWrite(L_EN, HIGH);
      delay(1000);
      break;

    case FWD:
      analogWrite(R_FWD,255);
      digitalWrite(R_BWD,LOW);
      analogWrite(L_FWD,255);
      digitalWrite(L_BWD,LOW);
      digitalWrite(R_EN,HIGH);
      digitalWrite(L_EN, HIGH);
      delay(1000);
      break;

    case LEFT:
      digitalWrite(L_FWD,LOW);
      digitalWrite(L_BWD,HIGH);
      digitalWrite(L_EN, HIGH);
      delay(1000);
      break;

    case RIGHT:
      digitalWrite(R_FWD,LOW);
      digitalWrite(R_BWD,HIGH);
      digitalWrite(R_EN, HIGH);
      digitalWrite(L_BWD,HIGH);
      digitalWrite(L_FWD,LOW);
      digitalWrite(L_EN, HIGH);
      delay(1000);
      
      break;

      case STOP:
      digitalWrite(R_FWD, LOW);
      digitalWrite(R_BWD, LOW);
      digitalWrite(L_FWD, LOW);
      digitalWrite(L_BWD, LOW);
      digitalWrite(R_EN, LOW);
      digitalWrite(L_EN, LOW);
      break;
  }
}
