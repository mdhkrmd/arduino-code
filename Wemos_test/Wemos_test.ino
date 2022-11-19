#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

const char *auth = "xOcWBqpsVl8sgNYxYwQvKMJzTG4Rg49o";
const char *ssid = "Test123";
const char *pass = "mdhkrmd1";

int tanah = 27;
int pompa = 14;

void setup() {   
  Serial.begin(115200);
  pinMode(tanah, INPUT);
  //pinMode(pompa, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  Blynk.run();
  int nilai = digitalRead(tanah);
  Serial.println(nilai);
  if(nilai == 1){
    Blynk.notify("Pump Water"); 
  }
}
