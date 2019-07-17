// examen_assembler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/* functia scrisa in C
int Divizor(int* v,int nr)
{
	int i,j,s;
	for(i=1;i<nr;i++)
	{	
		s=0;
		for(j=0;j<i;j++)
			s=s+v[j];
		if(s%v[i]!=0) return 0;
	}
	return 1;

}
*/
//functia in assembler
int Divizor(int *v,int nr)
{
	_asm
	{
		mov esi,1
		mov ecx,[ebp+8]
startfor1:
		cmp esi,[ebp+12]
		jae exitfor1
		mov eax,0
		mov edx,0
		mov edi,0
startfor2:
		cmp edi,esi
		jae exitfor2
		mov ebx,[ecx+edi*4]
		add eax,ebx
		inc edi
		jmp startfor2
exitfor2:
		mov ebx,[ecx+esi*4]
		div ebx
		cmp edx,0
		jne exit
		inc esi
		jmp startfor1
exitfor1:
		mov eax,1
		jmp exit_f
exit:
		mov eax,0
exit_f:

	}
}




int _tmain(int argc, _TCHAR* argv[])
{
	int v[100],i,nr,x;
	printf("nr=");scanf("%d",&nr);
	for(i=0;i<nr;i++)
	{
		printf("v[%d]=",i);scanf("%d",&v[i]);
	}

	_asm
	{
		push nr
		lea ebx,v
		push ebx
		call Divizor
		add esp,8
		mov x,eax
	}
	
	
	//int x=Divizor(v,nr);
	if(x==1)printf("Este!!! (%d)",x);
	else printf("Nu este!! (%d)",x);
	return 0;
}

