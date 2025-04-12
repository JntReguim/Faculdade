# riscv-busca-maior-funcao.asm
# Funcao para procurar o maior nro em um vetor de 10 nros inteiros, passado por referencia
# Mostra o uso de passagem de parametros por referencia e por valor, valor de retorno, variaveis locais

.data
str1: .string "Maior valor encontrado=  "

.text

# --- main -------------------------------------------------
main:
	addi sp, sp, -48 	# Alocar espaco na pilha para array de 10 posicoes de inteiros, N, maior_encontrado
 	
 	mv a0, sp 		# a0 = endereco de veto: parametro 1 de buscaMaior
 	li t1, 4		# Inicializacao do vetor "valores" armazenado na pilha, como variavel local da funcao main
 	sw t1, 0(sp)
 	li t1, 5
 	sw t1, 4(sp)
 	li t1, 7
 	sw t1, 8(sp)
 	li t1, 12
 	sw t1, 12(sp)
 	li t1, 654
 	sw t1, 16(sp)
 	li t1, 2
 	sw t1, 20(sp)
 	li t1, 78
 	sw t1, 24(sp)
 	li t1, 22
 	sw t1, 28(sp)
 	li t1, 8
 	sw t1, 32(sp)
 	li t1, 16
 	sw t1, 36(sp)
 	
 	
 	li t1, 10  		## Inicialização da variavel  "N", armazenada na pilha, como variavel local da funcao main
 	sw t1, 40(sp)
 	mv a1, t1   		# a1 = parâmetro 2 de buscaMaior
 	
 	li t1, -999  		## Inicializacao da variavel local a main, "maiorEcontrado", armazenada na pilha da funcao main
 	sw t1, 44(sp)
 	
 	jal buscaMaior   	# comando C correspondente: maiorEncontrado= buscaMaior(valores, N);
 	
 	mv t1, a0   		# atualiza na memoria o valor da variavel local "maiorEcontrado", com o valor retornado
 	sw t1, 44(sp)

 	# Imprimir resultados no console  (argumento em a0)
    	jal ra, printResultado
     
 	addi sp, sp, 48 # Desalocar área da pilha usada por main


fimPrograma:
        li a7, 10
        ecall


# --- buscaMaior -------------------------------------------------
# Parametros de entrada: a0: endereco do vetor, a1: tamanho do vetor 
buscaMaior:
	addi sp, sp, -8  	# Alocar espaco na pilha 2 variaveis locais a buscaMaior: maior, i
	
	li t1, -999 		# Var local "maior" - Inicializacao com o -999 
 	sw t1, 0(sp) 		# Armazenar maior na pilha, como variável local de buscaMaior
 	 	
 	li t2, 0  	 	# Var local "i" - Inicializacao com 1 e armazenar na pilha
 	sw t2, 4(sp)
		
for:
	bge t2, a1, fimloop 	# if i >= 10, fim do loop
	slli t3, t2, 2		# t3 = i * 4
	add t4, a0, t3 		# t4= &vetor + i*4
	lw t5, 0(t4) 		# t5 = vetor[i]

	blt t5, t1, proximo 	# se vetor[i] < maior, then proxima interação
	
	mv t1, t5		# se nao, atualizar maior com novo valor encontrado no vetor
	sw t1, 0(sp)  		## atualiza o valor de maior na memoria - Comando C correspondente: maior = vetor[i];

proximo:
	addi t2, t2, 1   	# i= i+1
	sw t2, 4(sp)     	# atualiza o valor de i na memoria - Comando C correspondente: for (i=0; i<tamanho; i++) {
	j for   		# proxima interacao do loop

fimloop:
	
	mv a0, t1  		# Maior valor encontrado retorna em a0

	addi sp, sp, 8  	# Desalocar area da pilha usada por buscaMaior
	
	ret   			# retorna para funcao main


# --- printResultado --------------------------------------
# a0: Contom o valor do maior nro do vetor
printResultado:
        mv t0, a0
       
        la a0, str1
        li a7, 4
        ecall
        
        mv a0, t0
        li a7, 1
        ecall
        
        ret
      
 ## ---- fim de printResultado -----------
