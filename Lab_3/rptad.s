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
	
	LDR R2 , [R0] ,#4
	LDR R3 , [R0]
START ADDS R4 , R2
	ADCS R5 , #0
	SUB R3 , #1
	TEQ R3 , #0
	BNE START
	STR R4 , [R1] ,#4
	STR R5 , [R1]
	
	
SRC DCD 0x00000012,0x00000005
	AREA DATASEG , DATA , READWRITE
DST DCD 0,0
	END