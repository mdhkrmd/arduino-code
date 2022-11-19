  #include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilai = analogRead(A0);
  Serial.print("Ketinggian Air = ");
  Serial.println(nilai);
    
  if(nilai >= 670){
    lcd.clear();
    digitalWrite(2, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Tinggi Air = ");
    lcd.setCursor(13,0);
    lcd.print(nilai);
    lcd.setCursor(0,1);
    lcd.print("BAHAYA");
  }
  else{
    lcd.clear();
    digitalWrite(2, LOW);
    lcd.setCursor(0,0);
    lcd.print("Tinggi Air =");
    lcd.setCursor(13,0);
    lcd.print(nilai);
    lcd.setCursor(0,1);
    lcd.print("AMAN"); 
  }
  delay(1000);
}
