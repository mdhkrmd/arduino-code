#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

DHT dht(2, DHT11);
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() 
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  Serial.begin(9600);
  dht.begin();
}

void loop() 
{
  float lmbb = dht.readHumidity();
  float suhu = dht.readTemperature();
  
  Serial.print("Kelembaban = ");
  Serial.print(lmbb);
  Serial.print(" Suhu = ");
  Serial.println(suhu);
  
  display.setTextSize(0.5);
  display.setTextColor(WHITE);
  
  display.setCursor(0,0);
  display.println("Kelembaban");
  display.setCursor(0,10);
  display.println(lmbb);

  display.setCursor(0,20);
  display.print("Suhu");
  display.setCursor(40,10);
  display.println(suhu);
  
  display.display();
}
