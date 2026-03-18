/*
8. Ponteiros – Acessando e Modificando Tópicos Dinamicamente
● Exercício: Use ponteiros para navegar por um array de tópicos de estudo e
modificar seus níveis de dificuldade.

● Objetivo: Introduzir a aritmética de ponteiros.
*/
#include <stdio.h>

typedef struct {
    char nome[30];
    int dificuldade;  
} TopicoEstudo;

int main() {
    TopicoEstudo topicos[3] = {
        {"Matemática", 3},
        {"Física", 4},
        {"Química", 2}
    };

    TopicoEstudo *ptr;

    printf("Tópicos e níveis de dificuldade originais:\n");
    for (ptr = topicos; ptr < topicos + 3; ptr++) {
        printf("Tópico: %s, Dificuldade: %d\n", ptr->nome, ptr->dificuldade);
    }

    for (ptr = topicos; ptr < topicos + 3; ptr++) {
        if (ptr->dificuldade == 3) {
            ptr->dificuldade = 5;  //Tornar mais difícil
        } else if (ptr->dificuldade == 4) {
            ptr->dificuldade = 1;  //Tornar mais fácil
        }
    }

    printf("\nTópicos e níveis de dificuldade após modificação:\n");
    for (ptr = topicos; ptr < topicos + 3; ptr++) {
        printf("Tópico: %s, Dificuldade: %d\n", ptr->nome, ptr->dificuldade);
    }

    return 0;
}
