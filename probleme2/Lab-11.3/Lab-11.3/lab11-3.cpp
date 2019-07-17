#include<iostream>
using namespace std;


int nrVocale(char *)
{
	_asm{

	mov esi, [ebp+8]
	mov ecx,0
	mov ebx,0
	_for:
		
		mov al, [esi]
		cmp al,97
		je VOCALA
		cmp al,101
		je VOCALA
		cmp al,105
		je VOCALA
		cmp al,111
		je VOCALA
		cmp al,112
		je VOCALA

		jmp CONSOANA

	VOCALA:
			  inc ebx
	CONSOANA:
			inc ecx
			add esi,1
			cmp ecx,17
			jbe _for



	mov eax,ebx


	}

}


int main()
{
	char *s = "cate consoana am ?";
	cout << nrVocale(s) << endl;
	return 0;

}
