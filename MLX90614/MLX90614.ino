#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

#define echoPin 8
#define initPin 9
#define buzz 13
int count = 0;
unsigned long pulseTime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 pinMode(initPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(buzz, OUTPUT);
 mlx.begin();  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(initPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(initPin, LOW);

  pulseTime = pulseIn(echoPin, HIGH);
  int nilai = pulseTime / 58;

  Serial.print("Jarak = ");
  Serial.print(nilai, DEC);
  Serial.println(" cm");
  delay(100);
 
  if(nilai <= 5){
    digitalWrite(buzz, HIGH);
    delay(250);
    Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
    Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
    digitalWrite(buzz, LOW);
    delay(2000);  
  }
  
}
