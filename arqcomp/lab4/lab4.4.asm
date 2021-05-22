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
mtc1 $t0, $f0
cvt.s.w $f0, $f0
lwc1 $f1, f1
lwc1 $f2, f1
jal FactorialSingle

# print int
li $v0, 1
cvt.w.s $f0, $f2
mfc1 $a0, $f0
syscall

li $v0, 11
li $a0, ' '
syscall

#print float
li $v0, 2
mov.s $f12, $f2
syscall

li $v0, 11
li $a0, '\n'
syscall

j main

FactorialSingle:
c.le.s $f0, $f1
bc1t return
mul.s $f2, $f2, $f0
sub.s $f0, $f0, $f1
j FactorialSingle
return:
jr $ra

Exit:



 
