#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noAvl {
    int chave;
    struct noAvl* esq;
    struct noAvl* dir;
    int h;
} NO_AVL;

// Funções principais
void inicializaAVL(NO_AVL** raiz);
bool estaVazia(NO_AVL** raiz);
int maxAlturaFilhos(NO_AVL** no);
int calculaFB(NO_AVL** no);
void rotacaoSimplesEsq(NO_AVL** no);
void rotacaoSimplesDir(NO_AVL** no);
void insereAVL(NO_AVL** no, int ch);
void preOrdem(NO_AVL** no);
void emOrdem(NO_AVL** no);
void posOrdem(NO_AVL** no);
int tamanhoAVL(NO_AVL** no);
void removeElementoAVL(NO_AVL** no, int ch);
void destruirAVL(NO_AVL** no);

#endif
