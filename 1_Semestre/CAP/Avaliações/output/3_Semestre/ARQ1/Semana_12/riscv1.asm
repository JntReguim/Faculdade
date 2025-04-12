.text

main:

	addi t0, t0, 1
	addi t1, t1, 7
	addi t2, t2, 12
	sub t3, t0, t0		# t3 = 0
	sub t4, t2, t1		# t4 = 5
	
BLT: 
	blt t2, t4, EXIT	# t2 < t4 ?
	
INCREMENTA:
	addi t4, t4, 1		# t1 ++
	slli t0, t0, 2		# shift a esquerda em 2 (Multiplica por 4)
	
BGE: 
	bge t2, t4, INCREMENTA	# t2 >= t4?
	
EXIT:
	xor t0, t0, t0		# t0 = 0
