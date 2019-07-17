/*void minor(int *src,int *dst,int dim,int x,int y); 
unde src şi dst reprezintă adresele de început ale unor matrici pătratice, de dimensiuni dim × dim., 
respectiv (dim - 1) × (dim - 1). 
FuncŃia depune în matricea dst elementele submatricii obŃinute din matricea src prin 
eliminarea liniei x şi a coloanei y.*/ 



void minor(int* src, int* dst, int dim, int x, int y){
        _asm{
                mov esi, [ebp+8]//sursa
                mov edi, [ebp+12]//destinatie
                mov edx, [ebp+16]//dimensiunea
                xor eax, eax //linia
                xor ebx, ebx //coloana
        _while1:
                cmp eax, edx
                jge _finish
                cmp eax, [ebp+20]
                jz _salt
                inc eax
                xor ebx, ebx
        _while2:
                cmp ebx, edx
                jge _while1
                cmp ebx, [ebp+24]
                jz _salt2
                mov ecx, [esi]
                mov [edi], ecx
                add edi, 4
                add esi, 4
                inc ebx
                jmp _while2
        _salt:
                inc eax
                lea esi, [esi+edx*4]
                jmp _while1
        _salt2:
                inc ebx
                add esi, 4
                jmp _while2
        _finish:
        }
}