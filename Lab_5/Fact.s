; WAP to find factorial of a number usign recursion
	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0X10001000
	DCD Reset_Handler
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R0,= SRC
	LDR R5,= DST
	ldr R2,[R0]
	MOV R4,#01
	BL Fact

STOP B STOP

Fact
	TEQ R2,#01
	BEQ exit
	MUL R4,R2
	STR R4,[R5]
	SUB R2,#01
	PUSH {R14}
	BL Fact
exit
	POP  {R14}
	BX LR

SRC DCD 0X0000003
	AREA DATASEG,DATA,READWRITE
DST DCD 0,0
	END