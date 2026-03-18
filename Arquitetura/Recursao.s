
.data
    msg: .asciiz "O fatorial é: "
.text
    main:
        li $a0, 5
        li $t0, 1        
        jal fact    
        
        move $t0, $v0
        
        la $a0, msg
        li $v0, 4
        syscall
        
        move $a0, $t0
        li $v0, 1
        syscall
        
        li $v0, 10
        syscall    
            
    fact:
        addi $sp, $sp, -8
        sw $a0, 8($sp)
        sw $ra, 4($sp)
        
        bgt $a0, $t1, L1
        li $v0, 1

        lw $a0, 8($sp)
        lw $ra, 4($sp)
        addi $sp, $sp, 8
        
        jr $ra    
        
    L1:
        addi $a0, $a0, -1
        jal fact    
        
        lw $a0, 8($sp)
        lw $ra, 4($sp)
        addi $sp, $sp, 8
        
        mul $v0, $v0, $a0
        
        jr $ra 
        
        
        