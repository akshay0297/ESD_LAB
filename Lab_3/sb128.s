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
	
	LDR R2 , [R0], #4
	LDR R3 , [R0], #4
	LDR R4 , [R0], #4
	LDR R5 , [R0], #4
	LDR R6 , [R0], #4
	LDR R7 , [R0], #4
	LDR R8 , [R0], #4
	LDR R9 , [R0], #4
	
	SUBS R2 , R6
	SBCS R3 , R7
	SBCS R4 , R8
	SBCS R5 , R9
	
	SBC R10 , #0
	RSB R10 , #0
	
	STR R2 , [R1] , #4
	STR R3 , [R1] , #4
	STR R4 , [R1] , #4
	STR R5 , [R1] , #4
	STR R10, [R1]
	
SRC DCD 0x12345670,0x12345671,0x12345672,0x72345673,0x12345674,0x12345675,0x12345676,0x92345677
	AREA DATASEG, DATA , READWRITE
DST DCD 0,0,0,0,0,0
	END