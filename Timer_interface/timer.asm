ORG 00H

MOV  TMOD,  #01H // mode 1 (16 bit timer moder) ,timer 0
again1:        // while loop
// led blink code 
MOV P1, #0FFH  // logic 1
ACALL DELAY  
MOV P1, #00H   // logic 0
ACALL DELAY
SJMP again1    // short jump 

// delay of 5ms 00H (0) TO 0EEH
//  1 count = 1.085us
//  4608 counts = 5ms
//  max counts = 65536  (2^16)
// so 65536 - 4608 = 60928 counts =EE00 (in hex)

DELAY: MOV TL0, #00H
MOV TH0, #0EEH
SETB TR0      // to turn ON the timer(timer 0 control run bit)
again: JNB TF0 ,again // flag bit when there is roll over from fffh to 000h(overflow flag)
CLR TR0               // JNB - jump if bit is not set
CLR TF0
RET

END