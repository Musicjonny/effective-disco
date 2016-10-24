#include "gyro.h"

#define LED1 
#define LED2 

int actual_rotation = 0;

void setup() {
  setup_gyro();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

}

void loop() {
  read_rotation();
  actual_rotation = add_rotation();
  if (actual_rotation > 0)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  }
  else if (actual_rotation < 0)
  {
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
  }

}
