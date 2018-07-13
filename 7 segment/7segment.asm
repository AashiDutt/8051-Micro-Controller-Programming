// this is an assembly language code for 7 segment interface with ic 8051

ORG 0000H
	MOV A,#00H
	AGAIN: MOV R5,#10    // counter
	MOV DPTR,#500H       // DPTR data pointer(uses 16 bit register)
	HERE: MOVC A,@A+DPTR // MOVC = MOVE CONTENT FROM CODE MEMORY TO accumulator
	// @ means value at address 500H
	
	MOV P3,A
	LCALL DELAY
	INC DPTR
	MOV A,#00H
	DJNZ R5,HERE
	SJMP AGAIN
	
	
	DELAY:  MOV R0,#07
	HERE3:MOV R1,#255
	HERE2:MOV R2,#255
	HERE1:DJNZ R2,HERE1
		  DJNZ R1,HERE2
		  DJNZ R0,HERE3
	RET

ORG 500H   // FOLLOWING VALUES STORED AT THIS LOCATION
	DB 3FH,06H,5BH,4FH,66H,6DH,7DH,07H,7FH,67H  //COMMON CATHODE (DISPLAY VALUES FROM 0 TO 9)
	; DB assembly directive	
END
	