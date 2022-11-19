int mq = A5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(mq, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int baca = analogRead(mq);
  Serial.println(mq);

}
