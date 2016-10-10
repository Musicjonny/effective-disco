#define MOTOR_L 2
#define MOTOR_R 3
#define ENABLE 4

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(MOTOR_L, OUTPUT);
  pinMode(MOTOR_R, OUTPUT);
  
  //digitalWrite(MOTOR_R, LOW);
  //digitalWrite(MOTOR_L, LOW);
  // put your setup code here, to run once:

}

int i = 0;
void loop() {
  
  digitalWrite(ENABLE, LOW);
  delay(1000);
  
  digitalWrite(MOTOR_L, LOW);
  digitalWrite(MOTOR_R, HIGH);
  digitalWrite(ENABLE, HIGH);
  delay(1000);
  
  digitalWrite(ENABLE, LOW);
  delay(1000);
  
 // for (i = 0; i< 255; i++) {
  
  digitalWrite(MOTOR_R, LOW);
  digitalWrite(MOTOR_L, HIGH);
  digitalWrite(ENABLE, HIGH);
 //analogWrite(ENABLE, i);
  delay(100);
 // }
  
  // put your main code here, to run repeatedly:

}
