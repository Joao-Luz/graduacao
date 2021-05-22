.text

Main:
# read int a
li $v0, 5
syscall
move $t0, $v0

# read int b
li $v0, 5
syscall
move $t1, $v0

# c = a / b
mult $t0, $t1

# print hi
mfhi $a0
li $v0, 34
syscall

# print line break
li $v0 11
li $a0, '\n'
syscall

# print lo
mflo $a0
li $v0, 34
syscall

# print line break
li $v0 11
li $a0, '\n'
syscall

j Main
