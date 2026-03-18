    .data
        mensagem: .asciiz "Digite o primeiro número:"
        mensagem2: .asciiz "Digite o segundo número:"
        Resultado: .asciiz "Resultado:"
    .text
    soma:

    add $sp, $sp, -8

    sw $s0, 4($sp)
    sw $ra, 8($sp)

    add $s0, $a0, $a1
    move $v0, $s0

    lw $ra, 8($sp)
    lw $s0, 4($sp)
    add $sp, $sp, 8

    jr $ra

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

    move $a0, $t0
    move $a1, $t1

    jal soma


    li $v0, 4
    la $a0, Resultado
    syscall

    #move $a0, $v0
    move $t0, $a0
    li $v0, 1
    syscall

    li $v0, 10
    syscall