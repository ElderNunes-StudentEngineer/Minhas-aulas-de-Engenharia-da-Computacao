#ifndef ABB_H
#define ABB_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct no_arvore {
    int chave;
    struct no_arvore* esq;
    struct no_arvore* dir;
} NO_ARVORE;

void inicializaABB(NO_ARVORE** raiz);
bool estaVazia(NO_ARVORE** raiz);
void insereABB(NO_ARVORE** no, int ch);
void preOrdem(NO_ARVORE** no);
void emOrdem(NO_ARVORE** no);
void posOrdem(NO_ARVORE** no);
bool pesquisaABB(NO_ARVORE** no, int ch);
void destruirABB(NO_ARVORE** no);
void removeABB(NO_ARVORE** no, int ch);

#endif 
