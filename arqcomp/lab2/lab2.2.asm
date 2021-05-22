.data 
var1: .word 0x00
var2: .word 0x01
var3: .word 0x02
var4: .word 0x03
primeiro: .ascii "J"
ultimo: .ascii "S"

.text
li $v0, 1 # print int
lw $a0, var1 # print var1
syscall
lw $a0, var2 # print var2
syscall
lw $a0, var3 # print var3
syscall
lw $a0, var4 # print var4
syscall
li $v0, 11 # print char
lb $a0, primeiro # print primeiro
syscall
lb $a0, ultimo # print ultimo
syscall
lw $t1, var1 # load contents of var1 to $t1
lw $t2, var4 # load contents of var4 to $t2
sw $t1, var4 # store contents of $t1(var1) to var4's address
sw $t2, var1 # store contents of $t2(var4) to var1's address
lw $t1, var2 # load contents of var2 to $t1
lw $t2, var3 # load contents of var3 to $t2
sw $t1, var3 # store contents of $t1(var2) to var3's address
sw $t2, var2 # store contents of $t2(var3) to var2's address
li $v0, 1 # print int
lw $a0, var1 # print var1
syscall
lw $a0, var2 # print var2
syscall
lw $a0, var3 # print var3
syscall
lw $a0, var4 # print var4
syscall
li $v0, 11 # print char
lb $a0, primeiro # print primeiro
syscall
lb $a0, ultimo # print ultimo
syscall