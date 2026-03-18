/*
1. Entrada e Saída Básica – Exibindo Tópicos de Estudo
● Exercício: Escreva um programa que imprima um conjunto predefinido (de
sua escolha) de tópicos de estudo utilizando printf.
● Objetivo: Introduzir a saída formatada e a funcionalidade básica do printf.
*/
#include<stdio.h>
#include<stdlib.h>

int main(void){
    char nome[30];
    int idade;

    printf("Digite o seu nome: ");
    scanf("%[^\n]", nome);

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Nome: %s \nIdade: %d\n", nome, idade);

    return 0;
}