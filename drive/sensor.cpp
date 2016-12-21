#include "sensor.h"


//initialisiert die Pins der Helligkeitssensoren
void setup_sensor(){
  pinMode(Widerstand_Sensor_Links, INPUT);
  pinMode(Widerstand_Sensor_Rechts, INPUT);
  pinMode(Widerstand_Sensor_Mitte, INPUT);
  pinMode(LED_Links, OUTPUT);
  pinMode(LED_Rechts, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED_Links, HIGH);
  digitalWrite(LED_Rechts, HIGH);
  
}

int Mittel_Wert_Final;
int Threshold = 90;

int which_sensor(){
  long Rechts = Sensor_Rechts();
  long Links = Sensor_Links();
  long Hinten = Sensor_Mitte();
  Serial.print("Rechts: ");
  Serial.println(Rechts);
  Serial.print("Links: ");
  Serial.println(Links);
  Serial.print("Mitte: ");
  Serial.println(Hinten);

  //print aktuellen Wert aus
  Serial.print("Rechts aktuell:");
  Serial.println(analogRead(Widerstand_Sensor_Rechts));
  Serial.print("links aktuell:");
  Serial.println(analogRead(Widerstand_Sensor_Links));
  Serial.print("mitte aktuell:");
  Serial.println(analogRead(Widerstand_Sensor_Mitte));

check:
  if ((Links + Threshold) > Rechts && (Links - Threshold) < Rechts){ //links und rechts sind gleich? wenn ja --> mitte überprüfen
  if ((Links + Threshold) > Hinten && (Links - Threshold) < Hinten){ //links und rechts UND mitte sind gleich? --> wenn ja: keine Linie
    for(int bla = 0; bla < 10; bla++){ //check sensor 10 times before returning state
      if((Sensor_Links() + Threshold) > Hinten && (Sensor_Links() - Threshold) < Hinten){
        if(bla == 9){
          Serial.println("Schwarz alle");
          return 0;
        }
      }
      else goto check;
    }
    
  }
  else if ((Links + Threshold) < Hinten ){ //wenn mitte größer als (links und rechts) --> links UND rechts auf der linie
    for(int bla = 0; bla < 10; bla++){ //check sensor 10 times before returning state
      if((Sensor_Links() + Threshold) < Hinten){
        if(bla == 9){
          Serial.println("Links und Rechts auf weiss");
          return 3;
        }
      }
      else goto check;
    }
  }
  else if ((Links - Threshold) > Hinten){ //sonst ist mitte kleiner als (links und rechts) --> NUR mitte
    for(int bla = 0; bla < 10; bla++){
      if((Sensor_Links() - Threshold) > Hinten){
        if(bla == 9){
          Serial.println("Nur hinten auf weiss");
          return 4;
        }
      }
      else goto check;
    }
  }
}
else if ((Links + Threshold) < Rechts){ //wenn links kleiner als rechts ist --> links auf linie
  for(int bla = 0; bla < 10; bla++){
    if((Sensor_Links() + Threshold) < Rechts){
      if(bla == 9){
        Serial.println("Nur Links auf weiss");
        return 1;
      }
    }
    else goto check;
  }
}
else if ((Links - Threshold) > Rechts){ //wenn links größer als rechts ist --> rechts auf der linie
  for(int bla = 0; bla < 10; bla++){
    if((Sensor_Links() - Threshold) > Rechts){
      if(bla == 9){
        Serial.println("Nur Rechts auf weiss");
        return 2;
      }
    }
    else goto check;
  }
}
}






int Sensor_Links(){
  long Puffer_1[20]={0};
  long Puffer_2[20]={0};
  int i,j = 0;
  long Mittel_Wert = 0;
  long Sum_1 = 0;
  long Sum_2 = 0;
  long Schleife = 0;
  
  for (j=0;j<=500;j++){
    if (Schleife == 0){
      for (i=0;i<=19;i++){
        Puffer_1[i]=analogRead(Widerstand_Sensor_Links)*10/6;
        Sum_1 += Puffer_1[i];                 
      }
      Schleife +=1;
      Mittel_Wert = Sum_1/10;
      return Mittel_Wert-5;
    }
      else if (Schleife != 0){
        for (i=0;i<=19;i++){
          if (i<19){
            Puffer_2[i+1] = Puffer_1[i];
            Sum_2 += Puffer_2[i+1];
            Puffer_1[i+1] = Puffer_2[i+1];
          }                       
        }
        Puffer_2[0] = analogRead(Widerstand_Sensor_Links)*10/6;
        Puffer_1[0] = Puffer_2[0];
        Mittel_Wert = (Sum_2 + Puffer_2[0])/10;
        return Mittel_Wert;
        
      }
   } 
}

long Sensor_Rechts(){
  long Puffer_1[20]={0};
  long Puffer_2[20]={0};
  int i,j = 0;
  long Mittel_Wert = 0;
  long Sum_1 = 0;
  long Sum_2 = 0;
  long Schleife = 0;
  
  for (j=0;j<=500;j++){
    if (Schleife == 0){
      for (i=0;i<=19;i++){
        Puffer_1[i]=analogRead(Widerstand_Sensor_Rechts)*100/60;
        Sum_1 += Puffer_1[i];                 
      }
      Schleife +=1;
      Mittel_Wert = Sum_1/10;
      return Mittel_Wert-5;
    }
      else if (Schleife != 0){
        for (i=0;i<=19;i++){
          if (i<19){
            Puffer_2[i+1] = Puffer_1[i];
            Sum_2 += Puffer_2[i+1];
            Puffer_1[i+1] = Puffer_2[i+1];
          }                       
        }
        Puffer_2[0] = analogRead(Widerstand_Sensor_Rechts)*100/60;
        Puffer_1[0] = Puffer_2[0];
        Mittel_Wert = (Sum_2 + Puffer_2[0])/10;
        return Mittel_Wert;
      }
   } 
}

int Sensor_Mitte(){
  int Puffer_1[20]={0};
  int Puffer_2[20]={0};
  int i,j = 0;
  int Mittel_Wert = 0;
  int Sum_1 = 0;
  int Sum_2 = 0;
  int Schleife = 0;
  
  for (j=0;j<=500;j++){
    if (Schleife == 0){
      for (i=0;i<=19;i++){
        Puffer_1[i]=analogRead(Widerstand_Sensor_Mitte)*10/9;
        Sum_1 += Puffer_1[i];                 
      }
      Schleife +=1;
      Mittel_Wert = Sum_1/10;
      return Mittel_Wert-5;
    }
      else if (Schleife != 0){
        for (i=0;i<=19;i++){
          if (i<19){
            Puffer_2[i+1] = Puffer_1[i];
            Sum_2 += Puffer_2[i+1];
            Puffer_1[i+1] = Puffer_2[i+1];
          }                       
        }
        Puffer_2[0] = analogRead(Widerstand_Sensor_Mitte)*10/9;
        Puffer_1[0] = Puffer_2[0];
        Mittel_Wert = (Sum_2 + Puffer_2[0])/10;
        return Mittel_Wert;
      }
   } 
}


/*
//gibt true zurück, wenn der linke Sensor eine weiße linie erkennt
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

//gibt true zurück, wenn der rechte Sensor eine weiße linie erkennt
bool is_sensor_right(){
  if (Sensor_Rechts() < Schwellwert_Rechts){
    Serial.println("right: true");
    return true;
  }  
  else {
    Serial.println("right: false");
    return false;
  }

}
*/


