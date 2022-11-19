#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

//sensor turbidity
static float kekeruhan;
static float teg;

//sensor ph
const int ph_pin = A1;
float Po = 0;
float PH_Step;
int nilai_analog_ph;
double teganganph;
float PH4 = 1.73;
float PH7 = 1.22;

//int relaypompa1 = 2;
int relaypompa1 = 2;
int relaypompa2 = 3;
int relayUV = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relaypompa1,OUTPUT);
  pinMode(relaypompa2,OUTPUT);
  pinMode(relayUV,OUTPUT);
  pinMode(ph_pin,INPUT);
  lcd.init();
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A0);
  teg = val*(5.0/1024);
  kekeruhan = 100.00-(teg/4.16)*100.00;
  Serial.print("kekeruhan = ");
  Serial.println(kekeruhan);
  delay(1);

  nilai_analog_ph = analogRead(ph_pin);  
  teganganph = 5/1024.0*nilai_analog_ph;
  PH_Step = (PH4-PH7)/3;
  Po = 7.0 + ((PH7-teganganph)/PH_Step);
  delay(0);
  
  if(kekeruhan >16){
    digitalWrite(relayUV,HIGH);
    digitalWrite(relaypompa2,HIGH);
    digitalWrite(relaypompa1,LOW);
    delay(1);
  }else if (kekeruhan <16){
    digitalWrite(relayUV,LOW);
    digitalWrite(relaypompa2,LOW);
    digitalWrite(relaypompa1,HIGH);
    Serial.print("Nilai PH Cairan = ");
    Serial.println(Po,2);
    lcd.setCursor(0,0);
    lcd.print("ph = ");
    lcd.setCursor(4,0);
    lcd.print(Po,2);
    
    delay(1);
  }
}
