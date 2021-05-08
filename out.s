.globl f
f:
addi $sp,$sp,-8
sw $fp,4($sp)
move $fp,$sp
li $2,11
move $sp,$fp
lw $fp,4($sp)
addiu $sp,$sp,8
jr $31
nop

addi $sp,$sp,0
move $fp,$sp
addi $sp,$sp,8
move $fp,$sp
