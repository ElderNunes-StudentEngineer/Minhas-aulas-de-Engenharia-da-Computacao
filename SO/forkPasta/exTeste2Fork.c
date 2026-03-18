#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void){

    int pid = fork();
    int status;

    if(pid > 0){
        printf("Eu sou Pai, meu pid é: %d\n", getpid());
        wait(&status);

        if(WIFEXITED(status)) printf("Meu Filho encerrou normalmente, me passou o valor: %d\n", WEXITSTATUS(status));

        if(WIFSIGNALED(status)) printf("Mataram meu Filho\n");

    }else if(pid == 0){
        printf("Eu sou o processo Filho, meu pid é: %d\n", getpid());
        sleep(10);
        exit(50);

    }else{
        printf("ERRO!\n");
    }

    return 0;
}