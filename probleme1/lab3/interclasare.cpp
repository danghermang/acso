#include <stdio.h>
#include <malloc.h>

struct Vector{
	short nr;
	int* v;
};


Vector interclaseaza_v(Vector& n,Vector& m)
{
	_asm{
		mov eax,[ebp+8]
		mov ebx,[ebp+12]
		movzx eax, word ptr [eax]
		movzx ebx, word ptr [ebx]
		add eax,ebx
		shl eax,2
		push eax
		call dword ptr malloc//aveti grija la ce se afla in eax, ecx si edx(pe langa astea se mai schimba si: eip, efl)
		mov edx,eax
		pop eax
		shr eax,2
		mov ecx,0
while_:
		cmp ecx,eax
		jae exit_

		test ecx,1
		jnz impar
par:
		mov ebx,[ebp+8]
		shr ecx,1
		cmp word ptr [ebx],cx//daca nu mai sunt elemente in primul vector
		jbe copiaza_v2//copiem restul continutului lui v2
		mov ebx,[ebx+4]//copiem in ebx pointerul catre vector
		mov ebx,[ebx+4*ecx]//copiem in ebx elementul de pe pozitia [ecx/2] din vectorul n
		shl ecx,1
		mov [edx+4*ecx],ebx//si completam in vectorul final
		jmp next_
impar:
		mov ebx,[ebp+12]
		shr ecx,1
		cmp word ptr [ebx],cx//daca nu mai sunt elemente in al II-lea vector
		jbe copiaza_v1//copiem continutul primului vector
		mov ebx,[ebx+4]//copiem in ebx ptr spre vector
		mov ebx,[ebx+4*ecx]//luam elementul de pe pozitia [ecx/2] din vectorul n, adica de pe poz 0,1,2,3,etc
		shl ecx,1
		or ecx,1
		mov [edx+4*ecx],ebx//si completam in vectorul final
		jmp next_

copiaza_v2:
		shl ecx,1
		xor esi,esi//offset in vect din param
while_2:
		mov ebx,[ebp+12]
		add esi,ecx
		cmp esi,eax
		jae  exit_
		sub esi,ecx
		mov ebx,[ebx+4]//copiem in ebx ptr spre vector
		lea edi,[ebx+2*ecx]
		mov ebx,[edi+4*esi]//luam elementul din vectorul m
		lea edi,[edx+4*ecx]
		mov [edi+4*esi],ebx//si completam in vectorul final
		inc esi
		jmp while_2
		jmp exit_
copiaza_v1:
		shl ecx,1
		xor esi,esi//offset in vect din param
while_3:
		mov ebx,[ebp+8]
		add esi,ecx
		cmp esi,eax
		jae  exit_
		sub esi,ecx
		mov ebx,[ebx+4]//copiem in ebx ptr spre vector
		lea edi,[ebx+2*ecx]
		mov ebx,[edi+4*esi]//luam elementul din vectorul n
		lea edi,[edx+4*ecx]
		mov [edi+4*esi],ebx//si completam in vectorul final
		inc esi
		jmp while_3
		jmp exit_
next_:
		inc ecx
		jmp while_
exit_:
	}
}

void main()
{
	Vector v1;
	Vector v2;

	v1.nr = 2;
	v1.v = (int*) new int[2];
	v1.v[0] = 1;
	v1.v[1] = 2;
	
	v2.nr = 5;
	v2.v = (int*) new int[5];
	v2.v[0] = 3;
	v2.v[1] = 4;
	v2.v[2] = 5;
	v2.v[3] = 6;
	v2.v[4] = 7;

	Vector r1v = interclaseaza_v(v1,v2);
	Vector r2v = interclaseaza_v(v2,v1);

	for (int i=0;i<r1v.nr;i++)
		printf(" %d ",*(r1v.v+i));
	printf("\n");
	for (int i=0;i<r2v.nr;i++)
		printf(" %d ",*(r2v.v+i));
}