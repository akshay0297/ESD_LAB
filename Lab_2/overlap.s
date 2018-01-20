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
	LDR R0 , = SRC + 36
	LDR R1 , = SRC + 72
	LDR R3 , [R0]
	STR R3 , [R1]
	SUB R0 , #4
	SUB R1 , #4
	LDR R3 , [R0]
	STR R3 , [R1]
	SUB R0 , #4
	SUB R1 , #4
	LDR R3 , [R0]
	STR R3 , [R1]
	SUB R0 , #4
	SUB R1 , #4
	LDR R3 , [R0]
	STR R3 , [R1]
	SUB R0 , #4
	SUB R1 , #4
	LDR R3 , [R0]
	STR R3 , [R1]
	SUB R0 , #4
	SUB R1 , #4
	LDR R3 , [R0]
	STR R3 , [R1]
	SUB R0 , #4
	SUB R1 , #4
	LDR R3 , [R0]
	STR R3 , [R1]
	SUB R0 , #4
	SUB R1 , #4
	LDR R3 , [R0]
	STR R3 , [R1]
	SUB R0 , #4
	SUB R1 , #4
	LDR R3 , [R0]
	STR R3 , [R1]
	SUB R0 , #4
	SUB R1 , #4
	LDR R3 , [R0]
	STR R3 , [R1]
STOP B STOP
	AREA DATASEG , DATA , READWRITE
SRC DCD  0x12 , 0x23 , 0x34 , 0x45 , 0x56 , 0x67 , 0x78 , 0x89 , 0x91 , 0xAB
DST DCD 0,0,0,0,0,0,0,0,0,0
	END