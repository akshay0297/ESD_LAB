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
	LDR R3 , =0x00000001

	STR R2 , [R1] , #4
	STR R3 , [R1] , #4
	
	BL RECUR
STOP B STOP

RECUR
	LDR R4 , [R1 , #-4]!
	LDR R5 , [R1 , #-4]!
	MUL R5 , R4
	STR R5 , [R1] , #4
	ADD R4 , #01
	CMP R4 , R2
	BEQ brk
	STR R4 , [R1] , #4
	PUSH {R14}
	BL RECUR
	POP {R14}
brk BX LR
	AREA DATASEG , DATA , READWRITE
SRC DCD  0x12 , 0x23 , 0x34 , 0x45 , 0x56 , 0x67 , 0x78 , 0x89 , 0x91 , 0xAB
DST DCD 0,0,0,0,0,0,0,0,0,0
	END