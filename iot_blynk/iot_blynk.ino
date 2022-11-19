#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>

const char auth[] = "0pzVcCCIcS5LkSRUpHfjglOup1ZSk8DD";
const char ssid[] = "verarukiah"; //ganti nama hotspot
const char pass[] = "";//ganti password

int led = 5;

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
 
 pinMode(led, OUTPUT);
}

void loop(){
   Blynk.run();
   
}
