 int nrImpare(int nr,...){ 
	 _asm{ 
		 xor eax,eax//folosit pentru a returna nr de elemente impare 
		 xor ecx,ecx // contor bucla 
	bucla: 
		 cmp ecx,[ebp+8]//comparam contorul cu nr_param 
		 je iesire 
		 test [ecx*4+ebp+12],1 //luati pe rand ecx,0; ecx=1, s.a.m.d si verificati corectitudinea.
		 jz par 
		 //impar 
		 inc eax 
	par: 
		 inc ecx 
		 jmp bucla
	iesire: 
	 } 
}
//Obs: "test" <=> "and", dar nu modifica registri, seteaza doar flagurile.
