#include <unistd.h>
#include <stdio.h>

int main(void){

    int PID;

    PID = fork();

    if(PID == 0){
        printf("Bom dia: Eu sou o filho! -> Retorno do fork = %d, mas meu PID é: %d\n",  PID, getpid());
    }else if(PID > 0){
        printf("Bom dia: Eu sou o Pai! -> Retorno do fork = %d, mas meu PID é: %d\n",  PID, getpid());
    }

    return 0;
}