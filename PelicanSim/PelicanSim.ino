#include <TM1637Display.h>
#include <SoftwareSerial.h>    //memasukan library Software Serial
#include <DFPlayer_Mini_Mp3.h> //memasukan library DFPlayermini
#define CLK 2
#define DIO 3
SoftwareSerial mySerial(10,11); //pin RX dan TX

int led_hijau = 6;
int led_merah = 5;
const int button = 7;

TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(9600);
  display.setBrightness(0x0f);  
  pinMode(button, INPUT);
  pinMode(led_hijau, OUTPUT);
  pinMode(led_merah, OUTPUT);
  mySerial.begin (9600);
  mp3_set_serial (mySerial);
  delay(10);
  mp3_set_volume (30);
}

void loop() {
  int but = digitalRead(button); 
  Serial.println(but);
  if (but == HIGH) {
    mp3_play (1);
    digitalWrite(led_merah, LOW);
    delay(5000);
    digitalWrite(led_hijau, HIGH);
    for(int i = 20; i >= 0; i--){
    display.showNumberDec(i);
    delay(1000);  
  }
  mp3_stop();
  }
  else{
    digitalWrite(led_merah, HIGH);
    digitalWrite(led_hijau, LOW);
    mp3_stop();
  }
}
