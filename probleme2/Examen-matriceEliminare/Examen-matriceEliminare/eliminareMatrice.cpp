#include<fstream>
using namespace std;
ifstream fin("in.in");
ofstream fout("out.out");
int M1[5][5], M2[4][4];



void eliminaDinMatrice(int *, int *, int, int, int)
{
	_asm
	{
		mov esi, [ebp + 8];


		mov edi, [ebp + 12];

		mov ebx, [ebp + 16];
		mov ecx, [ebp + 20];

		mov edx, [ebp + 24];
		push edx;

		//mov edx, 0;
		mov eax, ebx;
		mul edx;
		lea ebx, [esi + eax * 4];
		lea ecx, [esi + ecx * 4];

		pop edx;
		push edx;
		mov eax, edx;
		mul edx;
		pop edx;

	_for:
		cmp eax, 0;
		jbe sfarsitFor;

		cmp esi, ebx;
		je sariLinia;
		cmp esi, ecx;
		je sariColoana;
		
		push esi;
		mov esi, [esi];
		mov[edi], esi;
		add edi, 4;
		pop esi;
		add esi,4
		dec eax;
		jmp _for;

	sariLinia:
		lea esi, [esi + edx * 4];
		lea ecx, [ecx + edx * 4];
		sub eax, edx;
		jmp _for;
	sariColoana:
		add esi, 4;
		dec eax;
		lea ecx, [ecx + edx * 4];
		jmp _for;
	sfarsitFor:
	}


}


int main()
{
	int n, i, j;
	fin >> n >> i >> j;
	for (int q = 0; q < n;q++)
	for (int t = 0; t < n; t++)
	{
		fin >> M1[q][t];
	}
	
	int *p1 = M1[0];
	int *p2 = M2[0];

	eliminaDinMatrice(p1, p2, i, j, n);

	for (int q = 0; q < n - 1;q++)
	{
		for (int t = 0; t < n - 1; t++)
			fout << M2[q][t] << ' ';
		fout << endl;
	}

	return 0;


}
