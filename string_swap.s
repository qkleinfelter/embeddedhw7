	AREA stringSwap, CODE
	EXPORT string_swap
	ALIGN

string_swap PROC
	; Since R0 and R1 are pointers to pointers its simple to swap them
	LDR R2, [R0] ; Load the value R0 points to into R2
	LDR R3, [R1] ; Load the value R1 points to into R3
	STR R3, [R0] ; Store the value at R3 into R0
	STR R2, [R1] ; Store the value at R2 into R1
	BX LR ; go back to the caller because we're done
	ENDP
	
	END