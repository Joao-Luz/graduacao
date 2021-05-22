.data
dim: .word 2
a: .float 0.212 -1.122
b: .float -2.221 3.212
r: .float 0.0 0.0

.text
li $t0, 0
lw $t4, dim
    
loop:
beq $t0, $t4, exit  # dim iterações ? exit : continue
mul $t1, $t0, 4     # $t1 <- $t0 * 4
l.s $f1, a($t1)     # $f1 <- a[$t1]
l.s $f2, b($t1)     # $f2 <- b[$t1]
add.s $f3, $f1, $f2 # $f3 <- $f1 + $f2
s.s $f3, r($t1)     # $f3 -> r[$t1] 
addi $t0, $t0, 1    # t0 <- $t0 + 1
j loop

exit:
li $v0, 10
syscall