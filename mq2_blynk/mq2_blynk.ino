#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h> 

char auth[] = "OnmFYz6ZiTjpALAwOdbZj1D79Xv10TJW"; 
char ssid[] = "BLOK B/6"; //Enter WIFI Name
char pass[] = "mulyana2972"; //Enter WIFI Password
 
int mq2 = A0; 
 
void setup() 
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
 
void loop() 
{
  int data = analogRead(mq2); 
  Blynk.virtualWrite(V2, data);
  if (data > 700 )
  {
    Blynk.notify("Smoke Detected!"); 
  }
}
