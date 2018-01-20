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
	MOV R2 , #0x0A
	LDR R5 , = 0x12345678
LOOP
	LDR R3 , [R0] , #4
	TEQ R3 , R5
	STREQ R3 , [R1] , #4
	SUB R2 , #1
	TEQ R2 , #0
	BNE LOOP

SRC DCD  0x12 , 0x23 , 0x34 , 0x45 , 0x56 , 0x67 , 0x12345678 , 0x89 , 0x91 , 0xAB

		AREA DATASEG , DATA , READWRITE

DST DCD 0,0,0,0,0,0,0,0,0,0
	END