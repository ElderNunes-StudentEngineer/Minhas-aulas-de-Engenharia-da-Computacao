/*
6. Funções – Organizando o Sistema de Recomendação
● Exercício: Implemente uma função recomendar_topico(int
dificuldade) que retorne um tópico com base na dificuldade.
● Objetivo: Modularizar o código com funções.
*/
#include<stdio.h>
#include<stdlib.h>

void recomendar_topico(int dificuldade){
    if(dificuldade == 1){
        printf("Com base nessa dificuldade o tópico é Ciências!\n");
    }
    if(dificuldade == 2){
        printf("Com base nessa dificuldade o tópico é Português!\n");
    }
    if(dificuldade == 3){
        printf("Com base nessa dificuldade o tópico é Matemática!\n");
    }
}

int main(void){
    int dificuldade;
    printf("Digite o grau de dificuldade(1 a 3): ");
    scanf("%d", &dificuldade);
    recomendar_topico(dificuldade);

    return 0;
}