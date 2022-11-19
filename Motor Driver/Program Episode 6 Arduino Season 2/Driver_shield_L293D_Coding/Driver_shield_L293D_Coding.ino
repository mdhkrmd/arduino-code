//Subscribe AJTekno
//Driver shield L293D (4WD)
#include <AFMotor.h>

char val;
AF_DCMotor motor1(1, MOTOR12_64KHZ); //Jadikan motor 1, 64KHZ
AF_DCMotor motor2(2, MOTOR12_64KHZ); //Jadikan motor 2, 64KHZ
AF_DCMotor motor3(3, MOTOR12_64KHZ); //Jadikan motor 3, 64KHZ
AF_DCMotor motor4(4, MOTOR12_64KHZ); //Jadikan motor 4, 64KHZ

void setup() {
Serial.begin (9600);
motor1.setSpeed(240); //Set kecepatan motor 1 240 (range 0-255)
motor2.setSpeed(240); //Set kecepatan motor 2 240 (range 0-255)
motor3.setSpeed(240); //Set kecepatan motor 3 240 (range 0-255)
motor4.setSpeed(240); //Set kecepatan motor 4 240 (range 0-255)
}

void loop() {
  //Maju
  motor1.run(FORWARD); //Motor kanan maju
  motor2.run(FORWARD); //Motor kanan maju
  motor3.run(FORWARD); //Motor kiri maju
  motor4.run(FORWARD); //Motor kiri maju
  delay (5000);
  
  //Berhenti
  motor1.run(RELEASE); //Motor kanan berhenti
  motor2.run(RELEASE); //Motor kanan berhenti
  motor3.run(RELEASE); //Motor kiri berhenti
  motor4.run(RELEASE); //Motor kiri berhenti
  delay (2000);

  //Mundur
  motor1.run(BACKWARD); //Motor kanan mundur
  motor2.run(BACKWARD); //Motor kanan mundur
  motor3.run(BACKWARD); //Motor kiri mundur
  motor4.run(BACKWARD); //Motor kiri mundur
  delay (5000);
}
