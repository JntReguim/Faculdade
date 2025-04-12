# riscv-semana2.asm
# Trechos de codigo da aula teorica da semana 2
# Objetivos: 
#    - Entender o funcionamento do computador simplificado
#    - Contato inicial com programacao assembly RISC-V

.data
memDados: .word  0, 1, 25, 3, 4, 5, 6, 7, 8, 9

.text
main:

        ######## PARTE A: - Instrucoes -> adicao e subtracao:
        #Inicializacao de registradores				# addi -> soma um registrador com uma constante
        addi t1, zero, 0	# t1 = zero + 0 = 0
        addi t2, zero, 5 	# t2 = zero + 5 = 5
        addi t3, zero, 36	# t3 = zero + 36 = 36
        addi t4, zero, 4	# t4 = zero + 4 = 4
       
        add t1, t2, t3		# t1 = t2 + t3 = 5 + 36 = 41
        sub t1, t2, t3		# t1 = t2 - t3 = 5 - 36 = -31
       
        add t1, t2, t3		# t1 = t2 + t3 = 5 + 36 = 41  
        sub t1, t1, t4		# t1 = t1 - t4 = 41 - 4 = 37
       
       
        ######## PARTE B: - Instrucoes -> multiplicacao e divisao
        #Inicializacao de registradores
        addi s1, zero, 100	# s1 = zero + 100 = 100		0110 0100
        addi s2, zero, 60 	# s2 = zero + 60 = 60		0011 1100
        addi s3, zero, 20	# s3 = zero + 20 = 20		0001 0100
        addi s4, zero, 15	# s4 = zero + 15 = 15		0000 1111
       
        # Instrucoes multiplicacao / divisao
       
        # s1 * s2 = 100 * 60 = 600
        mul s3, s1, s2		# s3 = s1 * s2 = 6000	-> s3 recebe os 32 bits menos significativos da multiplicacao entre s1 e s2	0000 0000 0000 0000 0001 0111 0111 0000
        mulh s4, s1, s2 	# s4 = s1 * s2 = 6000	-> s4 recebe os 32 bits mais significativos da multiplicacao entre s1 e s2	0000 0000 0000 0000 0000 0000 0000 0000
       				# {s4, s3} = s1 * s2 	-> a multiplicacao de s1 e s2 fica armazenada na concatenacao de s4 e s3
       
        div  s3, s1, s2  	# s3 = s1 / s2 = 100 / 60 = 1		-> divisao interia entre s1 e s2
        rem  s4, s1, s2  	# s4 = s1 % s2 = 100 % 60 = 40		-> resto da divisao entre s1 e s2


        ######## PARTE C: - Instrucoes Logicas (and, or, xor)
        #		  - Todas as intrucoes abaixo possuem versao com imediato (i)	
        	
	addi t1, zero, 0	# t1 = zero + 0 = 0
	addi t2, zero, 5	# t2 = zero + 5 = 5
	addi t3, zero, 7	# t3 = zero + 7 = 7
	
	and t1, t2, t3		# t1 = t2 && t3 = 5 && 7 = 0101 && 0111 = 0101 = 5
	or t1, t2, t3		# t1 = t2 || t3 = 5 || 7 = 0101 || 0111 = 0111 = 7
	xor t1, t2, t3		# t1 = t2 ^^ t3 = 5 ^^ 7 = 0101 ^^ 0111 = 0010 = 2
	
	######## Extra: - Instrucoes shift logico e aritmetico
	addi t1, zero, 0	# t1 = zero + 0 = 0
	addi t2, zero, 5	# t2 = zero + 5 = 5
	addi t3, zero, 7	# t3 = zero + 7 = 7
	
	# A quantidade de deslocamento esta nos 5 bits menos significativos de um registrador.
	sll t1, t2, t3		# t1 = t2 << t3		0000 = 0101 << 0111 = 010 1000 0000
	srl t1, t2, t3		# t1 = t2 >> t3		0000 = 0101 >> 0111 = 0000
	sra t1, t2, t3		# t1 = t2 >>> t3	0000 = 0101 >>> 0111 = 0000
	
	######## PARTE D: - Instrucoes de acesso a  memoria (lw, sw) -> l = load e s = store
	la t1, memDados		# la: instrucao para armazenar em t1 o endereso de um dado na memoria de dados. 
				# No caso memDados eh um vetor, logo t1 armazena o endereco do primeiro indice				
	lw s3, 8(t1)		# lw: instrucao que armazena o valor presentre no enderco de 8(t1) -> (8 + t1), que é o terceiro elemento de memDados 	        (Quase um print)

	addi t0, zero, 0 	# t0 = zero + 0 = 0
	sw s3, 0(t1)		# Escreve o valor de s3 no endereco t1 + 0, ou seja, primeiro elemento do vetor memDados	
	lw t0, 0(t1)		# Le o valor do endereco t1 + 0, ou seja, primeiro elemento do vetor memDados, e insere em t0
	
	
	######## PARTE E: - Programacao: desvio condicional (if-then, if-then-else)
	addi s0, zero, 0	# s0 = zero + 0 = 0
	addi s1, zero, 4	# s1 = zero + 4 = 4
	addi s2, zero, 4	# s2 = zero + 4 = 4
	
	beq s1, s2, target1	# Se s1 == s2, entao va para target1, caso contrario segue sequencialmente normalmente
	addi s0, zero, 1	# s0 = zero + 1 = 1
	
target1:
	addi s0, zero, 2	# s0 = zero + 2 = 2
done1:
	bne s1, s2, target2	# Se s1 != s2, entao va para target2, caso contrario segue sequencialmente normalmente
	addi s0, zero, 3	# s0 = zero + 3 = 3
	j done2
	
target2:
	addi s0, zero, 4	# s0 = zero + 4 = 4
done2:

	######## PARTE F: - Programacao: loops (for, while)
	
# // determines the power
# // of x such that 2x = 128
# int pow = 1;
# int x = 0;
# while (pow != 128) {
#     pow = pow * 2;
#     x = x + 1;
#}
	addi s0, zero, 1	# s0 = zero + 1 = 1
	add s1, zero, zero	# s1 = zero + zero = 0
	addi t0, zero, 128	# t0 = zero + 128 = 128
	
while:
	beq s0, t0, done3	# O assembly testa o caso oposto ( pow != 128), no codigo de alto nivel seria (pow == 128).
	slli s0, s0, 1		# s0 = s0 << 1
	addi s1, s1, 1		# s1 = s1 + 1	// x = x + 1 -> incrementa
	j while
done3:

# // add the numbers from 0 to 9
# int sum = 0;
# int i;
# for (i=0; i!=10; i = i+1) {
#    sum = sum + i;
#}
	addi s0, zero, 0	# s0 = zero + 0 = 0
	add s1, zero, zero	# s1 = zero + zero = 0
	addi t0, zero, 10	# t0 = zero + 10 = 10
	
for:
	beq s0, t0, done4	# Se s0 == t0 vai para done4, caso contrario siga
	add s0, s0, s1		# s0 = s0 + s1
	addi s1, s1, 1		# s1 = s1 + 1  		(x = x + 1) incrementa 1
	j for
done4:


        # Exit program
        li a7, 10
        ecall
