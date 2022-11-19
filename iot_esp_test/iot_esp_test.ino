#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

char auth[] = "k2PdKitSbs_GAxA_fKOuPD1V94SrWF3Q";
char ssid[] = "BLOK B/6"; //ganti nama hotspot
char pass[] = "mulyana2972";//ganti password

int led = 5;

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
 
 pinMode(led, OUTPUT);
}

void loop(){
   Blynk.run();
}
