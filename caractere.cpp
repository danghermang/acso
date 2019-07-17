// modifica "ana are mere" in "Ana Are Mere" 
void modify(char *s)
{
	_asm{
			mov ebx, [ebp+8]
			cmp byte ptr[ebx], 'a'
			jl begin
			cmp byte ptr[ebx], 'z'
			jg begin
			sub byte ptr[ebx], 32
			inc ebx
		begin:
			cmp byte ptr[ebx], 0
			je exit1
			cmp byte ptr[ebx-1], ' '
			je ver2
			cmp byte ptr[ebx-1], ','
			je ver2
			jmp inc_while
		var2: 
			cmp byte ptr[ebx], 'a'
			jl inc_while
			cmp byte ptr[ebx], 'z'
			jg inc_while
			sub byte ptr[ebx], 32
		inc_while:
			inc ebx
			jmp begin
		exit1:

}
}