#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

char* msg;
int ctlz;

void myPrintf(int x, int y, char* msg){
    int size = strlen(msg);
    char msg2[11];
    strcpy(msg2, "\033[ B\033[ C");

    msg2[2] = x + '0';
    msg2[6] = y + '0';

    write(1, msg2, 8);
    write(1, msg, size);
}

void printsinc(char *Pmsg, int seg){

    msg = malloc(strlen(Pmsg)*sizeof(char));

    strcpy(msg, Pmsg);

    while(1){
        alarm(seg);
        pause();
    }
}

void handler_alarm(int signum){
    write(1, msg, strlen(msg));
}

void handler_ctlz(int signum){
    ctlz++;
    if(ctlz == 3){
         write(1, "Saindo do Programa...\n", strlen("Saindo do Programa...\n"));
        exit(0);
    }
}

int main(){

    ctlz = 0;
    signal(SIGTSTP, handler_ctlz);
    signal(SIGALRM, handler_alarm);

    myPrintf(5, 5, "Bom dia!\n");

    printsinc("Bom dia!\n", 5);

}   