int cauta_sir(char *, char *){
        _asm{
                mov esi, [ebp+8]
                mov edi, [ebp+12]
                xor ecx, ecx
        _while1:
                mov al, [esi]
                cmp al, 0
        je _final_rau
                mov edi, [ebp+12]
                push esi
                inc ecx
        _while2:
                mov al, [esi]
                mov bl, [edi]
                cmp bl, 0
        je _final_bun2
                cmp al, 0
        je _final_rau2
                cmp al, bl
        jne _final_while2
                inc esi
                inc edi
        jmp _while2
        _final_while2:
                pop esi
                inc esi
        jmp _while1
        _final_bun2:
                mov eax, ecx
        _final_rau2:
                pop esi
        _final_rau:
        }
}