//TEMA DE VACANTA
#include<iostream>
using namespace std;


int catiBitiDeUnuAre(int)
{

	_asm
	{
		mov eax, [ebp+8]
		xor ecx,ecx

	_while:

		test eax, 1
		jz NU
		inc ecx
	NU:
		shr eax,1
		cmp eax,0
		ja _while

	mov eax,ecx
	}

}

int estePrim(int)
{
	_asm
	{
		mov eax, [ebp+8]
		mov esi,1 //0-nu e prim 1-e prim
		mov edi, eax
		
		cmp eax,1
		je sfarsit
		cmp eax,2
		je sfarsit

		mov ecx,2
	_while:
			xor edx,edx
			mov eax,edi

			div ecx
			
			cmp edx,0
			jne BUN
			mov esi,0
		BUN:
			cmp esi,0
			je sfarsit
			inc ecx
			cmp ecx,edi
			jb _while
			
		
	
	sfarsit:
		mov eax,esi
	}



}

int estePalindrom(int)
{
	_asm
	{
		mov eax, [ebp+8]
		xor ebx,ebx
		mov esi,10
		push eax
	
	_while:
			
		xor edx,edx
		div esi


		push eax
		push edx
		mov eax,ebx
		mul esi
		mov ebx,eax
		pop edx
		pop eax
		add ebx, edx

		cmp eax,0
		ja _while


		pop eax
		cmp eax,ebx
		je EGALE
		mov eax,0
		jmp sfarsit
	EGALE:
			mov eax,1
	sfarsit:
	}
}

int numerePutere2(int *, int)
{
	_asm
	{
		mov esi, [ebp + 8]
		mov ecx, [ebp + 12]
		xor edi,edi
	_for:
			mov eax, [esi]
			push ecx
			push eax
			call catiBitiDeUnuAre
			pop ecx
			pop ecx
			cmp eax,1
			jne NuEPutere
			inc edi
		NuEPutere:
			sub ecx,1
			add esi,4
			cmp ecx,0
			ja _for

	mov eax,edi
			
	}
}

int progresieAritmetica(int *, int)
{
	_asm
	{
		mov esi, [ebp+8]
		mov ebx, [esi+4]
		mov edi, [esi]
		sub ebx,edi  //in ebx am ratia
		
		mov edi, [esi+4]
		mov ecx, [ebp+12]
		sub ecx,2
		add esi,8
		
	_for: cmp ecx,0
		  je forEnd
		  mov eax, [esi]
		  push eax
		  sub eax,edi
		  pop edi
		  cmp eax,ebx
		  jne NU
		  add esi,4
		  sub ecx,1
		  jmp _for
	  forEND:
		mov eax,1
		jmp sfarsit
	NU:	mov eax,0
	
	sfarsit:
	
	}

}

int toUpper(char *)
{
	_asm
	{
		mov esi, [ebp+8]
		mov eax,0
		mov al, [esi]
	_while:
			cmp al,0
			je sfarsitWhile
			cmp al,97
			jb NU
			cmp al,122
			ja NU
			sub al,32
			mov[esi],al
		NU:
			add esi,1
			mov al, [esi]
			jmp _while


	sfarsitWhile:

	}

}

int nrCuvinte(char *)
{
	_asm
	{
		mov esi, [ebp+8]
		mov eax,0
		mov al, [esi]
		xor ecx,ecx

	_while:
			cmp al,0
			je sfarsitWhile
			cmp al,32
			je separator
			cmp al,44
			je separator
			cmp al,46
			je separator
		inapoi:
			mov al, [esi + 1]
			inc esi
			jmp _while



	separator:
			
			mov ah, [esi-1]
			cmp ah,32
			je NU
			cmp ah,44
			je NU
			cmp ah,46
			je NU

			

			inc ecx
			jmp inapoi
	
		NU:
			jmp inapoi

	sfarsitWhile:
			
			mov al, [esi-1]
			cmp al,32
			je sfarsit
			cmp al,44
			je sfarsit
			cmp al,46
			je sfarsit
			inc ecx


		sfarsit:
			mov eax,ecx

	}



}

int main()
{
	int numar;
	//cin >> numar;
	int V[] = { 9, 9, 9, 9 ,9};
	int *p = V;
	//cout << catiBitiDeUnuAre(numar) << endl;
	//if (estePrim(numar) == 1) cout << "ESTE PRIM\n"; else cout << "NU ESTE PRIM\n";
	//if (estePalindrom(numar) == 1) cout << "ESTE PALINDROM\n"; else cout << "NU ESTE PALINDROM\n";
	int n = 5;

	//cout << numerePutere2(p, n) << endl;
	//cout << (progresieAritmetica(p, n) ? "DA\n" : "NU\n");

	char s[] = "a1.a2..a3...a4, .   . .. .. 5.";
	char* q = s;

	//toUpper(q);
	//cout << s << endl;

	cout << nrCuvinte(q) << endl;
}