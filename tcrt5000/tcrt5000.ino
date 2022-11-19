//int sensor = 4;
int sensorAnalog = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorAnalog, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  int nilai = digitalRead(sensor);
  int nilaiAnalog = analogRead(sensorAnalog);
//  Serial.println(nilai);
  Serial.println(nilaiAnalog);
}
