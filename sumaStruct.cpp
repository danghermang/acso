Se da o lista liniara simplu inlantuita:
struct Nod{
unsigned short nr;
Nod* urm;
};

Sa se scrie in asm o functie care returneaza suma nr impare din lista:
unsigned short suma(Nod *first_node);


unsigned short suma(Nod *first_node)
{
_asm{
mov ebx, [ebp + 8]
mov esi,0
_avanseaza_in_struct:
cmp ebx, NULL
je _final
mov eax, [ebx]
mov edx,0
mov edi,2
div edi
cmp edx,0
je _par
add esi, [ebx]
_par:
mov ebx, [ebx+4]
jmp _avanseaza_in_struct
_final:
mov eax,esi
}
}