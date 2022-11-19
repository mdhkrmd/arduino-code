#include <SPI.h>                      //Library komunikasi SPI
#include <RFID.h>                     //Library RFID
#define SS_PIN 10                      //Deklarasi pin ss pada D5
#define RST_PIN 6                     //Deklarasi pin rst pada D6
RFID rfid(SS_PIN,RST_PIN);            //Kenalkan pin ss dan rst pada RFID

int Data_RFID[4] = {34,188,94,52};
bool akses = true;

#define LED 2
bool kondisi_LED = false;

void setup() {
  Serial.begin(9600);
  SPI.begin();                        //Mulai komunikasi SPI
  rfid.init();                        //Mulai RFID
  pinMode(LED, OUTPUT);
}

void loop() {
  if(rfid.isCard() && rfid.readCardSerial()){
    for( int i=0 ; i<=3 ; i++){               
      if(rfid.serNum[i] != Data_RFID[i]){
        goto tolak_akses;
      }
    }
    rfid.halt();
    Serial.println("<< Akses Diterima >>");
    delay(1000);

    if(kondisi_LED == false){
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
      kondisi_LED = true;
    }
    else{
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
      kondisi_LED = false;
    }
  }

  if(akses == false){
    tolak_akses:
    Serial.println("Akses Ditolak!");
    delay(2000);
  }
}
