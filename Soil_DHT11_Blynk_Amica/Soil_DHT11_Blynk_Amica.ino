#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
DHT dht(4, DHT11);

char auth[] = "vQtegKCvS4X2nMYIudsdtzBB8ey5GE7s"; 
char ssid[] = "BLOK B/6"; //Enter WIFI Name
char pass[] = "mulyana2972"; //Enter WIFI Password
 
int soil = A0;
int pump = 5; 
 
void setup() 
{
  Serial.begin(9600);
  pinMode(pump, OUTPUT);
  dht.begin();
  Blynk.begin(auth, ssid, pass);
}
 
void loop() 
{
  float suhu = dht.readTemperature();
  float kelembaban = dht.readHumidity();
  int soil = analogRead(soil);
  
  Blynk.virtualWrite(V3, suhu);
  Blynk.virtualWrite(V4, kelembaban); 
  Blynk.virtualWrite(V2, soil);
  if (soil > 950 )
  {
    Blynk.notify("Pompa On, Air mengalir");
    digitalWrite(pump, HIGH); 
  }else{
    digitalWrite(pump, LOW);
  }
  Serial.print(suhu);
  Serial.print("|||||");
  Serial.print(kelembaban);
  Serial.print("|||||");
  Serial.println(soil);
}
