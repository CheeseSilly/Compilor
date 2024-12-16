.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
  li $v0, 4
  la $a0, _prompt
  syscall
  li $v0, 5
  syscall
  jr $ra

write:
  li $v0, 1
  syscall
  li $v0, 4
  la $a0, _ret
  syscall
  move $v0, $0
  jr $ra

  li $t0, 7
  sw $t0, 8($gp)
  li $t1, 3
  sw $t1, 9($gp)

multiply:
  move $gp, $sp
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  lw $t0, -4($gp)
  move $t0, $t1
  sw $t0, -4($gp)
  lw $t2, -8($gp)
  move $t2, $t3
  sw $t2, -8($gp)
  lw $t4, -12($gp)
  li $t4, 0
  sw $t4, -12($gp)
  lw $t5, -16($gp)
  lw $t6, -12($gp)
  move $t5, $t6
  sw $t5, -16($gp)
label1:
  lw $t7, -20($gp)
  li $t7, 0
  sw $t7, -20($gp)
  lw $s0, -8($gp)
  lw $s1, -20($gp)
  bgt $s0, $s1, label2
  j label3
label2:
  lw $s2, -24($gp)
  li $s3, 2
  lw $s4, -8($gp)
  div $s4, $s3
  mfhi $s2
  sw $s2, -24($gp)
  lw $s5, -24($gp)
  li $s6, 1
  beq $s5, $s6, label4
  j label5
label4:
  lw $s7, -28($gp)
  lw $t8, -4($gp)
  lw $t9, -16($gp)
  add $s7, $t9, $t8
  sw $s7, -28($gp)
  lw $t0, -16($gp)
  lw $t1, -28($gp)
  move $t0, $t1
  sw $t0, -16($gp)
label5:
  lw $t2, -36($gp)
  li $t2, 2
  sw $t2, -36($gp)
  lw $t3, -40($gp)
  lw $t4, -4($gp)
  lw $t5, -36($gp)
  mul $t3, $t5, $t4
  sw $t3, -40($gp)
  lw $t6, -4($gp)
  lw $t7, -40($gp)
  move $t6, $t7
  sw $t6, -4($gp)
  lw $s0, -48($gp)
  li $s0, 2
  sw $s0, -48($gp)
  lw $s1, -52($gp)
  lw $s2, -48($gp)
  lw $s3, -8($gp)
  div $s3, $s2
  mflo $s1
  sw $s1, -52($gp)
  lw $s4, -8($gp)
  lw $s5, -52($gp)
  move $s4, $s5
  sw $s4, -8($gp)
  j label1
label3:
  lw $s6, -16($gp)
  move $v0, $s6
  jr $ra

main:
  move $gp, $sp
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -16
  sw $sp, -4($sp)
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  addi $sp, $sp, -4
  lw $t0, -4($gp)
  li $t0, 3
  sw $t0, -4($gp)
  lw $t1, -8($gp)
  lw $t2, -4($gp)
  move $t1, $t2
  sw $t1, -8($gp)
  lw $t3, -12($gp)
  li $t3, 7
  sw $t3, -12($gp)
  lw $t4, -16($gp)
  lw $t5, -12($gp)
  move $t4, $t5
  sw $t4, -16($gp)
  lw $t6, -20($gp)
  li $t6, 0
  sw $t6, -20($gp)
  lw $t7, -24($gp)
  lw $s0, -20($gp)
  move $t7, $s0
  sw $t7, -24($gp)
  lw $s1, -24($gp)
  addi $sp, $sp, -72
  sw $t0, 0($sp)
  sw $t1, 4($sp)
  sw $t2, 8($sp)
  sw $t3, 12($sp)
  sw $t4, 16($sp)
  sw $t5, 20($sp)
  sw $t6, 24($sp)
  sw $t7, 28($sp)
  sw $s0, 32($sp)
  sw $s1, 36($sp)
  sw $s2, 40($sp)
  sw $s3, 44($sp)
  sw $s4, 48($sp)
  sw $s5, 52($sp)
  sw $s6, 56($sp)
  sw $s7, 60($sp)
  sw $t8, 64($sp)
  sw $t9, 68($sp)
  addi $sp, $sp, -8
  sw $ra, 0($sp)
  sw $gp, 4($sp)
  jal multiply
  move $sp, $gp
  lw $ra, 0($sp)
  lw $gp, 4($sp)
  addi $sp, $sp, 8
  addi $sp, $sp, 72
  move $s1, $v0
  sw $s1, -24($gp)
  addi $sp, $sp, -8
  sw $a0, 0($sp)
  sw $ra, 4($sp)
  lw $s2, -24($gp)
  move $a0, $s2
  jal write
  lw $a0, 0($sp)
  lw $ra, 4($sp)
  addi $sp, $sp, 8
  lw $s3, -52($gp)
  li $s3, 0
  sw $s3, -52($gp)
  lw $s4, -56($gp)
  li $s5, 16
  lw $s6, -52($gp)
  mul $s4, $s6, $s5
  sw $s4, -56($gp)
  lw $s7, -60($gp)
  lw $s7, -48($gp)
  sw $s7, -60($gp)
  lw $t8, -64($gp)
  lw $t9, -56($gp)
  lw $t0, -60($gp)
  add $t8, $t0, $t9
  sw $t8, -64($gp)
  lw $t1, -68($gp)
  li $t1, 2
  sw $t1, -68($gp)
  lw $t2, -48($gp)
  lw $t3, -68($gp)
  move $t2, $t3
  sw $t2, -48($gp)
  lw $t4, -76($gp)
  li $t4, 0
  sw $t4, -76($gp)
  lw $t5, -80($gp)
  li $t6, 16
  lw $t7, -76($gp)
  mul $t5, $t7, $t6
  sw $t5, -80($gp)
  lw $s0, -84($gp)
  lw $s0, -48($gp)
  sw $s0, -84($gp)
  lw $s1, -88($gp)
  lw $s2, -80($gp)
  lw $s3, -84($gp)
  add $s1, $s3, $s2
  sw $s1, -88($gp)
  lw $s4, -92($gp)
  lw $s5, -48($gp)
  move $s4, $s5
  sw $s4, -92($gp)
  addi $sp, $sp, -8
  sw $a0, 0($sp)
  sw $ra, 4($sp)
  lw $s6, -92($gp)
  move $a0, $s6
  jal write
  lw $a0, 0($sp)
  lw $ra, 4($sp)
  addi $sp, $sp, 8
  move $v0, $0
  jr $ra
