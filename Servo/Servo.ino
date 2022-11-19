#include <Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(2);  
}

void loop() {
  // put your main code here, to run repeatedly:
 for(int angle = 0; angle <= 180; angle++){
  servo.write(angle);
  delay(10);
 }
  for(int angle = 180; angle >= 0; angle--){
  servo.write(angle);
  delay(10);
}
}
