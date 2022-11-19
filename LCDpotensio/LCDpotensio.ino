#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // GANTI 0x3F Ke 0x27 kalau LCD ga muncul
int potensio = A0;
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(potensio, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorvalue = 0;
  sensorvalue = analogRead(potensio);
  Serial.println(sensorvalue);
  lcd.setCursor(0,0);
  lcd.print("Nilai: ");
  lcd.print(sensorvalue);
  lcd.setCursor(0,1);
  lcd.print("TEKKOM");

  delay(500);
  lcd.clear();
}
