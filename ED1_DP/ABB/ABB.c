#include "ABB.h"

void inicializaABB(NO_ARVORE** raiz){
    (*raiz) = NULL;
}

bool estaVazia(NO_ARVORE** raiz){
    return (*raiz) == NULL;
}

void insereABB(NO_ARVORE** no, int ch){
    if(estaVazia(no)){
        (*no) = (NO_ARVORE*) malloc(sizeof(NO_ARVORE));
        if((*no) == NULL){
            printf("Não foi possível alocar memória!\n");
            return;
        }
        (*no)->dir = (*no)->esq = NULL;
        (*no)->chave = ch;
        return;
    }
    if((*no)->chave == ch) return;
    if((*no)->chave > ch) insereABB(&(*no)->esq, ch);
    else insereABB(&(*no)->dir, ch);
}

void preOrdem(NO_ARVORE** no){
    if(estaVazia(no)) return;
    printf(" %d ", (*no)->chave);
    preOrdem(&(*no)->esq);
    preOrdem(&(*no)->dir);
}

void emOrdem(NO_ARVORE** no){
    if(estaVazia(no)) return;
    emOrdem(&(*no)->esq);
    printf(" %d ", (*no)->chave);
    emOrdem(&(*no)->dir);
}

void posOrdem(NO_ARVORE** no){
    if(estaVazia(no)) return;
    posOrdem(&(*no)->esq);
    posOrdem(&(*no)->dir);
    printf(" %d ", (*no)->chave);
}

bool pesquisaABB(NO_ARVORE** no, int ch){
    if(estaVazia(no)) return false;
    if((*no)->chave == ch) return true;
    else if((*no)->chave > ch) return pesquisaABB(&(*no)->esq, ch);
    else return pesquisaABB(&(*no)->dir, ch);
}

void destruirABB(NO_ARVORE** no) {
    if (estaVazia(no)) return;
    destruirABB(&(*no)->esq);
    destruirABB(&(*no)->dir);
    free(*no);
    (*no) = NULL;
}

void removeABB(NO_ARVORE** no, int ch) {
    if (estaVazia(no)) {
        printf("\nO elemento %d não está na Árvore!\n", ch);
        return;
    }

    if ((*no)->chave == ch) {
        // Caso 1: Nó sem filhos
        if ((*no)->esq == NULL && (*no)->dir == NULL) {
            free(*no);
            (*no) = NULL;
            printf("\nElemento %d excluído com sucesso!\n", ch);
            return;
        }

        // Caso 2: Nó com um filho à esquerda
        if ((*no)->esq != NULL && (*no)->dir == NULL) {
            NO_ARVORE* aux = (*no)->esq;
            free(*no);
            (*no) = aux;
            printf("\nElemento %d excluído com sucesso!\n", ch);
            return;
        }

        // Caso 3: Nó com um filho à direita
        if ((*no)->esq == NULL && (*no)->dir != NULL) {
            NO_ARVORE* aux = (*no)->dir;
            free(*no);
            (*no) = aux;
            printf("\nElemento %d excluído com sucesso!\n", ch);
            return;
        }

        // Caso 4: Nó com dois filhos (substitui pelo maior da subárvore esquerda)
        if ((*no)->esq != NULL && (*no)->dir != NULL) {
            NO_ARVORE* subEsq = (*no)->esq;
            while (subEsq->dir != NULL) {
                subEsq = subEsq->dir;  // Achar o maior da subárvore esquerda
            }
            (*no)->chave = subEsq->chave;  // Substitui pelo maior da subárvore esquerda
            removeABB(&(*no)->esq, (*no)->chave);  // Remove o nó duplicado
            return;
        }
    } else {
        if ((*no)->chave > ch) removeABB(&(*no)->esq, ch);
        else removeABB(&(*no)->dir, ch);
    }
}