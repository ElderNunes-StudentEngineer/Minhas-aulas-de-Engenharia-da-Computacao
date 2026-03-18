/*
3. Operadores e Expressões – Calculando a Eficiência do Estudo
● Exercício: Dado o nível de dificuldade e o tempo estimado de um tópico de
estudo, estipule e calcule um "índice de eficiência de estudo" utilizando
operações aritméticas.
● Objetivo: Reforçar o uso de operadores (+, -, *, /) e expressões.
*/
#include<stdio.h>
#include<stdlib.h>

int main(void){

    char nome[30];
    int dificuldade;
    float tempo;
    float indice;

    printf("Digite o nome de um tópico de estudo: ");
    scanf("%[^\n]", nome);
    printf("Digite o grau de dificuldade(de 1 a 5): ");
    scanf("%d", &dificuldade);
    printf("Digite o tempo estimado: ");
    scanf("%f", &tempo);

    if (dificuldade != 0) {
        indice = tempo / dificuldade;
        printf("Índice de Eficiência de Estudo: %.2f\n", indice);
    } else {
        printf("Erro: A dificuldade não pode ser zero.\n");
    }

    return 0;
}