#include <unistd.h>
#include <string.h>
#include <stdio.h>

void myPrintf(int x, int y, char* msg){
    int size = strlen(msg);
    char msg2[11];
    strcpy(msg2, "\033[ B\033[ C");

    msg2[2] = x + '0';
    msg2[6] = y + '0';

    write(1, msg2, 8);
    write(1, msg, size);
}

int main(){
    myPrintf(5, 5, "HELLLOUUU!\n");

}   