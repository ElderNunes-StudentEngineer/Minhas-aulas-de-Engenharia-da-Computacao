#include<stdio.h>
#include<stdlib.h>

void converta(int mph, float *km, float *metros){;
    *km = mph * 1.609344;
    *metros = 0.277778 *(*km);
}//converta

int main(){

    float km, metros;

    converta(100, &km, &metros);

    printf("Velocidade de quilômetros por hora: %.2f\n", km);
    printf("Velocidade de metros por segundo: %.2f\n", metros);

    return 0;
}//main