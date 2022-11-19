#define enA 9
#define in1 2
#define in2 3
#define enB 10
#define in3 4
#define in4 5
int motorSpeedA = 0;
int motorSpeedB = 0;


void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}


void loop() {
    motorSpeedA = 255; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
    motorSpeedB = 255; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255

    for(int a = 0; a <= 255; a+=10){
      analogWrite(enA, a);
      delay(200);
    }

    for(int a = 255; a <= 0; a-=10){
      analogWrite(enA, a);
      delay(200);
    }
     // Send PWM signal to motor A
    analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
    
    // Set Motor A backward
    digitalWrite(in1, motorSpeedA);
    digitalWrite(in2, motorSpeedA);
    
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(5000);
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    
    // Set Motor B forward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(2000);
}
