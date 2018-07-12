// This code represents serial communication for data transfer in 8051 microcontroller

#include<reg52.h>

void main()
{
	TMOD =0x20;   // timer 1 mode2
	
	SCON = 0x50;  //model run
	
	TH1 = 0x0FD ; //9600 baud rate TH1=(256 -(28800 / baud_rate))
	
	TR1 =1;      // turn ON timer 1
	
	//TX(transmission)
	while(1)
{
SBUF ='L';    // send ASCII value
while(!TI);
TI=0;         // tramsmit interupt

SBUF = 'A';
while(!TI);
TI=0;

SBUF= 'B';
while(!TI);
TI =0;

		
// rx (reciever)
while(!RI);
P1 = SBUF;   // sending recieved data to port 	P1
RI =0;

		
while(!RI);
P1 =SBUF;
RI =0;

}
}