#include "drive.h"
//#include "led.h"

void setup() {
  setup_motor();// put your setup code here, to run once:
  //setup_light();
}

void loop() {
  drive(LEFT);
  drive(RIGHT);
  //blinky();
}
