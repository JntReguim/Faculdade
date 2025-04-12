# riscv-inst-imm.asm
# Instruçoes para gerar código de máquina ref/ instruções que usam campo imediato
#

.data

var1: .word 25
var2: .word 37
var3: .word 86
var4: .word -1


.text

la t2, var2
lw t1, -4(t2)    #Tipo I
lw t3, 4(t2)

add t4, t1, t3

addi t4, t4, 2  #Tipo I
#addi t4, t4, -111  #Tipo I

sw t4, 8(t2)   #Tipo S

beq t4, zero, fimPrograma   #Tipo B


jal printResult

j fimPrograma


printResult:

li a7,1
mv a0, t4
ecall
ret




fimPrograma:
        li a7, 10
        ecall











