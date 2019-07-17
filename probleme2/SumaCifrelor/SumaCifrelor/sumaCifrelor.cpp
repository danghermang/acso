#include<iostream>
using namespace std;
int x, S;


int sumaCifrelor(int numar)
{
	_asm{

		

		mov esi,10
		mov eax,numar
		mov edi,0
	A:  	
		mov edx,0
		div esi
		add edi,edx
		cmp eax,0
		jbe sfarsit
		ja A
	
	sfarsit: 
		mov eax,edi


	}

}

int main()
{
	cin >> x;
	cout << sumaCifrelor(x)<<endl;
	return 0;
}