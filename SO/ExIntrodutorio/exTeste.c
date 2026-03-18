#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int tamanho(char* str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

void interrupt(int sinal){
    char *msg = "Encerrando...\n";

    write(1, msg, tamanho(msg));

    exit(0);
}

void alarme(int sinal){
    char *msg = "Dentro de um loop!\n";

    write(1, msg, tamanho(msg));
}

int main(){
    
    signal(SIGALRM, alarme); // Detectar o alarme       
    signal(SIGINT, interrupt); // Detectar Ctrl+C

    while(1){
        alarm(5); // Disparar o alarme em 5 segundos
        pause(); // Espera por sinais
    }

    return 0;
}