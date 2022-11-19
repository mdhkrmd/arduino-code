int api = 2;
int buzz = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(api, INPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilai = analogRead(api);
  Serial.println(nilai);
}
