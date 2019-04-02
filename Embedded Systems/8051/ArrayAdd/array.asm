ORG 300H        ;
DB 1,4,5,6,7    ;
; ARRAY OF 5
ORG 0000H       ;
MOV DPTR, #0300H;
; FIRST COUNTER
MOV R7, #05H    ;
MOV A, #00H     ;
MOV R0, #00H    ;
; SUM VARIABLE
MOV R6,#00H     ;

LOOP:
		MOV A, R0       ;
		MOVC A,@A+DPTR  ;
		ADD A, R6       ;
		MOV R6,A        ;
		INC R0          ;
		DJNZ R7, LOOP   ;

MOV P0, R6
END