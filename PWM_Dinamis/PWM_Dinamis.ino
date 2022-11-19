#include <stdio.h>
#include <stdlib.h>
#include <PWM.h> //https://github.com/terryjmyers/PWM

const int pwmPin0 = 5;
const int pwmPin1 = 6;
const int pwmPin2 = 9;
const int pwmPin3 = 10;
const int pwmPin4 = 3;
const int pwmPin5 = 11;
int ledPin = 13;

int32_t pwmFrequency = 10000;  //pwmFrequency (in Hz) for pins 9, 10, 3, 11

void setup() {
  InitTimersSafe(); //initialize all timers except for 0, to save time keeping functions
  Serial.begin(115200);
  delay(100);

  Serial.print("Set pin\t");
  Serial.print(pwmPin0);
  Serial.println(" as standart PWM Output\t; Timer 0");
  pinMode(pwmPin0, OUTPUT);
  Serial.print("Set pin\t");
  Serial.print(pwmPin1);
  Serial.println(" as standart PWM Output\t; Timer 0");
  pinMode(pwmPin1, OUTPUT);
  //No pinMode for PWM.h-Pins 9, 10, 3, 11

  Serial.print("Set pin\t");
  Serial.print(pwmPin2);
  Serial.print(" to PWM frequency\t");
  Serial.println(pwmFrequency);
  SetPinFrequencySafe(pwmPin2, pwmFrequency);
  Serial.print("pinResolution [Bits] = ");
  Serial.println(GetPinResolution(pwmPin2));

  Serial.print("Set pin\t");
  Serial.print(pwmPin3);
  Serial.print(" to PWM frequency\t");
  Serial.println(pwmFrequency);
  SetPinFrequencySafe(pwmPin3, pwmFrequency);
  Serial.print("pinResolution [Bits] = ");
  Serial.println(GetPinResolution(pwmPin3));

  Serial.print("Set pin\t");
  Serial.print(pwmPin4);
  Serial.print(" to PWM frequency\t");
  Serial.println(pwmFrequency);
  SetPinFrequencySafe(pwmPin4, pwmFrequency);
  Serial.print("pinResolution [Bits] = ");
  Serial.println(GetPinResolution(pwmPin4));

  Serial.print("Set pin\t");
  Serial.print(pwmPin5);
  Serial.print(" to PWM frequency\t");
  Serial.println(pwmFrequency);
  SetPinFrequencySafe(pwmPin5, pwmFrequency);
  Serial.print("pinResolution [Bits] = ");
  Serial.println(GetPinResolution(pwmPin5));

  Serial.println();
  Serial.print("Timer0, 1, 2 getFrequency(): ");
  Serial.print(Timer0_GetFrequency());
  Serial.print(", ");
  Serial.print(Timer1_GetFrequency());
  Serial.print(", ");
  Serial.println(Timer2_GetFrequency());
  Serial.print("Timer0, 1, 2 getPrescaler(): ");
  Serial.print(Timer0_GetPrescaler());
  Serial.print(", ");
  Serial.print(Timer1_GetPrescaler());
  Serial.print(", ");
  Serial.println(Timer2_GetPrescaler());
  Serial.print("Timer0, 1, 2 getResolution(): ");
  Serial.print(Timer0_GetResolution());
  Serial.print(", ");
  Serial.print(Timer1_GetResolution());
  Serial.print(", ");
  Serial.println(Timer2_GetResolution());
  Serial.print("Get pinResolution pwmPin 0...5: 5, 6, 9, 10, 3, 11: ");
  Serial.print(GetPinResolution(pwmPin0));
  Serial.print(", ");
  Serial.print(GetPinResolution(pwmPin1));
  Serial.print(", ");
  Serial.print(GetPinResolution(pwmPin2));
  Serial.print(", ");
  Serial.print(GetPinResolution(pwmPin3));
  Serial.print(", ");
  Serial.print(GetPinResolution(pwmPin4));
  Serial.print(", ");
  Serial.println(GetPinResolution(pwmPin5));
  Serial.print("Timer1, 2 GetTop()");
  Serial.print(Timer1_GetTop());
  Serial.print(", ");
  Serial.println(Timer2_GetTop());

  Serial.print("\nStart fading all PWM-outputs from 0...31, 119...135, 239...255");
}
void loop() {
  for (int i = 0; i < 80; i+=10) {
    Serial.println(i);
    digitalWrite(ledPin, HIGH);
    analogWrite(pwmPin0, 0);
    analogWrite(pwmPin1, 0);
    pwmWrite(pwmPin2, 0);
    pwmWrite(pwmPin3, 0);
    pwmWrite(pwmPin4, 0);
    pwmWrite(pwmPin5, 0);
    delay(50);
    digitalWrite(ledPin, LOW);
    analogWrite(pwmPin0, i);
    analogWrite(pwmPin1, i);
    pwmWrite(pwmPin2, i);
    pwmWrite(pwmPin3, i);
    pwmWrite(pwmPin4, i);
    pwmWrite(pwmPin5, i);
    delay(500);
  }

  analogWrite(pwmPin0, 0);
  analogWrite(pwmPin1, 0);
  pwmWrite(pwmPin2, 0);
  pwmWrite(pwmPin3, 0);
  pwmWrite(pwmPin4, 0);
  pwmWrite(pwmPin5, 0);
  delay(1000);

  for (int i = 80; i < 160; i+=10) {
    Serial.println(i);
    digitalWrite(ledPin, HIGH);
    analogWrite(pwmPin0, 0);
    analogWrite(pwmPin1, 0);
    pwmWrite(pwmPin2, 0);
    pwmWrite(pwmPin3, 0);
    pwmWrite(pwmPin4, 0);
    pwmWrite(pwmPin5, 0);
    delay(50);
    digitalWrite(ledPin, LOW);
    analogWrite(pwmPin0, i);
    analogWrite(pwmPin1, i);
    pwmWrite(pwmPin2, i);
    pwmWrite(pwmPin3, i);
    pwmWrite(pwmPin4, i);
    pwmWrite(pwmPin5, i);
    delay(500);
  }

  analogWrite(pwmPin0, 0);
  analogWrite(pwmPin1, 0);
  pwmWrite(pwmPin2, 0);
  pwmWrite(pwmPin3, 0);
  pwmWrite(pwmPin4, 0);
  pwmWrite(pwmPin5, 0);
  delay(1000);

  for (int i = 160; i < 255; i += 10) {
    Serial.println(i);
    digitalWrite(ledPin, HIGH);
    analogWrite(pwmPin0, 0);
    analogWrite(pwmPin1, 0);
    pwmWrite(pwmPin2, 0);
    pwmWrite(pwmPin3, 0);
    pwmWrite(pwmPin4, 0);
    pwmWrite(pwmPin5, 0);
    delay(50);
    digitalWrite(ledPin, LOW);
    analogWrite(pwmPin0, i);
    analogWrite(pwmPin1, i);
    pwmWrite(pwmPin2, i);
    pwmWrite(pwmPin3, i);
    pwmWrite(pwmPin4, i);
    pwmWrite(pwmPin5, i);
    delay(500);
  }

  analogWrite(pwmPin0, 0);
  analogWrite(pwmPin1, 0);
  pwmWrite(pwmPin2, 0);
  pwmWrite(pwmPin3, 0);
  pwmWrite(pwmPin4, 0);
  pwmWrite(pwmPin5, 0);
  delay(1000);
}
