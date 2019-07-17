#include<iostream>
using namespace std;
int V[100], n,nrPasi;


int Roteste(int *, int, int)
{
	_asm
	{
		mov esi, [ebp + 8]
		mov ebx, [ebp + 12]
		mov edi, [ebp + 16] //nr de Pasi

		cmp edi,ebx
		jb OK
		
		mov eax,edi
		mov edx,0
		div ebx
		mov edi,edx

	OK:
		xor ecx, ecx
	_for:
		cmp ecx,ebx
		je sfarsitFor
		push[esi+4*ecx]
		inc ecx
		jmp _for
	sfarsitFor:

		//am pus toate numerele pe sitva
		mov eax,edi
	_while:
		cmp eax,0
		je sfarsitWhile
		pop ecx
		sub eax,1
		mov[esi+4*eax],ecx
		jmp _while

	sfarsitWhile:
		
	mov eax,ebx
	sub eax,edi
	sub ebx,1

	_while2:
			cmp eax,0
			je sfarsitWhile2
			pop ecx
			mov[esi+4*ebx],ecx
			sub eax,1
			sub ebx,1
			jmp _while2

	sfarsitWhile2:

	}
}



int main()
{
	cin >> n >> nrPasi;
	for (int i = 0; i < n; i++)
		cin >> V[i];

	cout << endl;
	int *p = V;
	Roteste(p, n, nrPasi);

	for (int i = 0; i < n; i++)
		cout << V[i] << ' ';
	cout << endl;
	return 0;
}