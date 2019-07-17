// SUMA ELEMENTELOR PARE DINTR-UN VECTOR
#include<iostream>
using namespace std;
int V[10] = { 0, 2, 4, 1, 3, 5, 6, 6, 6, -2 };


int sumaVector(int*)
{
	_asm{

			mov ecx, 0 //contorul forului
			mov esi, [ebp + 8] //cu asta parcurg
			xor ebx, ebx

		_for :

				mov eax, [esi]
				test eax, 1
				jnz IMPAR
				add ebx, eax
		IMPAR :
				add esi, 4
				inc ecx
				cmp ecx, 9
				jbe _for

				mov eax, ebx
	}
}
int main()
{
	int *p = V;
	cout << sumaVector(p)<<endl;
	return 0;


}