const int gasPin = A0;
const int buzz = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzz, OUTPUT);
  pinMode(gasPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int smoke = analogRead(gasPin);
  Serial.println(smoke);
  delay(1000);
  if(smoke > 700){
    digitalWrite(buzz, HIGH);
  }else{
    digitalWrite(buzz, LOW);
  }
}
