#include <LiquidCrystal_I2C.h>
#define echoPin 8
#define initPin 9
unsigned long pulseTime = 0;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
   lcd.init();
   Serial.begin(9600);
  // Print a message to the LCD.
  lcd.backlight(); 
 lcd.begin(16, 2);
 pinMode(initPin, OUTPUT);
 pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(initPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(initPin, LOW);

  pulseTime = pulseIn(echoPin, HIGH);

  Serial.print("Jarak = ");
  Serial.print(pulseTime / 58, DEC);
  Serial.println(" cm");

  lcd.setCursor(0, 0);
  lcd.print("Jarak = ");
  lcd.print(pulseTime / 58, DEC);
  lcd.print(" cm");
  lcd.setCursor(0,1);
  lcd.print("Test Jarak");

  delay(100);
  lcd.clear();
}
