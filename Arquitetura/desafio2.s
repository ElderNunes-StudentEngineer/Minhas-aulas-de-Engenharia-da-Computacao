.data
	V: .word 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
.text
	main:
		la $t0, V
		
		lw $t1, 8($t0)
		lw $t2, 16($t0)
		add $t3, $t1, $t2
		
		sw $t3, 4($t0)
		
		li $v0, 1
		lw $a0, 4($t0)
		syscall
		
		li $v0, 10
		syscall
