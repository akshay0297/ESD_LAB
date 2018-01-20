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
	LDR R3 , [R0] , #4
	MOV R4 , R2
	MOV R5 , R3
	
START 
	CMP R2 , R3
	BHI high
	BEQ equl
	ADD R2 , R4
	B START
high
	ADD R3 , R5
	B START
equl
	STR R2 , [R1]
	
	
	AREA DATASEG , DATA , READWRITE
SRC DCD  0x12 , 0x23 , 0x34 , 0x45 , 0x56 , 0x67 , 0x78 , 0x89 , 0x91 , 0xAB
DST DCD 0,0,0,0,0,0,0,0,0,0
	END