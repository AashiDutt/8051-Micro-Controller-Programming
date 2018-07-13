// This is a c code for Relay Interfacing with 8051 microcontroller

#include<reg52.h>

sbit relay = P3^1;

void ms_delay(unsigned int time);
void main()
{
while(1)
{
relay = 1;
ms_delay(5000);  // 5 sec delay
relay=0;
ms_delay(5000);
}
}

void ms_delay(unsigned int time)
{
	unsigned int i, j;
	//Time X 1ms
	for(i=0;i<time;i++)
	{
		for(j=0;j<113;j++);
	}
}