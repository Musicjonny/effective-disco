#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

#define Widerstand_Sensor_Links A0
#define Widerstand_Sensor_Rechts A1
#define LED_Links 11
#define LED_Rechts 12
#define Schwellwert_Rechts 180// unterhalb 240 Weiß, Oberhalb Boden
#define Schwellwert_Links 780

void setup_sensor();

int Sensor_Rechts ();
int Sensor_Links ();

bool is_sensor_left();  //returns true, if white 
bool is_sensor_right();



#endif
