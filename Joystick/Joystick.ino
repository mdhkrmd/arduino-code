#include <Servo.h>
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(50);
  int joystickXVal = analogRead(A3) ; //read joystick input on pin A1.  Will return a value between 0 and 1023.
  int servoVal = map(joystickXVal, 0, 1023, 0, 180) ;  // changes the value to a raneg of 0 to 180.   See "map" function for further details.
  Serial.print(joystickXVal); //print the value fram A1
  Serial.println(" = input from joystick"); //print "=input from joystick" next to the value
  Serial.print(servoVal); //print a from A1 calculated, scaled value
  Serial.println(" = output to servo"); //print "=output to servo" next to the value
  Serial.println() ;
  servo.write(servoVal); //write the calculated value to the servo
  delay(200);
}
