#pragma once

#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAM_NOME 25

typedef struct NO {
    int prioridade;         
    char NomePet[TAM_NOME]; 
    struct NO *prox;        
} NO;

typedef struct LISTA {
    NO *cabeca;
    int tamanho;
} LISTA;

typedef struct PILHA {
    NO *topo;
    int tamanho;
} PILHA;

typedef struct FILAORD {
    NO *cabeca;
    int tamanho;
} FILAORD;

typedef struct FILA {
    NO *inicio;
    NO *fim;
    int tamanho;
} FILA;

// Funções de inicialização
void iniciaLista(LISTA *l);
void iniciaPilha(PILHA *p);
void iniciaFilaOrd(FILAORD *f);
void iniciaFila(FILA *f);

// Funções da fila ordenada
bool verificaFilaOrdVazia(FILAORD *f);
void inseriNovoPET(FILAORD *f, char NomePet[], int Prioridade);
void atenderPET(FILAORD *f, PILHA *atendidos);

// Funções da fila (não urgentes)
bool verificaFilaVazia(FILA *f);
void insereNaFila(FILA *f, char NomePet[]);

// Funções da lista de espera
void insereListaEspera(LISTA *l, char NomePet[], int Prioridade);
void RemoveListaEspera(LISTA *l);
void proxAtendimento(LISTA *l, FILAORD *urgentes, FILA *normais);

// Funções de exibição
void exibeListaEspera(LISTA *l);
void exibeAtendidos(PILHA *p);
void exibePrioridades(FILAORD *f);
void exibeFila(FILA *f);

// Funções de liberação de memória
void liberaLista(LISTA *l);
void liberaPilha(PILHA *p);
void liberaFilaOrd(FILAORD *f);
void liberaFila(FILA *f);

#endif