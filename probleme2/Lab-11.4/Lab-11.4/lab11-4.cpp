#include<iostream>
using namespace std;
int Matrice[10][10];

void creeaza(int *)
{
	_asm
	{

		mov esi, [ebp+8]
		mov ecx,0



	_for:
			mov ebx, [esi] //verificare
			mov dword ptr[esi],111
			add esi,44
			inc ecx
			cmp ecx,10
			jb _for
	}


}


void afiseaza(int Matrice[][10])
{
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
			cout << Matrice[i][j] << ' ';
		cout << endl;
	}
}

int main()
{
	
	int *p = Matrice[0];
	creeaza(p);

	afiseaza(Matrice);
	return 0;
}