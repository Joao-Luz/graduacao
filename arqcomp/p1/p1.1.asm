.data
count: .word 0x04
veta: 0x2000, 0x1000, 0x0800, 0x0400
vetb: 0x00, 0x00, 0x00, 0x00
msg: .asciiz "Entre com o ultimo digito do seu numero de matricula na Ufes: "

.text
li $v0, 4
la $a0, msg
syscall
li $v0, 5
syscall

move $t3, $v0
la $t0, veta
la $t1, vetb
lw $t2, count
loop:
beq $t2, $zero, exit
lw $t4, ($t0)
sllv $t4, $t4, $t3
sw $t4, ($t1)
addi $t2, $t2, -1
addi $t0, $t0, 4
addi $t1, $t1, 4
j loop

exit:
li $v0, 10
syscall