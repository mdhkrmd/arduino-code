#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h>
SoftwareSerial mySerial(2, 3); //tx rx

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN,RST_PIN);
int relay = 4;
int buzzer = 7;
int salah = 0;

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{
  Serial.begin(9600);;
  while (!Serial);
  delay(100);
  SPI.begin();     
  mfrc522.PCD_Init(); 
  Serial.println("Program Dasar Akses Sidik Jari Arduino");
  pinMode(relay,OUTPUT);
  pinMode(buzzer, OUTPUT);

  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
  Serial.println("Waiting for valid finger...");
}

void loop()                     // run over and over again
{
  getFingerprintID();
  delay(50);            //don't ned to run this at full speed.
  bacaRfid();
  delay(50);            //don't ned to run this at full speed.
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      //Serial.println(".");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
   digitalWrite(relay, LOW);
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
    digitalWrite(relay, HIGH);
    delay(2000);
    digitalWrite(relay, LOW);
    salah = 0;
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
       Serial.println("Did not find a match");
       digitalWrite(buzzer,HIGH);
       delay(1000);
       digitalWrite(buzzer, LOW);
       salah += 1;
       Serial.println(salah);

      if(salah >= 3){
         int loopa = 1;
         Serial.println("RFID");
//        if ( ! mfrc522.PICC_IsNewCardPresent()) 
//        {
//          return;
//        }
//        // memilih salah satu card yang terdeteksi
//        if ( ! mfrc522.PICC_ReadCardSerial()) 
//        {
//          return;
//        }
        //tampilkan ID card di serial monitor
        Serial.print("UID tag :");
        String content= "";
        byte letter;
        for (byte i = 0; i < mfrc522.uid.size; i++) 
        {
           Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
           Serial.print(mfrc522.uid.uidByte[i], HEX);
           content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
           content.concat(String(mfrc522.uid.uidByte[i], HEX));
        }
        Serial.println();
        content.toUpperCase();
        if(content.substring(1) == "A5 04 11 AD"){
          digitalWrite(relay, HIGH);
          delay(2000);
          digitalWrite(relay, LOW);
        }else if(content.substring(1) == "A5 04 11 AD"){
          digitalWrite(relay, HIGH);
          delay(2000);
          digitalWrite(relay, LOW);
        }else{
          Serial.println("Tidak terdaftar");
        }
         salah = 0;
      }
  }
    return p;   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 
  delay(1000);

  return finger.fingerID;
}

uint8_t bacaRfid(){
  int loopa = 1;
  if(salah==3){
    
  }
        
}
