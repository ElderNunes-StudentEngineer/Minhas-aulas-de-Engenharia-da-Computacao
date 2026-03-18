#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){

    int pid = fork();

    if(pid == 0){
        printf("Processo Filho!\n");
        execl("exExec2", " ", NULL);
        printf("Vou execultar ou não?\n");
    }else{
        printf("Processo pai esperando filho terminar\n");
        wait(NULL);
        printf("Encerrado!\n");
    }


    return 0;
}