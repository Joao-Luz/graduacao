.data 
msg: .asciiz "Digite um inteiro maior ou igual a zero!\n"
f1: .float 1.0

.text
main:
li $v0, 5
syscall
move $t0, $v0

bgez $t0, Factorial
li $v0, 4
la $a0, msg
syscall
j main

Factorial:
lwc1 $f2, f1
li $t2, 1

jal FactorialSingle

li $v0, 2
mov.s $f12, $f2
syscall
j main

FactorialSingle:

ble $t0, $t2, return
mtc1 $t0, $f1
cvt.s.w $f0, $f1
mul.s $f2, $f2, $f0
subi $t0, $t0, 1
j FactorialSingle
return:
jr $ra

Exit:



 
