.data
    mensagem: .asciiz "Por favor, digite o primeiro número (g):\n"
    mensagem2: .asciiz "Por favor, digite o segundo número (h):\n"
    mensagem3: .asciiz "Por favor, digite o terceiro número (i):\n"
    mensagem4: .asciiz "Por favor, digite o quarto número (j):\n"
    resultado: .asciiz "Resultado de folha: "
.text
    main:
    # Solicitar o primeiro número (g)
    li $v0, 4
    la $a0, mensagem
    syscall

    li $v0, 5
    syscall      
    move $t0, $v0  # $t0 = g

    # Solicitar o segundo número (h)
    li $v0, 4
    la $a0, mensagem2
    syscall

    li $v0, 5
    syscall      
    move $t1, $v0  # $t1 = h

    # Solicitar o terceiro número (i)
    li $v0, 4
    la $a0, mensagem3
    syscall

    li $v0, 5
    syscall      
    move $t2, $v0  # $t2 = i

    # Solicitar o quarto número (j)
    li $v0, 4
    la $a0, mensagem4
    syscall

    li $v0, 5
    syscall      
    move $t3, $v0  # $t3 = j

    # Chamar a função folha
    jal folha

    # Imprimir o resultado
    li $v0, 4
    la $a0, resultado
    syscall

    move $a0, $t6  # Move o resultado para $a0 para impressão
    li $v0, 1      # Código para imprimir inteiro
    syscall

    # Sair do programa
    li $v0, 10
    syscall

# Função folha
folha:
    # Calcula f = (g + h) - (i + j)
    add $t4, $t0, $t1        # $t4 = g + h
    add $t5, $t2, $t3        # $t5 = i + j
    sub $t6, $t4, $t5        # $t6 = f = (g + h) - (i + j)
    jr $ra                    # Retorna para a função chamadora
