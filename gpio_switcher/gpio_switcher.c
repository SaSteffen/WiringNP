#include <wiringPi.h>

typedef union
{
  struct
  {
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
    unsigned char bit8 : 1;
  }bits;
  unsigned char val;
}OutStatus;

int main(void)
{
  wiringPiSetup() ;
  OutStatus out = {0};
  pinMode (7, OUTPUT) ;
  pinMode (15, OUTPUT) ;
  for(;;)
  {
    for(int i=0; i<4; i++){
      out.val = i;
      digitalWrite(15, out.bits.bit1) ;
      digitalWrite(7, out.bits.bit2) ;
      delay (2500) ;
    }

  }
}
