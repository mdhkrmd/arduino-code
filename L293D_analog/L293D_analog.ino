static const uint8_t pwm_A = 5;
static const uint8_t pwm_B = 4;
static const uint8_t dir_A = 0;
static const uint8_t dir_B = 2;
int motor_speed = 180;
int durasi_belok = 1200;
int ir_kanan = 12;
int ir_kiri = 14;

void setup() {
  // put your setup code here, to run once:
 pinMode(pwm_A, OUTPUT);
 pinMode(pwm_B, OUTPUT);
 pinMode(dir_A, OUTPUT);
 pinMode(dir_B, OUTPUT);
 pinMode (ir_kanan, INPUT);
 pinMode (ir_kiri, INPUT);
}

void loop() {

 int right_ir = digitalRead(ir_kanan);
 int left_ir = digitalRead(ir_kiri);
 

//MAJU
 if((left_ir == LOW)&&(right_ir == LOW)){
  analogWrite(pwm_A, motor_speed);
  analogWrite(pwm_B, motor_speed);
  digitalWrite(dir_A, HIGH);
  digitalWrite(dir_B, HIGH);
 }
 //BELOK KANAN
 else if((left_ir == LOW)&&(right_ir == HIGH)){
  analogWrite(pwm_A, motor_speed);
  analogWrite(pwm_B, motor_speed);
  digitalWrite(dir_A, LOW);
  digitalWrite(dir_B, HIGH);
  //delay(durasi_belok);
 }
 //BELOK KIRI
 else if((left_ir == HIGH)&&(right_ir == LOW)){
  analogWrite(pwm_A, motor_speed);
  analogWrite(pwm_B, motor_speed);
  digitalWrite(dir_A, HIGH);
  digitalWrite(dir_B, LOW);
  //delay(durasi_belok);
 }
 //STOP
 else if((left_ir == HIGH)&&(right_ir == HIGH)){
   analogWrite(pwm_A, 0);
   analogWrite(pwm_B, 0);
 }
}
