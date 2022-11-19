#include "DHT.h"  //Memasukan Library DHT ke Program 
#define DHTPIN 2  //menggunakan pin 2 untuk pemasangan sensornya
#define DHTTYPE DHT11 //memilih tipe DHT11, bisa diubah menjadi DHT22, DHT21

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // GANTI 0x3F Ke 0x27 kalau LCD ga muncul

DHT dht(DHTPIN, DHTTYPE);  //setting pin yang dipilih dan tipe DHT
int led = 13;

void setup() {
  Serial.begin(9600);  //komunikasi Serial dengan komputer
  lcd.init();
  lcd.backlight();
  dht.begin(); //Komunikasi DHT dengan Arduino
  pinMode(led, OUTPUT);
}

void loop() {
  float kelembaban = dht.readHumidity(); //menyimpan nilai Humidity pada variabel kelembaban
  float suhu = dht.readTemperature(); //menyimpan nilai Temperature pada variabel suhu

  Serial.print(" Kelembaban: "); //menampilkan tulisan Kelembaban di Serial Monitor
  Serial.print(kelembaban); //menampilkan nilai kelembaban
  Serial.print(" Suhu: "); //menampilkan tulisan suhu
  Serial.println(suhu); //menampilkan nilai suhu

  lcd.setCursor(0,0);
  lcd.print(kelembaban);
  lcd.setCursor(0,1);
  lcd.print(suhu);
  delay(500);
  lcd.clear();
}
