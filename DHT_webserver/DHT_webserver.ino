#include <DHT.h>
#include <WiFi.h>

//Konfigurasi WiFi
const char *ssid = "BLOK B/6";
const char *password = "mulyana2972";

//IP Address Server yang terpasang XAMPP
const char *host = "192.168.100.23";

DHT dht(14, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
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
  dht.begin();
}

int value = 0;

void loop() {
  // put your main code here, to run repeatedly:
   // Proses Pengiriman -----------------------------------------------------------
  delay(5000);
  ++value;

  float suhu = dht.readTemperature();
  Serial.print(" Suhu = ");
  Serial.println(suhu);

  Serial.print("connecting to ");
  Serial.println(host);

  // Mengirimkan ke alamat host dengan port 80 -----------------------------------
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // Isi Konten yang dikirim adalah alamat ip si esp -----------------------------
  String url = "/dht_11/insert.php?data=";
  url += suhu;

  Serial.print("Requesting URL: ");
  Serial.println(url);

  // Mengirimkan Request ke Server -----------------------------------------------
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 1000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
}
