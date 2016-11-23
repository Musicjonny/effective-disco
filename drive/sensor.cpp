#include "sensor.h"

void setup_sensor(){
pinMode(Widerstand_Sensor_Links, INPUT);
  pinMode(Widerstand_Sensor_Rechts, INPUT);
  pinMode(LED_Links, OUTPUT);
  pinMode(LED_Rechts, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_Links, HIGH);
  digitalWrite(LED_Rechts, HIGH);
}

int Sensor_Links(){
  int Puffer_1[10]={0,0,0,0,0,0,0,0,0,0};
  int Puffer_2[10]={0,0,0,0,0,0,0,0,0,0};
  int i,j = 0;
  int Mittel_Wert = 0;
  int Sum_1 = 0;
  int Sum_2 = 0;
  int Schleife = 0;
  
  for (j=0;j<=500;j++){
    if (Schleife == 0){
      for (i=0;i<=9;i++){
        Puffer_1[i]=analogRead(Widerstand_Sensor_Links);
        Sum_1 += Puffer_1[i];                 
        }
                      Schleife +=1;
                      Mittel_Wert = Sum_1/10;
                      return Mittel_Wert;

                      }
                  else if (Schleife != 0){
                   
                    for (i=0;i<=9;i++)
                          {
                        if (i<9){
                           Puffer_2[i+1] = Puffer_1[i];
                            Sum_2 += Puffer_2[i+1];
                            Puffer_1[i+1] = Puffer_2[i+1];
                                } 
                                              
                          }
                        
                        Puffer_2[0] = analogRead(Widerstand_Sensor_Rechts);
                        Puffer_1[0] = Puffer_2[0];
                        Mittel_Wert = (Sum_2 + Puffer_2[0])/10;
                     return Mittel_Wert;
                     
                      }
                  
              } 
}

bool is_sensor_left(){
  
  if (Sensor_Links() > Schwellwert_Links){
    Serial.println("left: true");
    return true;
  }
    
  else {
    Serial.println("left: false");
    return false;
  }
}

bool is_sensor_right(){
//  int Puffer=0;
//  int i;
//  int Mittel_Wert=0;
//  
//  for(i=0;i <= 30;i++) 
//  {
//      Puffer += analogRead(Widerstand_Sensor_Rechts);
//  }
//  Mittel_Wert = Puffer/i;
//  
//  if (Mittel_Wert < Schwellwert_Rechts){
//    Serial.println("right: true");
//    return true;
//  }
//    
//  else {
//    Serial.println("right: false");
//    return false;
//  }#
return false;
}


