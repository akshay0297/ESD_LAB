;2 DIGIT UNPACKED ASCII TO PACKED HEXA

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
	LDR R2 , [R0]
	
	AND R3 , R2 , #0xFF
	AND R4 , R2 , #0xFF0000
	LSR R4 , #0x10
	CMP R3 , #0x41
	SUBGE R3 , #0x37
	SUBLO R3 , #0x30
	ORR R9 , R3
	ROR R9 , #04
	CMP R4 , #0x41
	SUBGE R4 , #0x37
	SUBLO R4 , #0x30
	ORR R9 , R4
	ROR R9 , #04
	ROR R9 , #0x18
	STR R9 , [R1]

SRC DCD 0x00390041
	AREA DATASEG , DATA , READWRITE
DST DCD 0,0
	END