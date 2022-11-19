int ir = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ir, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(ir);
  Serial.println(value);
}
