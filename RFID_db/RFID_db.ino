#include <HTTPClient.h>
#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>

//Konfigurasi WiFi
const char *ssid = "BLOK B/6";
const char *password = "mulyana2972";

//IP Address Server yang terpasang XAMPP
const char *host = "192.168.100.23";

int SDA_PIN = 21;
int rst = rst;
int relay = 7;
MFRC522 mfrc522(SDA_PIN, rst);   // Create MFRC522 instance.
 
void setup() 
{
  Serial.begin(115200);
  pinMode(relay, OUTPUT);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //Jika koneksi berhasil, maka akan muncul address di serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); 
  
  SPI.begin();     
  mfrc522.PCD_Init(); 
}

int value = 0;

void loop()
{
  if (WiFi.status() == WL_CONNECTED) {
    
    if ( ! mfrc522.PICC_IsNewCardPresent())
    {
      return;
    }
    if ( ! mfrc522.PICC_ReadCardSerial())
    {
      return;
    }
    Serial.println();
    Serial.print("UID tag :");
    String content = "";
    byte letter;
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : ""));
      content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    content.toUpperCase();
    Serial.println();
      HTTPClient http;
      http.begin("http://192.168.100.23/rfid/insert.php?data=" + String(content));
      int httpCode = http.GET();
      if (httpCode > 0) {
        String payload = http.getString();
        Serial.print("RESPON = ");
        Serial.println(payload);
      }
       http.end();  
  }
  delay(100);
}

/*
 *  if(content.substring(1) == "04 51 31 C2 13 5E 80"){
    digitalWrite(relay, HIGH);
    delay(5000);
    digitalWrite(relay, LOW);
  }else if(content.substring(1) == "57 BF FF A7"){
    digitalWrite(relay, HIGH);
    delay(5000);
    digitalWrite(relay, LOW);
  }else{
    Serial.println("Tidak terdaftar");
  }
*/
