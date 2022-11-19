#define enA 9
#define in1 4
#define in2 5

#define HALLSEN_A 2
#define ENCODER_CONSTANT 2

int interval = 60;
int motorSpeed = 0;
long previousMillis = 0;
long currentMillis = 0;

int rpm = 0;
int motorenA = 0;
int encoderValue = 0;
int data1 = 0;

float kp = 1.1;
float ki = 0.3;
float kd = 0;

int sp = 100;
int error = 0;
int last_error = 0; 
int sum_error = 0;

unsigned long lastTime;
int SampleTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(HALLSEN_A, INPUT_PULLUP);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  encoderValue = 0;
  attachInterrupt(digitalPinToInterrupt(HALLSEN_A), updateEncoder, RISING);
  previousMillis = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  while((data1<=100))
  {
    currentMillis = millis();
    if (currentMillis - previousMillis > interval)
    {
      rpm = (float)((encoderValue * ENCODER_CONSTANT)); 
      previousMillis = currentMillis;
      Serial.print(sp);
      Serial.print(", ");
      Serial.println (rpm);
      encoderValue = 0;
      
      error = sp - rpm;
      sum_error = sum_error + error;
      motorSpeed = ((kp * error) + (ki * sum_error) + (kd * (error-last_error)));
      if (motorSpeed > 255) motorSpeed - 255;
      else if (motorSpeed < 0) motorSpeed = 0;
      analogWrite (enA, motorSpeed); 
      last_error = error;
      data1++; 
    }
      analogWrite(enA, motorSpeed);
  }
  analogWrite(enA, 0);
}

void updateEncoder(){
  encoderValue++;
}
