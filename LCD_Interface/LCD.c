//CODE FOR LCD INTERFACING WITH IC 8051 MICROCONTROLLER USING PROTEUS.

#include<reg52.h>

//    RS     RW     E       D0 -  D7
//   P2.0   P2.1   P2.2   P1.0 - P1.7
//#defining conections with port 2 pins
sbit RS=P2^0;// means RS = P2.0 pin
sbit RW=P2^1;
sbit E=P2^2;

// user defined functions
void send_command(unsigned int command_value ) ;
void send_data(unsigned int data_value) ; // function for passing data
void ms_delay( unsigned int time);        // function for delay window

void main()
{
	
//LCD INITIALIZATION

//2 lines and 5x7 matrix
send_command(0x38);    // giving command to LCD (writting into command code register of LCD)

//display on cursor blink
send_command(0x0E);

//clear display screen
send_command(0X01);




//PRINTING A CHARACTER

while(1)
{

send_command(0x80)	; // force cursor on 1st line		
send_data('H');
send_data('E');
send_data('L');
send_data('L');
send_data('O');

	
send_command(0xC0)	; // force cursor on 2nd line	
	
send_data('W');
send_data('O');
send_data('R');	
send_data('L');
send_data('D');
}

}

// defining functions

void send_command(unsigned int command_value )  // used to send command to Instruction Command Code Register
{
	P1=command_value; // write data to port pins
	RW=0; // RW=0 to write data and RW=1 to read data
	RS=0; // RS(register select )=0 to select instruction command code reg.
	E=1;  // enable pin at active High 
	ms_delay(10);
	E=0;
}	
// after this the data present at port pins will latch(be present) in the  command code register of LCD

void send_data(unsigned int data_value) // used to send data to Data Register
{
	P1=data_value;
	RW=0;
	RS=1; //RS(register select )=1 to select Data reg.
	E=1;
	ms_delay(10);
	E=0;
}
// after this the data present at port pins will latch(be present) in the  Data register of LCD


void ms_delay( unsigned int time)
{
	unsigned int i,j;
	//time X 1ms
	for(i=0;i<time;i++)
	{
		for(j=0;j<113;j++);  //1 ms delay
	}
}

