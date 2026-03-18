#include <unistd.h>
#include <stdio.h>

int tamanho(char* str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

int main(){
    
    int fd[2];
    pipe(fd);

    if (fork() == 0){
        char buff[1024];
        int n = read(fd[0], buff, sizeof(buff)-1);
        buff[n] = '\0';

        printf("Recebido do pai: %s\n", buff); //Processo filho
    }else{
        char *mensagem = "Olá simba, sou seu pai!\n"; //Processo pai
        write(fd[1], mensagem, tamanho(mensagem));
    }


    return 0;
}