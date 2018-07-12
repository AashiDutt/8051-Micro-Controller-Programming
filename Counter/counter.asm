ORG 00H
	
MOV TMOD ,#06h    ;COUNTER 0 MODE2 8 BIT AUTO RELOAD MODE
SETB P3.4         ; set P3.4 pin as input pin (set bit)

MOV TL0,#00H
MOV TH0,#00H

HERE:SETB TR0    ;set timer run counter to 0

BACK:MOV P1,TL0 
JNB TF0,BACK     ; jump not bit , if TF0 is not det jumpp to back

CLR TR0
CLR TF0

SJMP HERE

END