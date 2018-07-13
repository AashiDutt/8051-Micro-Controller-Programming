// Code for Interrupt using Level Triggered Mode
// We are witting a code for square wave generator such that when an interrupt occurs the state of LED changes
	
#include<reg51.h>

void MSDelay(unsigned int);

sbit sq_wave=P1^3;
sbit LED=P1^4;
sbit SW=P3^2;

void EINT_LED() interrupt 0 
{
LED=~LED;  //cpl
MSDelay(500);	
}

void MSDelay(unsigned int time)
{
unsigned int i,j;
for (i=0;i<time;i++)
for (j=0;j<113;j++);
}

void main() 
{
SW=1; // p3.2 input
LED=0;
IT0=0; //LEVEL TRIGGERED
IE=0x81; //enable interrupt for EINT0 EXTERNAL INTERRUPT 0
while (1) 
{
sq_wave=1; 
MSDelay(500);
sq_wave=0;
MSDelay(500);
}
}

