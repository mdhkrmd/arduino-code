int push = 6;
int led = 5;
int tomboltest;

void setup() {
  // put your setup code here, to run once:
 pinMode(led, OUTPUT);
 pinMode(push, INPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:
  tomboltest = digitalRead(push);

  int count = 0;
  if(tomboltest == HIGH and count == 0){
    digitalWrite(led, HIGH);
    count += 1;
  }else if (tomboltest == HIGH and count == 1){
    digitalWrite(led, LOW);
    count -= 1;
  }
}
