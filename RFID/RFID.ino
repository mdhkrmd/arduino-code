#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
int relay = 7;
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
void setup() 
{
  Serial.begin(9600);
  pinMode(relay, OUTPUT); 
  SPI.begin();     
  mfrc522.PCD_Init(); 
}
void loop() 
{
  // membaca ID card
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // memilih salah satu card yang terdeteksi
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
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
  if(content.substring(1) == "04 51 31 C2 13 5E 80"){
    digitalWrite(relay, HIGH);
    delay(2000);
    digitalWrite(relay, LOW);
  }else if(content.substring(1) == "57 BF FF A7"){
    digitalWrite(relay, HIGH);
    delay(2000);
    digitalWrite(relay, LOW);
  }else{
    Serial.println("Tidak terdaftar");
  }
}
