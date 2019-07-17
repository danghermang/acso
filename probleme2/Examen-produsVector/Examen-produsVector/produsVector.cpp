#include<iostream>
using namespace std;
int V[100];


int produsVector(int *)
{
	_asm
	{
		mov esi, [ebp+8]
		mov eax, [esi]
		xor ecx,ecx
		xor ebx,ebx

	_while:
			cmp eax,0
			je sfarsitWhile
			inc ecx
			add ebx,eax
			push eax
			add esi,4
			mov eax, [esi]
			jmp _while
		sfarsitWhile:

	mov eax,ebx
	xor edx,edx
	
	div ecx
	mov ebx,eax
	
	mov eax,1
	xor edx,edx

_while2:
		cmp ecx,0
		je sfarsit
		pop esi
		cmp esi,ebx
		ja NU
		mul esi
	NU:	sub ecx,1
		jmp _while2


	sfarsit:

	}
}


int main()
{
	cin >> V[0];
	int i = 1;
	while (V[i - 1] != 0)
	{
		cin >> V[i];
		i++;
	}

	int *p = V;
	cout << produsVector(p) << endl;
	return 0;

}