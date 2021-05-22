.data
	msg1: .asciiz "Please enter an integer number: "
	x: .float 1.5674
	
.text
	li $s0, 0x00400000 # save return adress in $16
	L1: li $v0, 4 #system call for print_str
	la $a0, msg1 # address of string to print
	syscall
# now get an integer from the user
	li $v0, 5 # system call for read_int
	syscall # the integer placed in $v0
# do some computation here with the number
	addu $t0, $v0, $0 # move the number in $t0
	sll $t0, $t0, 2 # last digit of your UFES number
# print the result
	li $v0, 1 # system call for print_int
	addu $a0, $t0, $0 # move number to print in $a0
	syscall
	
	l.s $f0, x
	add.s $f2, $f0, $f0
	
# restore now the return address in $ra and return from main
	addu $ra, $0, $s0 # return address back in $31
	jr $ra # return from main

