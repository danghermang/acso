#include <stdio.h>
#define MAX 30

class Stiva{
	short nr;
	int v[MAX];
public:
	Stiva(){
		_asm{
			mov word ptr [ecx],0
		}
	}

	void push(...){
		_asm{
			mov ecx,[ebp+8]//this
			movzx edx,word ptr [ecx]
			cmp edx,MAX
			je exit
			
			mov eax,[ebp+4]
			movzx eax,byte ptr [eax+2]
			shr eax,2
			dec eax
			xor esi,esi//counter
loop_1:
			cmp esi,eax
			jae exit
			mov ebx,[ebp+12+4*esi]
			mov dword ptr [ecx+4+4*edx],ebx
			inc esi
			inc edx
			jmp loop_1
exit:
			mov word ptr [ecx],dx
		}
	}

	int pop(){
		_asm{
			movzx eax,word ptr [ecx]//nr
			test eax,eax
			jz exit
			mov eax,[ecx+4*eax]
			dec word ptr [ecx]
exit:
		}
	}
	static Stiva create(...){
		_asm{
			mov eax,[ebp+8]
			mov ecx,[ebp+4]
			movzx ecx,byte ptr [ecx+2]
			shr ecx,2
			dec ecx
			mov word ptr [eax],cx
loop_1:
			jz exit
			mov ebx,[ebp+8+4*ecx]
			mov [eax+ecx*4],ebx
			dec ecx
			jmp loop_1
exit:
		}
	}

	void afisare(){
		char specif_format[]="%d ";
		_asm{
			xor esi,esi//index 
loop_:
			cmp si, word ptr [ecx]//cmp index,nr
			jae exit
			push ecx// printf modifica ecx
			push [ecx+4+esi*4]//s.v[index]
			lea eax,specif_format
			push eax//"%d "
			call dword ptr printf
			add esp,8//refacem stiva
			pop ecx//backup ecx
			inc si//incrementare index
			jmp loop_//next_item
exit:
		}
	}
};

void main(){
	Stiva s;
	_asm{
		//s = Stiva::create(1,2,3);
		lea eax,s
		push 3
		push 2
		push 1
		push eax
		call Stiva::create
		add esp,16
		//s.push(4,5);
		push 5
		push 4
		push eax
		call Stiva::push
		add esp,12
		//s.pop();
		lea ecx,s
		call Stiva::pop
		call Stiva::afisare
	}
}
