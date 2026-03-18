.data
    mensagem: .asciiz "Digite a base do triângulo:"
    mensagem2: .asciiz "Digite a altura do triângulo:"
    Resultado: .asciiz "A área do triângulo é:"
.text
    main:
        li $v0, 4
        la $a0, mensagem
        syscall

        li $v0, 5
        syscall
        move $t0, $v0

        li $v0, 4
        la $a0, mensagem2
        syscall

        li $v0, 5
        syscall
        move $t1, $v0

        jal calculaAreaTriangulo
        move $t0, $v0

        li $v0, 4
        la $a0, Resultado
        syscall

        move $a0, $t0         
        li $v0, 1              
        syscall

        li $v0, 10             
        syscall

calculaAreaTriangulo:
        addi $sp, $sp, -8
        sw $s0, 4($sp)
        sw $ra, 8($sp)

        mul $s0, $a0, $a1
        move $a0, $s0

        jal divPor2

        lw $s0, 4($sp)
        lw $ra, 8($sp)
        addi $sp, $sp, 8

divPor2:
        addi $sp, $sp, -8
        sw $s0, 4($sp)
        sw $ra, 8($sp)

        li $s0, 2
        div $v0, $a0, $s0

        lw $s0, 4($sp)
        lw $ra, 8($sp)
        addi $sp, $sp, 8

        jr $ra

