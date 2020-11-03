	AREA maxFour, CODE
	EXPORT max4
	ALIGN
max4 PROC
	CMP R0, R1 ; compare the first 2 ints
	MOVLT R0, R1 ; if R0 < R1, R0 = R1
	CMP R2, R3 ; compare the second 2 ints
	MOVLT R2, R3 ; if R2 < R3, R2 = R3
	CMP R0, R2 ; compare the 2 remaining ints
	MOVLT R0, R2 ; if R0 < R2, R0 = R2
	BX LR ; back to caller
	ENDP
		
	END