#include<iostream>
using namespace std;
int numar, oglindit;
int main()
{
	cin >> numar;
	_asm{
		mov eax,numar
		mov ebx,0
		mov esi,eax
	catTimp:

		mov eax,esi
		and eax,1
		shl ebx, 1
		or ebx,eax
		shr esi,1
		
		cmp esi,0
		ja catTimp

		mov oglindit,ebx
	}

	cout <<endl<< oglindit << ' ';


}