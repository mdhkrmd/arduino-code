#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // GANTI 0x3F Ke 0x27 kalau LCD ga muncul
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Praktikum Mekatronika");
  lcd.setCursor(0,1);
  lcd.print("2021");
}

void loop() {
  // put your main code here, to run repeatedly:

}
