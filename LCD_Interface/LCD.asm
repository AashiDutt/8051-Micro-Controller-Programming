; Displaying character on LCD using Assembly Language

ORG 00H
	
; RS = P2.0 , RW = P2.1, E=P2.2, D0 -D7 = P1.0 - P1.7

RS EQU P2.0 ; EQU means equating (i.e RS = P2.0)
RW EQU P2.1
E  EQU P2.2
	
;LCD INITIALIZATION

MOV P1,#38H    ;2 lines and 5x7 matrix 
; load 38H data is loaded to port P1
ACALL send_command

MOV P1, #0EH   ; display on cursor blink
ACALL send_command

MOV P1 ,#01H   ;clear display screen
ACALL send_command

here: MOV P1,#80H  ; Force cursor to 1st line
      ACALL send_command
	  
; Printing a command

MOV P1,#'H'  ;#'E' means we want to transmit ASCII value of E
ACALL send_data
MOV P1,#'E'
ACALL send_data
MOV P1,#'L'
ACALL send_data
MOV P1,#'L'
ACALL send_data
MOV P1,#'O'
ACALL send_data

MOV P1,#0C0H ; Force cursor to 2nd line
ACALL send_command

MOV P1,#'W'
ACALL send_data
MOV P1,#'O'
ACALL send_data
MOV P1,#'R'
ACALL send_data
MOV P1,#'L'
ACALL send_data
MOV P1,#'D'
ACALL send_data

JMP here

send_command:   CLR RW
				CLR RS
				SETB E
				ACALL DELAY
				CLR E
				RET
				
send_data:      CLR RW
				SETB RS
				SETB E
				ACALL DELAY
				CLR E
				RET
				
DELAY :  MOV R0, #10
Here2 :  MOV R1, #255
Here1 :  DJNZ r1, here1
		 DJNZ R0, here2
				 
		RET				

END