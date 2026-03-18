/*
5. Laços de Repetição – Exibindo Vários Tópicos
● Exercício: Armazene cinco tópicos de estudo em um array e use um laço for
para exibi-los.
● Objetivo: Reforçar a iteração com laços.
*/
#include<stdio.h>
#include<stdlib.h>

int main(void){

    char *topicos[] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta"};
    for(int i=0; i<5; i++){
        printf("Tópico[%d]: %s\n", i, topicos[i]);
    }

    return 0;
}