#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7
int motorSpeedA = 0;
int motorSpeedB = 0;
int potensio = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potensio, INPUT);
  lcd.init();
  lcd.backlight();
  pinMode(enA, OUTPUT);
  //pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   motorSpeedA = 255; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
    //motorSpeedB = 255; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
    int a = analogRead(potensio);
    int output = map(a, 0, 1023, 0, 255);
    Serial.println(output);
    analogWrite(enA, output);
     // Send PWM signal to motor A
    //analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
    
    // Set Motor A backward
    //digitalWrite(in1, motorSpeedA);
    //digitalWrite(in2, motorSpeedA);
    
    // Set Motor B backward
    //digitalWrite(in3, HIGH);
    //digitalWrite(in4, LOW);
    //delay(5000);
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    
}
