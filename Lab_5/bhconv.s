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
	LDR R1 , = DST
	LDR R2 , [R0]
	MOV R3,#0
	CMP R2 , #10
	BLS LOW
START 
	SUB R2 , #10
	ADD R3 , #01
	CMP R2 , #10
	BLO LOW
	B START

LOW 
	LSL R3 , #04
	ADD R3 , R2
	STR R3 ,[R1]
	

	AREA DATASEG , DATA , READWRITE
SRC DCD  0x12 , 0x23 , 0x34 , 0x45 , 0x56 , 0x67 , 0x78 , 0x89 , 0x91 , 0xAB
DST DCD 0,0,0,0,0,0,0,0,0,0
	END