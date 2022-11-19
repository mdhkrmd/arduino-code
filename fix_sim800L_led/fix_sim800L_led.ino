#include<SoftwareSerial.h>
SoftwareSerial sim(2,3);

int led = 13;
String pesan;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  sim.begin(9600);
  delay(100);
  sim.println("AT");
  sim.println("AT+CMGF=1");
  sim.println("AT+CNMI=1,2,0,0,0");
}

void loop() {
  if(Serial.available()){
    sim.write(Serial.read());
  }
  if(sim.available()>0){
    pesan = sim.readStringUntil('\n');
    Serial.println(pesan);
    if(pesan=="On\r"){
      digitalWrite(led,HIGH);
      eksekusi(1);
      Serial.println("LED nyala");
    }
    if(pesan=="Off\r"){
      digitalWrite(led,LOW);
      eksekusi(0);
      Serial.println("LED mati");
    }
  }

}

void eksekusi(bool tipe){
  sim.println("AT+CMGF=1");
  delay(1000);
  sim.println("AT+CMGS=\"085155060773\"\r");
  delay(1000);
  if(tipe==1){
    sim.println("Halo Halo Muadz");
  }else{
    sim.println("Muadz Halo Halo");
  }
  delay(100);
  sim.println((char)26);
  delay(1000);
}
