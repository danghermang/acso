// ExamenASM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int sumacifre2(int x)
{
	int s=0;
	if(x<10)
		return x;
	while(x!=0)
	{
		s+=x%10;
		x/=10;
		if(x==0)
		{
			x=s;
			s=0;
			if(x<10)
				return x;
		}
	}
}

int sumacifre(int x)
{
	int s=0;
	__asm{
	mov eax,x
	mov s,eax
	cmp x,10
	jle finish
	mov s,0
start:
	mov eax,x
	mov bx,10
	mov edx,0
	div bx
	add s,edx
	mov x,eax
	cmp x,0
	je chg
	jmp start
chg:
	mov edx,s
	mov x,edx
	mov s,edx
	cmp x,10
	jl finish
	mov s,0
	jmp start
finish:
	mov eax,s
}
}


int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	short n=10;
	cin>>x;
	__asm{
	mov eax,x
		push eax
		call sumacifre
		mov x,eax
		pop eax
	}
	cout<<"\nSuma="<<x;
	return 0;
}

