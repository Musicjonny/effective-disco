#define MOTOR1
#define MOTOR2
#define DISTANCE_L
#define DISTANCE_R
#define DISTANCE A0
#

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

int dist = 0;

void loop() {
  // put your main code here, to run repeatedly:
  dist = analogRead(DISTANCE);
  Serial.println(dist);
  delay(200);
}
