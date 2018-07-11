#include<reg52.h>

void ms_delay();

void main()
{
	
	TMOD = 0X01; // timer 0 , mode 1,16 bit mode
	while(1)
	{
		P1 = 0XFF; // sending high and low logic 
		ms_delay();
		P1 =0X00;
		ms_delay();
	}
}

void ms_delay()  // 5ms
{
	TL0=0X00;  // timer 0 low 
	TH0=0X0EE; //timer 0 high (5ms)
	TR0=1;     // turn ON timer 0
	
	while(!TF0); //  if overflow flag is high
	TR0=0;     // turn timer off
	TF0=0;     // clear the timer flag reg.
}
	