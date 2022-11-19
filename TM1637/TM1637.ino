#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);
 
void setup()
{
 display.setBrightness(0x0f);  
}
 
void loop()
{
  for(int i = 0; i <= 9; i++){
    display.showNumberDec(i);
    delay(1000);
  }
  for(int i = 9; i >= 0; i--){
    display.showNumberDec(i);
    delay(1000);
}
}
