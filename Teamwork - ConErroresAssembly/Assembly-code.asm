.386
.model flat, C

.data


push ebx
mov ebx, esp ; Prologe in the stack, as R6

xor eax, eax
xor ecx, ecx
xor edx, edx

.code

IsValidAssembly PROC
;After calling the proceudre in c++, first is push the ret then a, b and c

mov eax, [ebp+8] ; First input a , +8 due to in +4 is the ret
mov ecx, [ebp+12] ; Second input b , +12 due to in stack of x86-32 we increment by 4
mov edx, [ebp+16] ; Third input c  +16 due to the previous said

;Body of the procedure

AND eax, 0x00FF ; Bit mask

CMP eax, 66 ; CMP eax wih 66
JG codeIfA
JE endCondition

codeIfA:
and ecx, 0x02000000 ; bit 26 of ebx   NO SE SI ES 0x04000000, PROBAR
sar ecx, 25 ; swift the bit 25 to the right, SAR conserves the sign
and edx, 0x00000004 ; bit 3 of ecx
sar edx, 2 ; swift two places to the right the 3 bit

cmp ebx, ecx ; Cmp of their bit value
JE equalsInB:
JMP noEqualInB

equalsInB:
mov edx, 1 ; the procedure return true (1)
JMP endCondition:

noEqualInB:
mov edx, 0 ; the procedure return false (0)

endCondition:

pop eax ; Clean the stack
pop ebx
pop ecx

mov eax, edx ; eax is the return registed that is passed to c++ code
ret

IsValidAssembly ENDP

END