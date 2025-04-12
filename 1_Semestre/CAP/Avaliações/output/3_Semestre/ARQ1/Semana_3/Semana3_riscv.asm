# // Vetore declarados como vari�veis globais:
# int VA[10]= {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
# int VB[10]= {0, 100, 200, 300, 400, 500, 600, 700, 800, 900};
# int VC[10]= {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
# int main(){
#	int i;
# 	int N=10;
# 	for (i=0; i<N; i++)
#		VC[i]= VA[i] + VB[i];
#		for (i=0; i<N; i++)
#			printf("VC[%d] = %d \n", i, VC[i]);
# 	return 0;
#}

.data
VA: .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
VB: .word 0, 100, 200, 300, 400, 500, 600, 700, 800, 900
VC: .word -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
N: .word 10
string: .string "Vetor VC: "

.text
main: 
	lw t0, N		# t0 = N = 10
	li t1, 1		# t1 = i = 1
	la s0, VA		# a0 = &VA
	la s1, VB		# a1 = &VB
	la s2, VC		# a2 = &VC
	
for:
	bge t1, t0, fimloop	# Se t1 >= t0 va para fimloop, caso contrario, siga.
	slli s3, t1, 2		# s3 = t1 << 2		s3 = i * 4
	add s4, s3, s0		# s4 recebe endereco de VA[i]
	lw s5, 0(s4)		# s5 = VA[i]
	add s4, s3, s1		# s4 recebe endereco de VB[i]
	lw s6, 0(s4)		# s6 = VB[i]
	add s7, s5, s6		# s7 = s5 + s6			s7 = VA[i] + VB[i]
	add s4, s3, s2		# s4 recebe endereco de VC[i]
	sw s7, 0(s4)		# s7 = VC[i]
	
next:	
	addi t1, t1, 1		# t1 = t1 + 1 		i++
	j for
	
fimloop:

# Chama funcao que imprime o vetor VC
	jal ra, printVetor
	
fimDoPrograma:
	li a7, 10
	ecall
	
# Funcao que imprime o vetor VC
printVetor:
	lw t0, N		# t0 = N = 10
	li t1, 1		# t1 = i = 1
	la s2, VC		# a2 = &VC
	
	la a0, string		# a0 = &string
	li a7, 4		# Chamada para imprimir string
	ecall
	
for1:
	bge t1, t0, fimloop1	# Se t1 >= t0 va para fimloop, caso contrario, siga.
	slli s3, t1, 2		# s3 = t1 << 2		s3 = i * 4
	add s4, s3, s2		# s4 recebe endereco de VC[i]
	lw s7, 0(s4)		# s7 = VC[i]
    	
    	mv a0, s7
    	li a7, 1		# Chamada para imprimir interio
    	ecall
    	
    	li a0, ' '		# a0 = ' '
    	li a7, 11		# Chamada para imprimir caracter
    	ecall 
    	
next1:
	addi t1, t1, 1		# t1 = t1 + 1		i++
	j for1

fimloop1:
	ret
