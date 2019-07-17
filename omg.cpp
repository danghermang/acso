‪#‎include‬ "stdafx.h"
#include <stdio.h>
#include<iostream>
using namespace std;
int IndiceLiniiNumerePrime(int *,int dim)
{
_asm{
mov edi,[ebp+8]
xor ecx,ecx
xor eax,eax
fori:
cmp ecx,dim
jge outi
xor edx,edx
xor esi,esi
forj:
cmp esi,dim
jge outj
push eax
push edi
push ecx
push edx
mov eax,ecx
mov ebx,dim
mul ebx
add eax,esi
mov ebx,4
mul ebx
mov ebx,[edi+eax]
mov eax,ebx
shr eax,1
mov ecx,1
cmp ebx,1
jle lala
jmp lafor
lala:
mov ecx,0
lafor:
mov edi,2
while1:
cmp edi,eax
jge _out
push eax
mov edx,0
mov eax,ebx
div edi
pop eax
cmp edx,0
je bad
jmp _next
bad:
mov ecx,0
_next:
inc edi
jmp while1
_out:
cmp ecx,1
pop edx
pop ecx
pop edi
pop eax
je suma
jmp urm
suma:
add edx,ebx
urm:
inc esi
jmp forj
outj:
cmp edx,eax
jg schimb
jmp peste
schimb:
mov eax,edx
peste:
inc ecx
jmp fori
outi:
xor ecx,ecx
whilei:
cmp ecx,dim
jge endi
xor esi,esi
xor edx,edx
whilej:
cmp esi,dim
jge endj
push eax
push edi
push ecx
push edx
mov eax,ecx
mov ebx,dim
mul ebx
add eax,esi
mov ebx,4
mul ebx
mov ebx,[edi+eax]
mov eax,ebx
shr eax,1
mov ecx,1
cmp ebx,1
jle lele
jmp infor
lele:
mov ecx,0
infor:
mov edi,2
whileprime:
cmp edi,eax
jge _outprime
push eax
mov edx,0
mov eax,ebx
div edi
pop eax
cmp edx,0
je notprime
jmp _urmat
notprime:
mov ecx,0
_urmat:
inc edi
jmp whileprime
_outprime:
cmp ecx,1
pop edx
pop ecx
pop edi
pop eax
je adunare
jmp urmeaza
adunare:
add edx,ebx
urmeaza:
inc esi
jmp whilej
endj:
cmp edx,eax
je verif
jmp salt
verif:
mov eax,ecx
jmp endi
salt:
inc ecx
jmp whilei
endi:
}
}
int main()
{
int a[5][5],i,j;
for(i=0;i<5;i++)
for(j=0;j<5;j++)
{
cout<<"a["<<i<<"]["<<j<<"]=";
cin>>a[i][j];
}
int *p=a[0];
_asm{
push 5
push p
call IndiceLiniiNumerePrime
add esp,8
mov i,eax
}
cout<<"Indicele="<<i<<endl;
}