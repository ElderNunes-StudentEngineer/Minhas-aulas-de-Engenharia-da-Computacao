/*
4. Instruções Condicionais – Recomendando um Tópico com Base na
Dificuldade
● Exercício: Implemente um programa que receba a entrada do usuário
(scanf) para o nível de dificuldade preferido e sugira um tópico com base
nas condicionais (if, else). Você deve estipular qual tópico é recomendado
para qual nível de dificuldade.
● Objetivo: Introduzir a tomada de decisões em C.
*/
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int escolha;
    printf("Dificuldades: \n1-Fácil \n2-Médio \n3-Difícil\n");
    printf("Qual sua escolha de dificuldade: ");
    scanf("%d", &escolha);

    if(escolha == 1){
        printf("Dificuldade fácil escolhida!\n");
        printf("Abrindo jogo no modo escolhido...\n");
    }
    if(escolha == 2){
        printf("Dificuldade médio escolhida!\n");
        printf("Abrindo jogo no modo escolhido...\n");
    }
    if(escolha == 3){
        printf("Dificuldade difícil escolhida!\n");
        printf("Abrindo jogo no modo escolhido...\n");
    }
    if(escolha > 3){
        printf("Número inválido!\n");
    }

    return 0;
}