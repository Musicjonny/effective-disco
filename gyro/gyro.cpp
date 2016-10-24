#include "gyro.h"

void setup_gyro(){
  Serial.begin(9600);
  L3G gyro;
  Wire.begin();
  L3G gyro;
  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }

  gyro.enableDefault();
}

void read_rotation(){
  Serial.println((int)gyro.g.z);
  delay(100);
}

int add_rotation(){
  rotation += (int)gyro.g.z;
  return rotation;
}

