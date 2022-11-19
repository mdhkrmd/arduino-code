#include <Servo.h>

#define echoPin 8
#define initPin 9

Servo servo;
int angle = 10;
unsigned long pulseTime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.write(angle);
  servo.attach(2);
  pinMode(initPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(initPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(initPin, LOW);

  int jarak;
  pulseTime = pulseIn(echoPin, HIGH);
  jarak = pulseTime / 58;

  Serial.print("Jarak = ");
  Serial.print(jarak, DEC);
  Serial.println(" cm");

  if(jarak <= 15){
    servo.write(180);
    delay(500);
    servo.write(0);
    delay(500);
    servo.write(180);
    delay(3000);
  }
  else{
    servo.write(0);
  }
}
