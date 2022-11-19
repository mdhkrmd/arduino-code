//sesuaikan dengan PIN yang dipasang
int IN1=8;
int IN2=9;
int IN3=10;
int IN4=11;
int step = 100;
int delaytime=3; //makin kecil delay, makin cepat motor berputar

void setup(){
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
}

void loop(){
//maju 60;
for (int i=0; i<100; i++){
maju();
}
for (int i=100; i>0; i--){
mundur();
}
}

void maju(){
//step 4
step1();
delay(delaytime);
//step 3
step2();
delay(delaytime);
//step 2
step3();
delay(delaytime);
//step 1
step4();
delay(delaytime);
}

void mundur(){
//step 4
step4();
delay(delaytime);
//step 3
step3();
delay(delaytime);
//step 2
step2();
delay(delaytime);
//step 1
step1();
delay(delaytime);
}

void step1(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,HIGH);
}
void step2(){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
}
void step3(){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
}
void step4(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
}
