/*
7. Arrays e Strings – Gerenciando uma Lista de Tópicos de Estudo
● Exercício: Armazene múltiplos tópicos em um array de strings e permita que
o usuário busque por um tópico específico utilizando strcmp().
● Objetivo: Praticar o uso de arrays e funções de manipulação de strings.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
    char topico[20];
    char *topicos[] = {"Segunda", "Terça", "Quarta", "Quinta", "Sexta"};

    printf("Digite o nome a ser pesquisado: ");
    scanf("%[^\n]", topico);

    for(int i=0; i<5; i++){
        if(strcmp(topico, topicos[i]) == 0){
            printf("%s encontrado\n", topico);
        }else{
            printf("Nome não encontrado!\n");
            break;
        }
    }
    

    return 0;
}