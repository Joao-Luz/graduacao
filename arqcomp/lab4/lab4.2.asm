.data
Zero.s:     .word 0x00000000
PlusInf.s:  .word 0x7F800000
MinusInf.s: .word 0xFF800000
PlusNaN.s:  .word 0x7F800020
MinusNaN.s: .word 0xFF800002
MyNum: .float 11

.text
main:

# Single values

lwc1 $f0, PlusInf.s
lwc1 $f1, PlusNaN.s
lwc1 $f2, MyNum

add.s $f12, $f2, $f0
jal PrintFloat

add.s $f12, $f2, $f1
jal PrintFloat


j Exit

	PrintFloat:
	li $v0, 2
	syscall
	li $a0, '\n'
	li $v0, 11
	syscall
	jr $ra
	
Exit: