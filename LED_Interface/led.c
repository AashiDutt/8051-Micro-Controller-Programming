// This is a code for 8051 microcontroller using Keil Software

// blink led P1

#include<reg52.h>   // include header file

// declare a function
void ms_delay( unsigned int time);  // unsigned as time does not come with '+' or '-' sign.

void main()
{
	
	while(1)
	  {
		P1= 0x0ff;    // on led (giving logic 1 to port P1)
		ms_delay(1000);   // delay 1s
		P1=0x00;      // off led (giving logic 0 to port P1)
		ms_delay(1000);
	  }
}

void ms_delay(unsigned int time)
{
	unsigned int i,j;
	
	// time X 1ms
	for(i=0;i<time;i++)
	{
		for(j=0;j<113;j++);   // creates delay of 1ms
	}
}

// use Analysis Window button to verify delay time --> setup -->enter port name--> press enter --> check the analysis(zoom out the window)
// to debug start debugger --> peripherals --> choose port -->step over /step out(come out of loop) /run(for running whole code)