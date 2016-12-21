#include "drive.h"
#include "sensor.h"

void setup() {
  setup_motor();
  setup_sensor();
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

int i = 0;

//init: wait 10 seconds 
void loop() {
  if (i == 0) {
    digitalWrite(4, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    delay(8000); //für wettbewerb auskommentieren um 10 sekunden zu warten
    digitalWrite(4, LOW);
    digitalWrite(2,LOW);
    digitalWrite(3, LOW);
    //digitalWrite(2, LOW);
    delay(2000);
  delay(1);
  }
  i = 1;

int state;
/*
if no sensor detects white: return 0
left sensor white: return 1
right sensor white: return 2
both sensors white: return 3
only middle sensor: return 4
*/
int j = 0;


for (j = 0;j < 400; j++){
state = which_sensor();
switch (state) {
  case 0:
    Serial.println("no line detected");
    digitalWrite(2,LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    drive(TURNLEFT,140);
    break;
  case 1:
    Serial.println("line detected: left");
//    drive(TURNRIGHT,180);
//    delay(800);
//    j+=400;
    digitalWrite(2,HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
      drive(STOP, 0);
      delay(500);
      drive(RIGHT,180);
      delay(220);
      drive(FWD,200);
      delay(500);
      goto hello;
    break;
  case 2:
    Serial.println("line detected: right");
    digitalWrite(2,HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    drive(STOP, 0);
    delay(200);
    drive(RIGHT,180);
    delay(150);
   // j+=400;
    goto hello;
    break;
  case 3:
    Serial.println("line detected: left AND right");
    drive(TURNLEFT,180); //WARNING, NOT THE RIGHT
    digitalWrite(2,HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    delay(600);
    break;
  case 4:
    Serial.println("line detected: middle");
    drive(FWD,180);
    digitalWrite(2,HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    delay(500);
    goto hello;
    break;
  default: 
    Serial.println("no state");
    break;
}
  

}
hello:
drive(STOP,0);
digitalWrite(3, HIGH);
  delay(1000);
digitalWrite(3, LOW);

///*simulated timed function with a for-loop */
//for (j = 0;j < 1000; j++){
//  Serial.println(j);
//
// if (is_sensor_right()) {
//    drive(RIGHT,180);
//    delay(200);
//    j+=100;
//    drive(STOP,0);
//    exit;
//  }
//
//  
//  /*if the sensor left is right, turn right for a moment */
//  else if(is_sensor_left()) {
//    drive(TURNRIGHT,180);
//    delay(150);
//    j+=200;
//  }
//  /*if the sensor left is false, turn slightly for a moment */
//  else if(!is_sensor_left()){
//    drive(RIGHT,150);
//  }
//  
//  
//}
//drive(STOP,0);
//delay(800);

}
