#void reincializaVetor(int vetor[], int tamanho, int novoValor){
#// 1 variável local:  i.
#   int i;
    
#   for (i=0; i<tamanho; i++) {
#      vetor[i]= novoValor;
#   }
#}

#int buscaMaior(int vetor[], int tamanho){
#   // 2 variáveis locais: maior, i.
#   int maior = -999;
#   int i;
    
#   for (i=0; i<tamanho; i++) {
#      if (vetor[i] > maior){
#         maior = vetor[i];
#      }
#   }
    
#   reincializaVetor(vetor, tamanho, maior);
    
#   return maior;
#}

#int main(){
#// 3 variáveis locais: valores (10 words), N, maiorEncontrado 
#   int valores[10]= {4, 5, 7, 12, 654, 2, 78, 22, 8, 16};
#   int N=10;
#   int maiorEncontrado;
#   int i;
    
#   maiorEncontrado= buscaMaior(valores, N);
    
#   printf("Maior valor encontrado=  %d \n", maiorEncontrado);
    
#   for (i=0; i<N; i++){
#      printf("%d  ", valores[i]);
#   }
#}

.data
string2: .string "NovoVetor: "
string3: .string " "
string4: .string "\n"

.text
main:
	addi sp, sp, -48		# Alocar espaco na stack para array de 10 posicoes de inteiros, N, num_maior
	
	mv t0, sp			# a0 = &sp 
	li t1, 4			# Inicializacao do vetor "valores" armazenado na pilha, como variavel local da funcao main
 	sw t1, 0(sp)			# 1 elemento
 	li t1, 5
 	sw t1, 4(sp)			# 2 elemento
 	li t1, 7
 	sw t1, 8(sp)			# 3 elemento
 	li t1, 12
 	sw t1, 12(sp)			# 4 elemento
 	li t1, 654
 	sw t1, 16(sp)			# 5 elemento
 	li t1, 2
 	sw t1, 20(sp)			# 6 elemento
 	li t1, 78
 	sw t1, 24(sp)			# 7 elemento
 	li t1, 22
 	sw t1, 28(sp)			# 8 elemento
 	li t1, 8
 	sw t1, 32(sp)			# 9 elemento
 	li t1, 16
 	sw t1, 36(sp)			# 10 elemento

	li t1, 10			# Inicializacao da variavel  "N", armazenada na pilha, como variavel local da funcao main
	sw t1, 40(sp)
	mv a1, t1			# a1 recebe valor de t1, ou seja, 10

	li t1, -999			# Espaco de num_maior
	sw t1, 44(sp)			# Inicializacao da variavel "num_maior" aramazenada na pilha, como variavel local da funcao main
	
	jal busca_maior			# Chama funcao busca_maior
	
	sw a3, 44(sp)			# Atualiza num_maior na pilha
	
	jal print_vetor			# Chama funcao print_vetor
	
	# Fim, termine deslocando a pilha
	addi sp, sp, 48			# Desaloca memoria da pilha
	
fimDoPrograma:
	li a7, 10
	ecall
	
# Funcao busca maior
busca_maior:
	addi sp, sp, -8			# Aloca duas posicao na stack
	mv a0, t0
	
	li t1, -999			# Espaco para num_maior
	sw t1, 0(sp)
	
	li a2, 0			# i = 0
	sw a2, 4(sp)

for:
	bge a2, a1, fimloop		# Se a2 >= a1 va para fim loop, caso oposto, siga
	slli s0, a2, 2			# i * 4
	add s1, a0, s0			# s1 = &V + i * 4
	lw s2, 0(s1)			# s2 = V[i]
	
	blt s2, t1, next		# s2 < t1 	V[i] < V[0]
	
	mv t1, s2			# Insere maior valor em t1
	sw t1, 0(sp) 
	
next:
	addi a2, a2, 1			# i++
	sw a2, 4(sp)			# Atualiza o valor de i na pilha
	j for

fimloop:
	addi sp, sp, 8			# Desaloca memoria
	
	mv a3, t1			# Move num_maior para a3
	
	mv s7, ra
	jal new_vetor
	mv ra, s7
	ret

# Funcao que reescreve vetor com o num_maior
new_vetor: 
	addi sp, sp, -4			# Aloca uma posicao na stack
	mv a0, t0
	
	li, a2, 0			# i = 0
	sw a2, 0(sp)
				
for1:
	bge a2, a1, fimloop1		# Se a2 >= a1, va para fimloop1, caso oposto siga
	slli s0, a2, 2			# i * 4
	add s1, a0, s0			# s1 = &V + i * 4
	
	sw a3, 0(s1)			# V[i] = num_maior

next1:	
	addi a2, a2, 1			# i++
	sw a2, 0(sp)			# Atualiza o valor de i na pilha
	j for1

fimloop1:
	ret

# Funcao que imprime vetor
print_vetor:
	addi sp, sp, -4			# Aloca uma posicao na stack
	
	li, a2, 0			# i = 0
	sw a2, 0(sp)
	
	la a0, string2			# Chamada de sistema para impressao de string
	li a7, 4
	ecall
	
	mv a0, t0
	
for2:
	bge a2, a1, fimloop2		# Se a2 >= a1, va para fimloop1, caso oposto siga
	slli s0, a2, 2			# i * 4
	add s1, a0, s0			# s1 = &V + i * 4
	lw s2, 0(s1)			# s2 = V[i]
	
	mv a0, s2			# Chamada de sistemas para impressao de inteiro
	li a7, 1
	ecall
	
	la a0, string3			# Chamada de sistema para impressao de string
	li a7, 4
	ecall
	
	mv a0, t0
	
next2:
	addi a2, a2, 1			# i++
	sw a2, 0(sp)			# Atualiza o valor de i na pilha
	j for2
	
fimloop2:
	ret
