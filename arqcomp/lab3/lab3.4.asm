.text

# read int a
li $v0, 5
syscall
move $t0, $v0

# read int b
li $v0, 5
syscall
move $t1, $v0

# c = a + b
addu  $t2, $t0, $t1

# print c 
li $v0, 1
move $a0, $t2
syscall

li $v0 11
li $a0, '\n'
syscall

# c = a - b
subu  $t3, $t0, $t1

# print c 
li $v0, 1
move $a0, $t3
syscall
