.text

main:
	addi t0, t0, 2
	addi t1, t1, 7
	addi t2, t2, 12
	add t3, t0, t1
	sub t4, t2, t1

L1:
	xor t5, t4, t4
	slli t0, t0, 2
	
BEQ:
	and s0, t0, t1
	or s1, t2, t1
	slli t0, t0, 2
	beq t2, t5, L1
	
	
	
	
	
	
	