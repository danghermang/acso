#include <iostream>
using namespace std;

class A{
	short a1;
	short a2;
	char a3;

public:
	virtual void afisare(){
		cout<<"A\n";
	}
};

class B: public A{
	char b;

public:
	void afisare(){
		cout<<"B\n";
	}
};

class C:public B{
	int c1;

public:
	virtual void afisare(){
		cout<<"C\n";
	}
};


void main(){
	A a,*pb,*pc;
	B b;
	C c;

	pb = (A*)&b;
	pc = (A*)&c;

	a.afisare();//A
	pb->afisare();//B

	//echivalent asm:
	_asm{
		mov  ecx,pb //pointerul this
		mov  ebx, [ecx] //pointer catre VMT
		call word ptr [ebx]//apelam prima metoda virtuala din VMT
	}
	pc->afisare();//C

	cout<<sizeof(A)<<" "<<sizeof(B)<<" "<<sizeof(C);//se afiseaza 12 16 20. De ce?
}