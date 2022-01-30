.data
	newline:	.asciiz	"\n"
.text
.globl main
main:
	li $v0, 1
	li $a0, 6
	syscall
	li $v0, 4
	la $a0, newline
	syscall
main1:
	li $v0, 1
	li $a0, 10
	syscall
	li $v0, 4
	la $a0, newline
	syscall
main2:
	li $v0, 1
	li $a0, 4
	syscall
	li $v0, 4
	la $a0, newline
	syscall
main3:
	li $v0, 1
	li $a0, 2
	syscall
	li $v0, 4
	la $a0, newline
	syscall
main4:
	li $v0, 1
	li $a0, 14
	syscall
	li $v0, 4
	la $a0, newline
	syscall
main5:
	li $v0, 1
	li $a0, 1777
	syscall
	li $v0, 4
	la $a0, newline
	syscall
	li $v0, 10
	syscall