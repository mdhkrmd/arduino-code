#include <TM1637Display.h>

#define CLK 2
#define DIO 3
#define echoPin 8
#define initPin 9
#define buzz 5
int count = 0;

TM1637Display display(CLK, DIO);
unsigned long pulseTime = 0;
uint8_t blank[] = { 0x0, 0x0, 0x0, 0x0 };// data to clear the screen

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 pinMode(initPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(buzz, OUTPUT);

 display.setSegments(blank); // clear the screen from previous values 
 display.showNumberDec(0);// display zero at the belonging

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
  display.setBrightness(0x0f);
  
  if(nilai <= 30){
    
    count++;// increment the count   
      display.setSegments(blank); // clear the screen from previous values   
      display.showNumberDec(count);// display the count 
    digitalWrite(buzz, LOW);
    delay(2000);  
  }
  
}
