/*
2. Variáveis e Tipos de Dados – Armazenando Tópicos de Estudo
● Exercício: Declare variáveis (int, float, char) para armazenar o nome de
um tópico de estudo, a dificuldade (escala de 1 a 5) e o tempo estimado.
Atribua e imprima os valores.
● Objetivo: Utilizar os tipos de variáveis e o armazenamento básico.
*/
#include<stdio.h>
#include<stdlib.h>

int main(void){
    char nome[30];
    int dificuldade;
    float tempo;

    printf("Digite o nome de um tópico de estudo: ");
    scanf("%[^\n]", nome);
    printf("Digite o grau de dificuldade(de 1 a 5): ");
    scanf("%d", &dificuldade);
    printf("Digite o tempo estimado: ");
    scanf("%f", &tempo);

    printf("Nome do tópico: %s | Grau de dificuldade(de 1 a 5): %d | Tempo estimado: %.2f\n", nome, dificuldade, tempo);

    return 0;
}