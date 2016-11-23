#include "drive.h"
#include "sensor.h"

void setup() {
  setup_motor();
  setup_sensor();
}

int i = 0;

void loop() {
  if (i == 0) {
    delay(10000);
  }
  i = 1;

//  if ( !is_sensor_left()){
//  /* drive left */
//    drive(LEFT,180);
//    delay(50);
//    drive(STOP,0);
//    delay(100);
//    
//    drive(FWD,220);
//    delay(80);
//    drive(FWD,170);
//    delay(200);
//    drive(STOP,0);
//    delay(400);
//    
//    Serial.println("nach links");
//  }
//
//  else if (is_sensor_left() && is_sensor_right){
//  /*drive right */
//    drive(BWD,180);
//    delay(300);
//
//    drive(RIGHT,180);
//    delay(200);
//    drive(STOP,0);
//    delay(1000);
//    
//    drive(FWD,220);
//    delay(80);
//    drive(FWD,170);
//    delay(200);
//    drive(STOP,0);
//    delay(400);
//    
//    Serial.println("LINIE!! zurück und dann nach rechts");
//  }
//
//  else if (is_sensor_left()){
//    drive(RIGHT,180);
//    delay(200);
//    drive(STOP,0);
//    delay(1000);
//    
//    drive(FWD,220);
//    delay(80);
//    drive(FWD,170);
//    delay(200);
//    drive(STOP,0);
//    delay(400);
//    
//    Serial.println("nach rechts");
//  }
//
//  else {
//    drive(STOP,0);
//    delay(1000);
//  }
int j = 0;
for (j = 0;j < 1000; j++){
  Serial.println(j);
  if(is_sensor_left()) {
    drive(TURNRIGHT,180);
    delay(200);
    j+=200;
    //Serial.println("links");
  }

  if(!is_sensor_left()){
    drive(TURNLEFT,180);
   // Serial.println("rechts");
  }
  
}
drive(STOP,0);
delay(400);

}
