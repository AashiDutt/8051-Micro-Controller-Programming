ORG 00h ;The ORG directive is used to indicate the beginning of the address
        ;The number that comes after ORG can either be in hex or decimal
		;If the number is not followed by H, it is deimal and the assembler will convert it to hex
		
		
		HERE: MOV P1,#0FFH   ; led P1 ,# Indicates that 0FF is a data and not an address
			  LCALL DELAY    ; Function call for subroutine DELAY
			  MOV P1,#00H    
			  LCALL DELAY
			  SJMP HERE      ; SHORT JUMP to HERE
			 
			 
; delay = 2 x 7 x 255 x 255 x 1.085us =0.99s = total delay duration in microseconds
DELAY: MOV R0,#07
HERE3: MOV R1,#255
HERE2: MOV R2,#255
HERE1: DJNZ R2,HERE1
	   DJNZ R1,HERE2
	   DJNZ R0,HERE3
	   
	   RET                   ; return helps to return program counter from subroutine and back to main code
	
END
; this indicates end of code and if any code is written beyond this is ignored by the assembler

; for continious preview of values 
; goto peripherals --> port 1(P1) --> port window opens -->goto Run or press F5 key