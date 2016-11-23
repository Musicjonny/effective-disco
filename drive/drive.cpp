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
      analogWrite(R_BWD,velocity);
      digitalWrite(L_FWD,LOW);
      analogWrite(L_BWD,velocity);
      digitalWrite(R_EN,HIGH);
      digitalWrite(L_EN, HIGH);
      delay(1000);
      break;

    case FWD:
      analogWrite(R_FWD,velocity);
      digitalWrite(R_BWD,LOW);
      analogWrite(L_FWD,velocity);
      digitalWrite(L_BWD,LOW);
      digitalWrite(R_EN,HIGH);
      digitalWrite(L_EN, HIGH);
      break;

    case LEFT:
      digitalWrite(L_FWD,LOW);
      analogWrite(L_BWD,velocity);
      digitalWrite(R_FWD,velocity);
      digitalWrite(R_BWD,LOW);
      digitalWrite(L_EN, HIGH);
      digitalWrite(R_EN, HIGH);
      break;

    case RIGHT:
      digitalWrite(R_FWD,LOW);
      analogWrite(R_BWD,velocity);
      digitalWrite(R_EN, HIGH);
      analogWrite(L_FWD,velocity);
      digitalWrite(L_BWD,LOW);
      digitalWrite(L_EN, HIGH);
      break;

      case STOP:
      digitalWrite(R_FWD, LOW);
      digitalWrite(R_BWD, LOW);
      digitalWrite(L_FWD, LOW);
      digitalWrite(L_BWD, LOW);
      digitalWrite(R_EN, LOW);
      digitalWrite(L_EN, LOW);
      break;

      case TURNRIGHT:
      analogWrite(R_FWD,velocity);
      analogWrite(R_BWD,LOW);
      digitalWrite(R_EN, HIGH);
      analogWrite(L_FWD,(velocity*7/10));
      digitalWrite(L_BWD,LOW);
      digitalWrite(L_EN, HIGH);
      break;

      case TURNLEFT:
      analogWrite(L_FWD,velocity);
      analogWrite(R_BWD,LOW);
      digitalWrite(R_EN, HIGH);
      analogWrite(R_FWD,(velocity*8/10));
      digitalWrite(L_BWD,LOW);
      digitalWrite(L_EN, HIGH);
      break;
  }
}
