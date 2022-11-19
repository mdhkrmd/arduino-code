  boolean cs;
  boolean ls;
  boolean rs;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  cs = digitalRead(2);
  if(cs == HIGH and ls == LOW){
    if (rs == HIGH){
      digitalWrite(8, LOW);
      rs = LOW;
    }
    else{
      digitalWrite(8, HIGH);
      rs = HIGH;
    }
  }
  ls = cs;
}
