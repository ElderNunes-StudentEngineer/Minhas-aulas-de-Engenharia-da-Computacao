#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct objeto{
    int CPF;
    int idade;
    char nome[30];
    struct objeto *prox;
}OBJETOS;

typedef struct{
    OBJETOS* inicio;
    OBJETOS* final;
    int tamanho;
}FILA_DINAMICA;

void inicializaFila(FILA_DINAMICA* fila);
bool estaVazia(FILA_DINAMICA* fila);
int tamanhoFila(FILA_DINAMICA* fila);
void insereFila(FILA_DINAMICA* fila, char nome[], int cpf, int idade);
OBJETOS* removeElemento(FILA_DINAMICA* fila);
void imprimePrimeiroFila(FILA_DINAMICA* fila);
void imprimeUltimoFila(FILA_DINAMICA* fila);
void imprimeFila(FILA_DINAMICA* fila);
void destroiFila(FILA_DINAMICA* fila);
void pesquisaElemento(FILA_DINAMICA* fila, int cpf);

#endif