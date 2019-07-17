#include <iostream>
using namespace std;

#define MAX 30

class Coada{
private:
	int nr;
	int tab[MAX];

public:

	Coada(){
		this->nr = 0;
	}
	
	void Adauga_1(int el){
		if(nr < MAX)
			this->tab[this->nr++] = el;
	}

	void Adauga_2(int el){
		_asm{
			mov eax,[ecx]
			cmp eax,MAX
			jge iesire
			inc eax
			mov [ecx],eax
			mov ebx,[ebp+8]
			mov [ecx + 4*eax],ebx
		iesire:
		}
	}

	void Afisare(){
		for(int i=0;i<this->nr;i++)
			cout<<this->tab[i]<<' ';
		cout << endl;
	}
};

void Adauga_c(Coada& c,int el){
	int nr_elem = *((int*)(&c));
	nr_elem++;

	*((int*)(&c)) = nr_elem;
	*(int*) ((unsigned int)&c + 4*nr_elem) = el;
}

void Adauga_asm(Coada& c,int el){
	
	_asm{
		mov eax,[ebp+8]//pointer spre c
		inc [eax]
		mov ecx,[eax]
		mov ebx,[ebp+12]//el
		mov [eax+ecx*4],ebx
	}
}

void main(){
	Coada c;
	c.Adauga_1(2);
	c.Adauga_2(3);
	Adauga_c(c,4);
	Adauga_asm(c,5);
	c.Afisare();
}