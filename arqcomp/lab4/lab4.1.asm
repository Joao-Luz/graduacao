.data
Zero.s:     .word 0x00000000
PlusInf.s:  .word 0x7F800000
MinusInf.s: .word 0xFF800000
PlusNaN.s:  .word 0x7F800020
MinusNaN.s: .word 0xFF800002

Zero.d:     .word 0x00000000 0x00000000
PlusInf.d:  .word 0x00000000 0x7FF00000
MinusInf.d: .word 0x00000000 0xFFF00000
PlusNaN.d:  .word 0x00000020 0x7FF00000
MinusNaN.d: .word 0x00000002 0xFFF00000

.text
main:

# Single values

lwc1 $f0, Zero.s
mov.s $f12, $f0
jal PrintFloat

lwc1 $f1, PlusInf.s
mov.s $f12, $f1
jal PrintFloat

lwc1 $f2, MinusInf.s
mov.s $f12, $f2
jal PrintFloat

lwc1 $f3, PlusNaN.s
mov.s $f12, $f3
jal PrintFloat

lwc1 $f4, MinusNaN.s
mov.s $f12, $f4
jal PrintFloat

# Double values

li $a0, '\n'
li $v0, 11
syscall

lwc1 $f6, Zero.d
lwc1 $f7, Zero.d+4
mov.d $f12, $f6
jal PrintDouble

lwc1 $f8, PlusInf.d
lwc1 $f9, PlusInf.d+4
mov.d $f12, $f8
jal PrintDouble

lwc1 $f10, MinusInf.d
lwc1 $f11, MinusInf.d+4
mov.d $f12, $f10
jal PrintDouble

lwc1 $f14, PlusNaN.d
lwc1 $f15, PlusNaN.d+4
mov.d $f12, $f14
jal PrintDouble

lwc1 $f16, MinusNaN.d
lwc1 $f17, MinusNaN.d+4
mov.d $f12, $f16
jal PrintDouble

j Exit

	PrintFloat:
	li $v0, 2
	syscall
	li $a0, '\n'
	li $v0, 11
	syscall
	jr $ra
	
	PrintDouble:
	li $v0, 3
	syscall
	li $a0, '\n'
	li $v0, 11
	syscall
	jr $ra
	
Exit: