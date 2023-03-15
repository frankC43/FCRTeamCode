.386
.model flat, C

.code

IsValidAssembly PROC ; proto :DWORD :DWORD :DWORD

;Data reading

xor eax, eax, eax
xor ebx, ebx, ebx
xor ecx, ecx, ecx

mov eax, DWORD PTR [esp+4] ; First input
mov ebx, DWORD PTR [esp+8] ; Second input
mov ecx, DWORD PTR [esp+16] ; Third input

;Body of the procedure

and eax, 0x000000FF ; Bit mask

cmp eax, 0x0000000024 ; CMP eax wih 66
brns nextConditionA
jmp end

nextConditionA:
brz codeIfA
jmp end

codeIfA:
and ebx, 0x02000000 ; bit 26 of ebx   NO SE SI ES 0x04000000, PROBAR
sar ebx, 25 ; swift the bit 25 to the right, SAR conserves the sign
and ecx, 0x00000004 ; bit 3 of ecx
sar ecx, 2 ; swift two places to the right the 3 bit

cmp ebx, ecx ; Cmp of their bit value
brz equalsInB:
jmp noEqualInB

equalsInB:
mov edx, 1 ; the procedure return true (1)
jmp end

noEqualInB:
mov edx, 0 ; the procedure return false (0)

end:

pop eax ; Clean the stack
pop ebx
pop ecx

mov eax, edx ; eax is the return registed that is passed to c++ code
ret

IsValidAssembly ENDP

END