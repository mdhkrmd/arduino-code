int tcrt = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tcrt, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int tcread = 0;
  tcread = digitalRead(tcrt);
  Serial.println(tcread);
}
