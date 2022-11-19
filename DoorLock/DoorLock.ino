  boolean cs;
  boolean ls;
  boolean rs;
  int dl = 8;
  int tch = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dl, OUTPUT);
  pinMode(tch, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  cs = digitalRead(tch);
  if(cs == HIGH and ls == LOW){
    if (rs == HIGH){
      digitalWrite(dl, LOW);
      rs = LOW;
    }
    else{
      digitalWrite(dl, HIGH);
      rs = HIGH;
    }
  }
  ls = cs;
}
