#include<iostream>
#include<stdio.h>
using namespace std;
const int n = 10;
long P1,P2,Suma;


void calculeazaSuma()
{
	_asm
	{
		mov esi,n
		shr esi,1
		mov eax,n
		inc eax
		xor edx,edx
		mul esi
		mov P1,edx //partea mai semnificativa
		mov P2,eax //partea mai putin semnificativa
	}
}

long long Putere(int k)
{
	long long p = 1;
	for (int i = 1; i <= k; i++)
		p *= 2;
	return p;
}
int main()
{
	calculeazaSuma();
	long long rezultat = Putere(32)*P1 + P2;
	
	cout << rezultat<<endl;

}

