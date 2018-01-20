; ASCENDING STACK
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
	LDR R0,=SRC
	LDR R1,=5
	LDR R2,=2
	LDR R3,=4
	LDR R4,=1
	LDR R5,=7
	LDR R6,=9
	LDR R7,=10
	LDR R8,=3
	LDR R9,=6
	LDR R10,=8
	STM R0,{R1-R10}
	LDR R12,=N
OUT
	MOV R1,R0
	LDR R2,[R1]
	MOV R3,R1 
	MOV R11,R12
IN
	LDR R4,[R3]
	CMP R4,R2
	MOVHI R2,R4
	MOVHI R1,R3
	ADD R3,#4
	SUB R11,#1
	TEQ R11,#0
	BNE IN
	
	LDR R5,[R0]
	STR R2,[R0],#4
	STR R5,[R1]
	SUB R12,#1
	TEQ R12,#0
	BNE OUT
	LDMDB R0!,{R1-R10}
	
STOP B STOP
N EQU 10
	AREA DATASEG,DATA,READWRITE
SRC DCD 0,0,0,0,0,0,0,0,0,0
	END