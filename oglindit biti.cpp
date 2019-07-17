#include <stdio.h>

//Sa se scrie codul in limbaj de asamblare care oglindeste bitii  unui numar

void main(){
	unsigned int number;
	number = 140;

	_asm{
		/* Completati */
		mov esi, number
		xor edi, edi
		mov ecx, 0
_loop:
		mov ebx,esi
		mov edx,1
		shl edx,cl
		and ebx,edx

		shr ebx,cl
		ror ebx,1
		shr ebx,cl
		or edi, ebx

		mov ebx,esi
		mov edx, 80000000h
		shr edx,cl
		and ebx,edx
		shl ebx,cl
		rol ebx,1
		shl ebx,cl
		or edi, ebx

		inc ecx
		cmp ecx,15
		ja _done
		jmp  _loop
_done:

		mov number,edi

	}
	if( number != 822083584)
		printf("Failed! Your result is %d\n",number);
	else
		printf("OK!");	
}