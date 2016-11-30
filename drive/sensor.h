#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

#define Widerstand_Sensor_Links A0
#define Widerstand_Sensor_Rechts A1
#define Widerstand_Sensor_Mitte A2
#define LED_Links 11
#define LED_Rechts 12
#define LED_Mitte 4

void setup_sensor();

int Sensor_Rechts (); //gibt einen gemittelten Helligkeitswert für den rechten Sensor aus
int Sensor_Links (); //gibt einen gemittelten Helligkeitswert für den linken Sensor aus
int Sensor_Mitte (); //gibt einen gemittelten Helligkeitswert für den mittleren Sensor aus

/*
if no sensor detects white: return 0
left sensor white: return 1
right sensor white: return 2
both sensors white: return 3
only middle sensor: return 4
*/

int which_sensor();  



#endif
