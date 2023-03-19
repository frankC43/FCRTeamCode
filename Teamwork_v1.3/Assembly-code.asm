.386
.model flat, C

.code

IsValidAssembly PROC
;After calling the proceudre in c++, first is push the ret then a, b and c

push ebx
mov ebx, esp	; Prologe in the stack, as R6

push edx	; first input
push ecx	; second input
push eax	; thrid input

;Body of the procedure

AND edx, 255  ; Bit mask

CMP edx, 42 ; CMP first input wih 66
JNS secondFlagCheck
JMP retFalse

secondFlagCheck:
JNZ codeIfA
JMP retFalse


codeIfA:
AND ecx, 33554432   ; bit 26 of ecx 
sar ecx, 25			; swift the bit 25 to the right, SAR conserves the sign
AND eax, 4          ; bit 3 of eax
sar eax, 2			; swift two places to the right the 3 bit

CMP eax, ecx    ; CMP of their bit value
JZ retTrue
JMP retFalse

retTrue:
mov edx, 1 ; the procedure return true (1)
JMP endCondition

retFalse:
mov edx, 0 ; the procedure return false (0)

endCondition:

pop eax				; We return registers its values
pop ecx				
mov eax, edx		; eax will pass the boolean result to the function in cpp
pop edx
pop ebx

ret

IsValidAssembly ENDP

END