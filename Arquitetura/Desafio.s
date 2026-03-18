.data
	menu: .asciiz "\n\nMenu\n1.Soma\n2.Subtração\n3.Multiplicação\n4.Divisão\n5.Sair\nEscolha uma opção: \n"
	num1: .asciiz "Digite o primeiro número: \n\n"
	num2: .asciiz "Digite o segundo número: \n\n"
	result: .asciiz "Resultado: "
	Inva: .asciiz "Opção inválida!"
.text
      main:

	li $v0, 4
	la $a0, menu
	syscall
	
	li $v0, 5
	syscall
	
	move $t0, $v0
	
	li $t1, 1
	li $t2, 2
	li $t3, 3
	li $t4, 4
	li $t5, 5
	
	beq $t0, $t1, soma
	beq $t0, $t2, subtracao
	beq $t0, $t3, multiplicacao
	beq $t0, $t4, divisao
	beq $t0, $t5, sair
	
	li $v0, 4
	la $a0, Inva	
	syscall
	
	j sair
	
	soma:
	
		li $v0, 4
		la $a0, num1
		syscall
		
		li $v0, 5
		syscall
		
		move $t0, $v0 
		
		li $v0, 4
		la $a0, num2
		syscall
		
		li $v0, 5
		syscall
		
		move $t1, $v0
		add $t2, $t0, $t1
		
		li $v0, 4
		la $a0, result
		syscall
		
		li $v0, 1
		move $a0, $t2
		syscall
		
		j main
	
	subtracao:
	
		li $v0, 4
		la $a0, num1
		syscall
		
		li $v0, 5
		syscall
		
		move $t0, $v0 
		
		li $v0, 4
		la $a0, num2
		syscall
		
		li $v0, 5
		syscall
		
		move $t1, $v0
		sub $t3, $t0, $t1
		
		li $v0, 4
		la $a0, result
		syscall
		
		li $v0, 1
		move $a0, $t3
		syscall
		
		j main
	
	multiplicacao:
	
		li $v0, 4
		la $a0, num1
		syscall
		
		li $v0, 5
		syscall
		
		move $t0, $v0 
		
		li $v0, 4
		la $a0, num2
		syscall
		
		li $v0, 5
		syscall
		
		move $t1, $v0
		mul $t4, $t0, $t1
		
		li $v0, 4
		la $a0, result
		syscall
		
		li $v0, 1
		move $a0, $t4
		syscall
		
		j main
	
	divisao:
	
		li $v0, 4
		la $a0, num1
		syscall
		
		li $v0, 5
		syscall
		
		move $t0, $v0 
		
		li $v0, 4
		la $a0, num2
		syscall
		
		li $v0, 5
		syscall
		
		move $t1, $v0
		div $t5, $t0, $t1
		
		li $v0, 4
		la $a0, result
		syscall
		
		li $v0, 1
		move $a0, $t5
		syscall
		
		j main
	
	sair:
		li $v0, 10
		syscall
		
	
