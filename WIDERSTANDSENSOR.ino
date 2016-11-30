 
// Der Mittelwert von Sensor_Hinten - Kalibrierender Wert

#define Widerstand_Sensor_Links A0
#define Widerstand_Sensor_Rechts A1
#define Widerstand_Sensor_Hinten A2
#define LED_Links 11
#define LED_Rechts 12
#define LED_Hinten 4


int Sensor_Rechts ();
int Sensor_Links ();
int Sensor_Hinten ();


  
  
void setup() {
  Serial.begin(9600);
  pinMode(Widerstand_Sensor_Links, INPUT);
  pinMode(Widerstand_Sensor_Rechts, INPUT);
  pinMode(LED_Links, OUTPUT);
  pinMode(LED_Rechts, OUTPUT);
}


void loop(){
digitalWrite(LED_Links,HIGH);
digitalWrite(LED_Rechts,HIGH);
digitalWrite(LED_Hinten, HIGH);

int Mittel_Wert_Final;
int i=0;
int Threshold = 45;


int Rechts = Sensor_Rechts();
int Links = Sensor_Links();
int Hinten = Sensor_Hinten();

Serial.print("Links: ");
Serial.print(Links);
Serial.print("        Rechts: ");
Serial.print(Rechts);
Serial.print("        Hinten: ");
Serial.println (Hinten);

if ((Links + Threshold) > Rechts && (Links - Threshold) < Rechts){
  if ((Links + Threshold) > Hinten && (Links - Threshold) < Hinten){
    Serial.println("Schwarz alle");
  }
  else if ((Links + Threshold) < Hinten ){
    Serial.println("Links und Rechts auf weiss");
  }
  else if ((Links - Threshold) > Hinten){
    Serial.println("Nur hinten auf weiss");
  }
}
else if ((Links + Threshold) < Rechts){
  Serial.println("Nur Links auf weiss");
}
else if ((Links - Threshold) > Rechts){
  Serial.println("Nur Rechts auf weiss");
}

//Serial.print("Links: ");
//Serial.print(Links);
//Serial.print("        Rechts: ");
//Serial.print(Rechts);
//Serial.print("        Hinten: ");
//Serial.println (Hinten);
delay(100);
}


int Sensor_Rechts()
{ 


int Puffer_1[10]={0,0,0,0,0,0,0,0,0,0};
int Puffer_2[10]={0,0,0,0,0,0,0,0,0,0};
int i,j = 0;
int Mittel_Wert = 0;
int Sum_1 = 0;
int Sum_2 = 0;
int Schleife = 0;

for (j=0;j<=500;j++){
  
if (Schleife == 0){
    for (i=0;i<=9;i++)
                      {
      
               Puffer_1[i]=analogRead(Widerstand_Sensor_Rechts);
               Sum_1 += Puffer_1[i];                 
         
                      }
                      Schleife +=1;
                      Mittel_Wert = Sum_1/10;
                      return Mittel_Wert - 5;

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
                     return Mittel_Wert - 5;
                     
                      }
                  
              } 
}
  
                      
  





  
//  int Puffer=0;
//  int Counter=0;
//  int Mittel_Wert=0;
// for(Counter=0;Counter <= 9;Counter++) 
//  
//  {
//  Puffer += analogRead(Widerstand_Sensor_Rechts);
//  
//  }
//
//  Mittel_Wert = Puffer/Counter;
//  return Mittel_Wert;  
 




int Sensor_Links ()
{
 int Puffer_1[10]={0,0,0,0,0,0,0,0,0,0};
int Puffer_2[10]={0,0,0,0,0,0,0,0,0,0};
int i,j = 0;
int Mittel_Wert = 0;
int Sum_1 = 0;
int Sum_2 = 0;
int Schleife = 0;

for (j=0;j<=500;j++){
  
if (Schleife == 0){
    for (i=0;i<=9;i++)
                      {
      
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
                        
                        Puffer_2[0] = analogRead(Widerstand_Sensor_Links);
                        Puffer_1[0] = Puffer_2[0];
                        Mittel_Wert = (Sum_2 + Puffer_2[0])/10;
                     return Mittel_Wert;
                     
                      }
                  
              
}
}
int Sensor_Hinten ()
{
  
  
   int Puffer_1[10]={0,0,0,0,0,0,0,0,0,0};
int Puffer_2[10]={0,0,0,0,0,0,0,0,0,0};
int i,j = 0;
int Mittel_Wert = 0;
int Sum_1 = 0;
int Sum_2 = 0;
int Schleife = 0;

for (j=0;j<=500;j++){
  
if (Schleife == 0){
    for (i=0;i<=9;i++)
                      {
      
               Puffer_1[i]=analogRead(Widerstand_Sensor_Hinten);
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
                        
                        Puffer_2[0] = analogRead(Widerstand_Sensor_Hinten);
                        Puffer_1[0] = Puffer_2[0];
                        Mittel_Wert = (Sum_2 + Puffer_2[0])/10;
                     return Mittel_Wert;
                     
                      }
                  
              
}
  }
//void loop() {
////  
// digitalWrite(LED_Links,HIGH);
// 
// //digitalWrite(LED_Rechts,HIGH);
//  int Sensor_Links = analogRead(Widerstand_Sensor_Links);
//  //int Sensor_Rechts = analogRead(Widerstand_Sensor_Rechts);
//  Puffer += Sensor_Links ;
//  Counter += 1;
//
//  if (Counter == 13)
//  {
//    Mittel_Wert = Puffer / Counter;
//    Serial.println(Mittel_Wert);
//    delay(100);
//    Puffer = 0;
//    Counter = 0;
//    }
//
//  
//  
// // Serial.println(Sensor_Rechts);
// // Serial.println(Sensor_Links); 
//  }

//

