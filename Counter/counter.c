#include<reg52.h>

sbit count_T0 =P3^4;  // P3.4

void main()
{
	TMOD =0X06;  // Counter 0, mode 2, 8 bit mode(0000-0110)[0x06]
	count_T0 =1; //P3.4 input pin
	
	while(1)
	{
		TH0=0x00;
		TL0=0x00;
		
		TR0=1; //counter 0 on
		
		while(!TF0)    //when tf flag is not 0 i.e it will be high
		{
			P1=TL0;
		}
		
		TF0 =0;
		TR0 =0;
	}
}