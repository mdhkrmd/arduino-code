#include "gprs.h";
#include <SoftwareSerial.h>

GPRS gprs(9600);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Test serial debug.....");
  gprs.preInit();
  while (0 !=  gprs.sendATTest()){
    Serial.println("Error");
  }
  Serial.println("SIM OK");
}

void loop() {
  // put your main code here, to run repeatedly:
  gprs.serialDebug();
}
