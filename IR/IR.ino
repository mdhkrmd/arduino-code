int ir = 2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ir, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilaiIR = digitalRead(ir);
  Serial.println(nilaiIR);
}
