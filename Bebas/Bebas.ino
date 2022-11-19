int relay = 2;
int turbidity = 4;
 
void setup()
{
  pinMode(turbidity, INPUT);
  pinMode(relay , OUTPUT);   
}
 
void loop()
{  
  if (turbidity <= 10){
  digitalWrite(relay, HIGH);
  delay(5000);  
  }
  digitalWrite(relay, LOW);
  delay(1000);
}
