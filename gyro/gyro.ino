/*
The sensor outputs provided by the library are the raw 16-bit values
obtained by concatenating the 8-bit high and low gyro data registers.
They can be converted to units of dps (degrees per second) using the
conversion factors specified in the datasheet for your particular
device and full scale setting (gain).

Example: An L3GD20H gives a gyro X axis reading of 345 with its
default full scale setting of +/- 245 dps. The So specification
in the L3GD20H datasheet (page 10) states a conversion factor of 8.75
mdps/LSB (least significant bit) at this FS setting, so the raw
reading of 345 corresponds to 345 * 8.75 = 3020 mdps = 3.02 dps.
*/

#include <Wire.h>
#include <L3G.h>

L3G gyro;
long drehung = 0;
long richtung = 0;
static int LED1 = 12;
static int LED2 = 11;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }

  gyro.enableDefault();
}

long i = 0;
long sum = 0;

void loop() {
  gyro.read();

//  Serial.print(" Aktuelle Drehung: ");
  drehung = (int)gyro.g.z-230;
  
/* Mittelwert
  while(i < 100000){
    sum += drehung;
    i++;
    //if (i % 1000 == 0)
   //   Serial.println(i);
  }
  Serial.println((float)sum/100000);
  sum = 0;
  i = 0;
 */

  if (drehung > -70 && drehung < 70) 
    drehung = 0;
  drehung = drehung/100;
  Serial.println(drehung);
 // Serial.print(", Drehrichtung: ");
  richtung += drehung;
  if (richtung > 1000){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  }
 //   Serial.println("Rechts");
  else if (richtung < -1000){
    digitalWrite(LED2, HIGH);
    digitalWrite(LED1, LOW);
  }
  
  
//    Serial.println("Links");
  else{
    digitalWrite(LED2, LOW);
    digitalWrite(LED1, LOW);
  }
 //   Serial.println("gerade");
  Serial.println(richtung);
}
