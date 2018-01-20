; 32 BIT UNPACKED TO PACKED
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
	LDR R0 , =SRC
	LDR R1 , =DST
	MOV R8 , #04
UP
	LDRB R2 , [R0] , #01
	ORR R10 , R2
	ROR R10 , #04
	SUB R8 , #01
	TEQ R8 , #0
	BNE UP
	STR R10 , [R1]
SRC DCD 0x0304050A
	AREA DATASEG , DATA , READWRITE
DST DCD 0,0
	END