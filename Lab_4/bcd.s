	AREA RESET , DATA ,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10000000
	DCD Reset_Handler
	ALIGN
	AREA mycode , CODE , READONLY
	ENTRY
	EXPORT
Reset_Handler
	LDR R0 , = SRC
	LDR R1 , =DST
	LDR R2 , [R0] , #4
	LDR R3 , [R0] 
	MOV R8 , #0
	MOV R10 , #8
UP 
	MOV R4 , R2
	LSR R4 , R8
	AND R4 , #0x0F
	MOV R5 , R3
	LSR R5 , R8
	AND R5 , #0x0F
	
	ADD R5 , R6
	ADD R6 , R4 , R5
	CMP R6 , #09
	BLS skip
	ADD R6 , #06	

skip 
	AND R7 , R6 , #0x0F
	LSR R6 , #4
	ORR R9 , R7
	ROR R9 , #4
	ADD R8 , #4
	SUB R10 ,#1
	TEQ R10 , #0
	BNE UP
	STR R9 , [R1] , #4
	STR R6 , [R1]
	AREA DATASEG , DATA , READWRITE
SRC DCD  0x12 , 0x23 , 0x34 , 0x45 , 0x56 , 0x67 , 0x78 , 0x89 , 0x91 , 0xAB
DST DCD 0,0,0,0,0,0,0,0,0,0
	END