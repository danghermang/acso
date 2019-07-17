#include<iostream>
//interschimba valorile a doua variabile
using namespace std;
int a, b;

void swap(int* a, int *b)
{

	_asm{
		
		mov eax,ebp
		add eax,8
		mov eax, [eax]
		
		mov ebx, ebp
		add ebx, 12
		mov ebx, [ebx]
		
		mov ecx, [eax]
		mov edx, [ebx]

		mov [eax],edx
		mov [ebx], ecx

	}


}

int main()
{
	cin >> a >> b;
	
	swap(&a, &b);
	
	cout << a << ' ' << b << endl;

}