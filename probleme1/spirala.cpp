#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void afisare (int *, int, int *)
{
	_asm
	{
		mov ebx, [ebp+8] ;// pointer catre matrice
		mov ecx, [ebp+16] ;//pointer catre vector
		mov edx, 0 ;//contor pt vector
		mov edi, 0 ;// k
		mov esi, 0 ;// i
		
		mov eax, [ebp+12]
		sar eax, 1

for_k:
		cmp edi, eax
		je exit_k

		mov esi, edi ;// i=k
for_i:
		push eax
		mov eax, [ebp+12]
		sub eax, edi ;// n=n-k
		cmp esi, eax
		pop eax
		je nexti

		;// else

		push eax
		push edx
		mov eax, [ebp+12] ;//cream a[k][i]
		mul edi
		add eax, esi
		pop edx

		push edi
		mov edi, [ebx+4*eax] ;//salvam a[k][i]
		mov [ecx+4*edx], edi ;//b[s]=a[k][i]
		pop edi
		pop eax
		inc edx

		inc esi ;//i++
		jmp for_i

for_ii:
		push eax
		mov eax, [ebp+12]
		sub eax, edi 
		sub eax, 1	;// n=n-k-1
		cmp esi, eax
		pop eax
		je nextii

		;// else

		push eax
		push edx
		mov eax, [ebp+12] ;//cream a[k][i]
		mul esi
		sub eax,edi
		sub eax,1
		add eax, [ebp+12]
		pop edx

		push edi
		mov edi, [ebx+4*eax] ;//salvam a[k][i]
		mov [ecx+4*edx], edi ;//b[s]=a[k][i]
		pop edi
		pop eax
		inc edx

		inc esi ;//i++
		jmp for_ii

for_iii:
		push eax
		cmp esi, edi
		pop eax
		jl nextiii

		;// else

		push eax
		push edx
		mov eax, [ebp+12] ;//cream a[k][i]
		sub eax, edi
		sub eax, 1
		mul [ebp+12]
		add eax, esi
		pop edx

		push edi
		mov edi, [ebx+4*eax] ;//salvam a[k][i]
		mov [ecx+4*edx], edi ;//b[s]=a[k][i]
		pop edi
		pop eax
		inc edx

		dec esi ;//i--
		jmp for_iii

for_iiii:
		push eax
		cmp esi, edi
		pop eax
		je exit_i

		;// else

		push eax
		push edx
		mov eax, esi ;//cream a[k][i]
		mul [ebp+12]
		add eax, edi
		pop edx

		push edi
		mov edi, [ebx+4*eax] ;//salvam a[k][i]
		mov [ecx+4*edx], edi ;//b[s]=a[k][i]
		pop edi
		pop eax
		inc edx

		dec esi ;//i--
		jmp for_iiii


nexti:
		mov esi,edi
		add esi,1
		jmp for_ii

nextii:
		mov esi,[EBP+12]
		sub esi,1
		sub esi,edi
		jmp for_iii

nextiii:
		mov esi,[EBP+12]
		sub esi,2
		sub esi,edi
		jmp for_iiii

exit_i:
		inc edi ;//k++
		jmp for_k

exit_k:

	}
}

int main()
{
	int a[8][8]={1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,9,9,3,4,5,6,7,8,1,8,2,6,7,8,8,9,2,7,1,5,1,9,9,1,3,6,9,4,3,2,1,2,4,5,8,7,6,5,4,3,5,4,3,2,1,9,8,7,6};
	int b[100];
	int n=8;
	int *p=a[0];
	int *q=b;
	//afisare(a, n, b); 
	
	_asm
	{
	push q
	push n
	push p
	call afisare
	add esp, 12
	}

	for (int i=0;i<64;i++)
		 cout<<b[i]<<" ";

	return 0;
}