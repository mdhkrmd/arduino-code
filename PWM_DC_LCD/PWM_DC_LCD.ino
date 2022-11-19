#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#include "timer.h"

#define enA 9
#define in1 4
#define in2 5
int motorSpeedA = 0;

Timer timer;
char input;

const int LM393 = 2;
int counter = 0;
void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(LM393), count, RISING);
  Serial.begin(115200);
  timer.setInterval(1000);
  timer.setCallback(RPM);
  timer.start();
}

void count() {
  counter++;
}

void RPM() {
  Serial.println(counter * 60);
  if(Serial.available()){
        input = Serial.read();
        Serial.print("You typed: " );
        Serial.println(input);
        if(input == '1'){
          motorSpeedA = 100;
          analogWrite(enA, motorSpeedA);
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
        }
        else if(input == '2'){
          motorSpeedA = 125;
          analogWrite(enA, motorSpeedA);
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
        }
        else if(input == '3'){
          motorSpeedA = 150;
          analogWrite(enA, motorSpeedA);
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
        }
        else if(input == '4'){
          motorSpeedA = 175;
          analogWrite(enA, motorSpeedA);
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
        }
        else if(input == '5'){
          motorSpeedA = 200;
          analogWrite(enA, motorSpeedA);
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
        }
        else if(input == '6'){
          motorSpeedA = 225;
          analogWrite(enA, motorSpeedA);
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
        }
        else if(input == '7'){
          motorSpeedA = 255;
          analogWrite(enA, motorSpeedA);
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
        }
        else if(input == '0'){
          motorSpeedA = 0;
          analogWrite(enA, motorSpeedA);
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
        }
    }
  lcd.setCursor(0,0);
  lcd.print("PWM: ");
  lcd.print(counter); 
  counter = 0;
}

void loop() {
  timer.update();
}
