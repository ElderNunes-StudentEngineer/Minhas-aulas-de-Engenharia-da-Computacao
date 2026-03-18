#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int dado;
    struct No* prox;
} NO;

typedef struct Pilha {
    NO* topo;
    int tamanho;
} PILHA;

void inicializaPilha(PILHA* p);
bool estaVazia(PILHA* p);
int tamanhoPilha(PILHA* p);
void inserePilha(PILHA* p, int d);
int removerPilha(PILHA* p);
void exibirPilha(PILHA* p);

#endif
