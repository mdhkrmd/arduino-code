int pwm = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(pwm, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(pwm, 64);
}
