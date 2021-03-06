;BUBBLE SORT
	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	ALIGN
	DCD Reset_Handler
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R4 , #0
	MOV R1 , #10
	LDR R0 , =SRC
	LDR R2 , =DST
UP
	LDR R3 , [R0 , R4]
	STR R3 , [R2 , R4]
	ADD R4 , #04
	SUB R1 , #01
	CMP R1 ,#0
	BHI UP
	LDR R0 , =DST
						; iNNER LOOP COUNTER
	MOV R3 , #10
	SUB R3 , R3 ,#1
	MOV R9 , R3			;R9 CONTAINS NUMBER OF PASSES
						;OUTER LOOP
OUTER_LOOP

	MOV R5 , R0
	MOV R4 , R3
	
INNER_LOOP

	LDR R6 , [R5] , #4
	LDR R7 , [R5]
	CMP R7 , R6
	
	STRLS R6 , [R5]
	STRLS R7 , [R5 , #-4]
	
	SUBS R4 , R4 , #1
	BNE INNER_LOOP
	SUB R3 , #01
	SUBS R9 , R9 ,#1
	BNE OUTER_LOOP

SRC DCD 0x10 , 0x05 , 0x33 , 0x24 , 0x56 , 0x77 , 0x21 , 0x04 , 0x87 , 0x01
	AREA DATASEG , DATA , READWRITE
DST DCD 0,0,0,0,0,0,0,0,0,0
	END