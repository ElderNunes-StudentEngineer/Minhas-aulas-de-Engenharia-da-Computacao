# 2) implemente o código correspondente em mips

# int vetor[] = {3, 0, 1, 2, -6, -2, 4, 10, 3, 7, 8, -9, -15, -20, -87, -100}

# printf("Seja bem vindo! \nPor favor entre com um valor inteiro para pesquisar no vetor\n\n");
# scanf("%i", elemento);

# while(vetor[i] != -100){

#     if(vetor[i] == elemento){
#         printf("Elemento %i encontrado\n\n", elemento );
#         exit(0);
#     }

#     i++;
# }

# printf("Elemento não encontrado\n\n");
# exit(0);
.data
    V: .word 3, 0, 1, 2, -6, -2, 4, 10, 3, 7, 8, -9, -15, -20, -87, -100    
    mensagem: .asciiz "Seja bem vindo! \nPor favor entre com um valor inteiro para pesquisar no vetor:\n\n"
    msg_encontrado: .asciiz "Elemento %i encontrado\n\n"
    msg_nao_encontrado: .asciiz "Elemento não encontrado\n\n"
.text   
    main:
        # Imprime a mensagem de boas-vindas
        li $v0, 4                
        la $a0, mensagem
        syscall

        # Lê o elemento do usuário
        li $v0, 5                
        syscall
        move $t1, $v0            

        # Inicializa o índice
        li $t0, 0               

    while:
        # Carrega o valor do vetor na posição i
        lw $t2, V($t0)           

        # Verifica se o valor é -100 (fim do vetor)
        li $t3, -100
        beq $t2, $t3, naoEncontrado   

        # Verifica se o elemento foi encontrado
        beq $t2, $t1, encontrado      

        # Incrementa o índice
        addi $t0, $t0, 4         
        j while                  

    encontrado:
        # Imprime mensagem de elemento encontrado
        li $v0, 4                
        la $a0, msg_encontrado
        syscall

        # Imprime o elemento encontrado
        move $a0, $t1            
        li $v0, 1                
        syscall

    naoEncontrado:
        #Imprime mensagem de elemento não encontrado   
        la $a0, msg_nao_encontrado
        syscall         




