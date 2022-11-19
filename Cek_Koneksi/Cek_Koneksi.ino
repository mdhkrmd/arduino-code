#include <ESP8266WiFi.h>
const char *ssid = "Test123"; //ganti nama hotspot
const char *pass = "";//ganti password
WiFiClient client;
void setup()
{
Serial.begin(9600);
delay(10);
Serial.print(" Connect to : ");
Serial.println(ssid);
WiFi.begin(ssid, pass);
while (WiFi.status() != WL_CONNECTED)
{
  delay(500);
  Serial.print("….");
}
Serial.print("\n");
Serial.print("IP address : ");
Serial.print(WiFi.localIP());
Serial.print("\n");
Serial.print("Connect to : ");
Serial.println(ssid);
}

void loop() { 
  
}
