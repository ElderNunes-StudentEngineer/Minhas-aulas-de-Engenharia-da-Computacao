#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define N 5

typedef struct{
    int CPF;
    char nome[30];
    int idade;
}OBJETOS;

typedef struct{
    int tamanho;
    int inicio;
    int fim;
    OBJETOS elementos[N];
}FILA_ESTATICA;

void iniciaFila(FILA_ESTATICA *fila){
    fila->tamanho = 0;
    fila->fim = fila->inicio = -1;
}//iniciaFila

bool estaCheia(FILA_ESTATICA *fila){
    return fila->tamanho == N;
}//estaCheia

bool estaVazia(FILA_ESTATICA *fila){
    return fila->tamanho == 0; 
}//estaVazia

int tamanhoFila(FILA_ESTATICA *fila){
    return fila->tamanho;
}//tamanhoFila

void insereFila(FILA_ESTATICA *fila, int cpf, char nome[], int idade){
    if(estaCheia(fila) == true){
        printf("Fila Cheia!\n");
        return;
    }//if

    if(estaVazia(fila) == true){
    fila->inicio = (fila->inicio+1) % N;
    }//if

    fila->tamanho++;
    fila->fim = (fila->fim+1) % N;

    fila->elementos[fila->fim].CPF = cpf;
    fila->elementos[fila->fim].idade = idade;
    strcpy(fila->elementos[fila->fim].nome, nome);
}//iniciaFila

void excluiElemento(FILA_ESTATICA *fila){
    if(estaVazia(fila) == true){
        printf("Fila Vazia!\n");
        return;
    }//if

    fila->tamanho--;
    if(estaVazia(fila) == true){
        iniciaFila(fila);
        return;
    }//if
    fila->inicio = (fila->inicio+1) % N;
}//excluiElemento

void imprimePrimeiroFila(FILA_ESTATICA *fila){
    if(estaVazia(fila) == true){
        printf("Fila Vazia!\n");
        return;
    }//if

    printf("Primeiro da Fila | Nome: %s | CPF: %d | Idade: %d\n", fila->elementos[fila->inicio].nome,
                                                                  fila->elementos[fila->inicio].CPF,
                                                                  fila->elementos[fila->inicio].idade);

}//imprimeFila

void imprimeUltimoFila(FILA_ESTATICA *fila){
        if(estaVazia(fila) == true){
        printf("Fila Vazia!\n");
        return;
    }//if

    printf("Último da Fila | Nome: %s | CPF: %d | Idade: %d\n", fila->elementos[fila->fim].nome,
                                                                  fila->elementos[fila->fim].CPF,
                                                                  fila->elementos[fila->fim].idade);

}//imprimeUltimoFila


int main(){

    FILA_ESTATICA f;

    iniciaFila(&f);
    insereFila(&f, 12345, "Elder Nunes", 19);
    insereFila(&f, 34562, "Felipe Nunes", 65);
    insereFila(&f, 11123, "Joao Nunes", 32);
    insereFila(&f, 22234, "Gi Nunes", 11);
    insereFila(&f, 33233, "Lucas Nunes", 23);

    excluiElemento(&f);

    imprimePrimeiroFila(&f);
    imprimeUltimoFila(&f);
    return 0;
}//main