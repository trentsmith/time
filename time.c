
#include "msp430fg4618.h"
#include "intrinsics.h"
#include "stdio.h"
void Init_LCD(void);
unsigned char *LCDSeg = (unsigned char *) &LCDM3;
int LCD_SIZE=11;
int array[16]= {95,6,107,47,54,61,125,23,127,55};
int su,st,mu,mt,h,hu,ht;
int main(void)
{
Init_LCD();
  WDTCTL = WDTPW + WDTHOLD;
  P2DIR |= 0x02;
  P2OUT = 0x02;
   TACCTL0 = 0x010;
   TA0CTL = 0x01D4;
   TACCR0=0x1000;
__enable_interrupt();

  for (;;){
  }
}

#pragma vector = TIMERA0_VECTOR;
__interrupt void Timer_ISR(void)
  {
P2OUT ^=0x02;
su++;
if(su == 10)
 {su = 0; st ++;}
if(st == 6)
 {st = 0; mu++;}
if(mu == 10)
 {mu = 0; mt++;}
if(mt == 6)
 {mt = 0; h++;}
 if(h == 13)
 {h = 1;}
hu = h;
ht = 0;
if(h == 10);
 {hu = 0; ht =1;};
if(h == 11);
 {hu = 1; ht =1;};
if(h == 12);
 {hu = 2; ht =1;};
 if(h >9)
{
    hu = h-10;
    ht = 1;
}
else
{
    hu = h;
    ht =0;
}

 int i = 0;
 for(i = 0;i<0x1000;i++)
 {

 }
 LCDSeg[0] = array[su];
 LCDSeg[1] = array[st];
 LCDSeg[2] = 0;
 LCDSeg[3] = array[mu];
 LCDSeg[4] = array[mt];
 LCDSeg[5] = 0;
 LCDSeg[6] = array[hu];
 LCDSeg[7] = array[ht];
  }

void Init_LCD(void){
int n;
for (n=0;n<LCD_SIZE;n++){
 *(LCDSeg+n) = 0;
 }
 P5SEL = 0x1C;
 LCDAVCTL0 = 0x00;
 LCDAPCTL0 = 0x7E;
 LCDACTL = 0x7d;
}