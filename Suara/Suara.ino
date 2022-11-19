int power = 2;
const int suara = A0;
int bacasuara;
int batas = 200;
int clap;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(power, OUTPUT);
  pinMode(suara, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bacasuara = analogRead(suara);
  Serial.println(bacasuara);
  if(bacasuara >= 50 and clap == 0){
    digitalWrite(power, HIGH);
    clap += 1;
  }
  else if(bacasuara >= 50 and clap == 1){
    digitalWrite(power, LOW);
    clap -= 1;
  }
}
