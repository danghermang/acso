#include<iostream>
using namespace std;
//calculeaza 2+2*4+2*4*6+...+2*4*6*..*2n

int n;

int calculeaza(int &)
{
	_asm{
		
		
		mov esi, [ebp+8]
		shl esi,1

		mov ebx,0
		mov edi,1
		mov ecx,0

	catTimp:

		add ecx, 2
		
		mov eax, ecx
		mul  edi     //edi=edi*ecx
		mov edi, eax
		
		add ebx,edi
		
		cmp ecx,esi
		jb catTimp

		mov n,ebx
	}
	return n;
}



int main()
{
	cin >> n;
	int rezultat;
	_asm{
		
		push esp
		push n
		call calculeaza
		mov rezultat, eax
		//pop ebx
		pop eax
		pop esp
	}

	cout << rezultat << endl;
	return 0;
}