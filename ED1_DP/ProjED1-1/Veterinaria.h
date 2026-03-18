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
void iniciaPilha(PILHA *p);
void iniciaFilaOrd(FILAORD *f);
void iniciaFila(FILA *f);

// Funções da fila ordenada
bool verificaFilaOrdVazia(FILAORD *f);
void inseriNovoPET(FILAORD *f, char NomePet[], int Prioridade);
void pesquisarNaFilaOrd(FILAORD *fila, char NomePet[]);

// Funções da fila (não urgentes)
bool verificaFilaVazia(FILA *f);
void insereNaFila(FILA *f, char NomePet[]);
void pesquisarNaFila(FILA *fila, char NomePet[]);
// Funções da pilha

// Funções de exibição
void exibeAtendidos(PILHA *p);
void exibePrioridades(FILAORD *f);
void exibeFila(FILA *f);

// Funções de liberação de memória
void liberaPilha(PILHA *p);
void liberaFilaOrd(FILAORD *f);
void liberaFila(FILA *f);

// Backup dos dados
bool salvaFilaOrd(FILAORD *f, const char *nomeArquivo);
bool salvaFila(FILA *f, const char *nomeArquivo);
bool carregaFilaOrd(FILAORD *f, const char *nomeArquivo);
bool carregaFila(FILA *f, const char *nomeArquivo);

#endif