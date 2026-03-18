#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
Excrever um programa C que cria uma árvore de 3 processos, onde o processo A faz um fork() 
criando um processo B, o processo B, por sua vez, faz um fork() criando um processo C. 
Cada processo deve exibir uma mensagem "Eu sou o processo XXX, filho de YYY", onde XXX e YYY são 
PIDs de processos. Utilizar wait() para garantir que o processo C imprima sua resposta antes do B, e 
que o processo B imprima sua resposta antes do A. Utilizar sleep() (man 3 sleep) para haver um 
intervalo de 1 segundo entre cada mensagem impressa.
*/

int main(){

    int B = fork(); // A cria B

    if(B < 0){
        printf("Erro!\n");
    }else if(B == 0){
        int C = fork(); // B cria C
        
        if(C < 0){
            printf("Erro!\n");
        }

        if(C == 0){
            printf("Eu sou o processo C, meu pai é: %d\n", getppid());
            sleep(1);
        }else{
            wait(NULL);
            printf("Eu sou o processo B, meu pai é: %d\n", getppid());
        }
    }else{
        // Processo A
        wait(NULL);
        sleep(1);
        printf("Eu sou o processo A, meu pai é %d\n", getppid());
    }

    return 0;
}