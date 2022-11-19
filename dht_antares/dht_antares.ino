#include <AntaresESP32HTTP.h>
#include <WiFi.h>          
#include <DHT.h>
DHT dht (14, DHT11);

//API Key Antares
#define ACCESSKEY "2943a4cc68ecba07:99a731b711abe367"

//SSID dan Password WiFi
#define WIFISSID "BLOK B/6"
#define PASSWORD "mulyana2972"

//Nama Aplikasi Antares
#define projectName "learn_iot"
//Nama Device Antares
#define deviceName "dht11"

AntaresESP32HTTP antares(ACCESSKEY);

void setup() {
  Serial.begin(115200);
  antares.setDebug(true);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFISSID, PASSWORD);
  Serial.println("");
 
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(WIFISSID);
  dht.begin();
}

void loop() {
// Mengambil data sensor dari pin Analog
// dan menyimpan kedalam variabel datasensor
  float suhu = dht.readTemperature();

// Menambahkan datasensor dengan nama kelembaban
// kedalam buffer antares untuk dikirim
  antares.add("suhu", suhu);

// Mengirim data buffer ke server Antares
// dengan detail Aplikasi dan Device (HTTPS)
  antares.send(projectName, deviceName);
  delay(10000);
// Mengirim data buffer ke server Antares
// dengan detail Aplikasi dan Device (HTTP)
//antares.sendNonSecure(projectName, deviceName); 
}
