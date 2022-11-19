int ldr = 2;
int pompa = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pompa, OUTPUT);
  pinMode(ldr, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int bacaLdr = digitalRead(ldr);
  Serial.println(bacaLdr);
  if(bacaLdr == 1){
    digitalWrite(pompa, HIGH);
  }
  else{
    digitalWrite(pompa, LOW);
  }
}
