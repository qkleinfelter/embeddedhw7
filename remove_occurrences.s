	AREA removeOccurrences, CODE
	EXPORT remove_occurrences
	ALIGN

remove_occurrences PROC
	PUSH {R4}
	MOV R2, #0 ; reading index variable
	MOV R3, #0 ; writing index variable
	
loop
	LDRB R4, [R0, R2] ; Load the current point of the string into R4
	; If R4 is 0 then we hit the null term and should exit
	CBZ R4, exit
	CMP R4, R1 ; Compare the current character to the character we don't want
	ADD R2, #1 ; increment reading index variable
	BEQ loop ; if R4 == R1, then we don't want to add it so loop again
	STRB R4, [R0, R3] ; stores the value of R4 in the new string at the correct index
	ADD R3, #1 ; increment writing index var
	B loop ; continue on
	
exit
	; We just need to add a null terminator to our string and exit now
	MOV R4, #0
	STRB R4, [R0, R3]
	POP {R4}
	BX LR
	ENDP
		
	END