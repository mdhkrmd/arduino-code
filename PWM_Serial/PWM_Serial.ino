// pins for the LEDs:
const int pin7 = 5;
const int pin8 = 6;
const int sens = 2;
const int led = 13;
int sensst = 0;

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // make the pins outputs:
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(sens, INPUT);
  pinMode(led, OUTPUT);

}

void loop() {

  sensst = digitalRead(sens);
  if  (sensst == HIGH){
    Serial.println("kosong");
  }else{
    Serial.println("Ada halangan");
  }
  delay(100);
  
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int pw = Serial.parseInt();
    // do it again:


    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      pw = constrain(pw, 0, 255);

      if (pw == 1){
        pw = 150;
      }else if (pw == 2){
        pw = 155;
      }else if (pw == 3){
        pw = 165;
      }else if (pw == 4){
        pw = 175;
      }else if (pw == 5){
        pw = 185;
      }else if (pw == 6){
        pw = 200;
      }else if (pw == 7){
        pw = 215;
      }else if (pw == 8){
        pw = 230;
      }else if (pw == 9){
        pw = 255;
      }else{
        pw = 0;
      }


      // fade the red, green, and blue legs of the LED:
      analogWrite(pin7, pw);


      // print the three numbers in one string as hexadecimal:
      Serial.print("Jumlah power yang diberikan = ");
      Serial.println(pw);

    }
  }
}
