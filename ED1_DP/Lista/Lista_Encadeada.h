// Lista_Encadeada.h
#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct jogador {
    char nome[30];
    int rank;
    char jogo[30];
    struct jogador *prox;
} JOGADOR;

typedef struct {
    JOGADOR *inicio;
    int tamanho;
} LISTA_ENCADEADA;

void inicializaLista(LISTA_ENCADEADA* lista);
bool estaVazia(LISTA_ENCADEADA* lista);
int tamanhoLista(LISTA_ENCADEADA* lista);
void insereLista(LISTA_ENCADEADA* lista, char nome[], int rank, char jogo[]);
void adicionarEm(LISTA_ENCADEADA* lista, char nome[], int rank, char jogo[], int pos);
void removerNoLista(LISTA_ENCADEADA* lista, int rank);
void encontrarJogador(LISTA_ENCADEADA* lista, int rank);
void exibirLista(LISTA_ENCADEADA* lista);
void liberarLista(LISTA_ENCADEADA* lista);

#endif