#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

SoftwareSerial mySerial(10,11);

void setup () {
Serial.begin (9600);
mySerial.begin (9600);
mp3_set_serial (mySerial);
delay(10);
mp3_set_volume (30);
}

void loop () {
  mp3_play (1);
  delay(20000);
  mp3_stop();
}
