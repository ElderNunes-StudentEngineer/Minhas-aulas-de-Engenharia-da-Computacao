#include "AVL.h"

void inicializaAVL(NO_AVL** raiz) {
    *raiz = NULL;
}

bool estaVazia(NO_AVL** raiz) {
    return *raiz == NULL;
}

int maxAlturaFilhos(NO_AVL** no) {
    int hE = (*no)->esq ? (*no)->esq->h : -1;
    int hD = (*no)->dir ? (*no)->dir->h : -1;
    return hE > hD ? hE : hD;
}

int calculaFB(NO_AVL** no) {
    int hD = (*no)->dir ? (*no)->dir->h : -1;
    int hE = (*no)->esq ? (*no)->esq->h : -1;
    return hD - hE;
}

void rotacaoSimplesEsq(NO_AVL** no) {
    NO_AVL* aux = (*no)->dir;
    (*no)->dir = aux->esq;
    aux->esq = *no;
    *no = aux;

    aux->esq->h = 1 + maxAlturaFilhos(&aux->esq);
    (*no)->h = 1 + maxAlturaFilhos(no);
}

void rotacaoSimplesDir(NO_AVL** no) {
    NO_AVL* aux = (*no)->esq;
    (*no)->esq = aux->dir;
    aux->dir = *no;
    *no = aux;

    aux->dir->h = 1 + maxAlturaFilhos(&aux->dir);
    (*no)->h = 1 + maxAlturaFilhos(no);
}

void insereAVL(NO_AVL** no, int ch) {
    if (estaVazia(no)) {
        *no = (NO_AVL*)malloc(sizeof(NO_AVL));
        if (!*no) {
            printf("Erro de alocação\n");
            return;
        }
        (*no)->chave = ch;
        (*no)->esq = (*no)->dir = NULL;
        (*no)->h = 0;
        return;
    }

    if (ch == (*no)->chave) return;
    if (ch < (*no)->chave) insereAVL(&(*no)->esq, ch);
    else insereAVL(&(*no)->dir, ch);

    (*no)->h = 1 + maxAlturaFilhos(no);
    int fB = calculaFB(no);

    // Balanceamento
    if (fB == 2) {
        if (calculaFB(&(*no)->dir) >= 0) rotacaoSimplesEsq(no);
        else {
            rotacaoSimplesDir(&(*no)->dir);
            rotacaoSimplesEsq(no);
        }
    } else if (fB == -2) {
        if (calculaFB(&(*no)->esq) <= 0) rotacaoSimplesDir(no);
        else {
            rotacaoSimplesEsq(&(*no)->esq);
            rotacaoSimplesDir(no);
        }
    }
}

void preOrdem(NO_AVL** no) {
    if (estaVazia(no)) return;
    printf(" %d[h=%d] ", (*no)->chave, (*no)->h);
    preOrdem(&(*no)->esq);
    preOrdem(&(*no)->dir);
}

void emOrdem(NO_AVL** no) {
    if (estaVazia(no)) return;
    emOrdem(&(*no)->esq);
    printf(" %d ", (*no)->chave);
    emOrdem(&(*no)->dir);
}

void posOrdem(NO_AVL** no) {
    if (estaVazia(no)) return;
    posOrdem(&(*no)->esq);
    posOrdem(&(*no)->dir);
    printf(" %d ", (*no)->chave);
}

int tamanhoAVL(NO_AVL** no) {
    if (*no == NULL) return 0;
    return 1 + tamanhoAVL(&(*no)->esq) + tamanhoAVL(&(*no)->dir);
}

void removeElementoAVL(NO_AVL** no, int ch) {
    if (estaVazia(no)) {
        printf("\nElemento %d não encontrado!\n", ch);
        return;
    }

    if (ch < (*no)->chave) {
        removeElementoAVL(&(*no)->esq, ch);
    } else if (ch > (*no)->chave) {
        removeElementoAVL(&(*no)->dir, ch);
    } else {
        // Encontrou o nó
        if ((*no)->esq == NULL && (*no)->dir == NULL) {
            free(*no);
            *no = NULL;
        } else if ((*no)->esq == NULL) {
            NO_AVL* temp = (*no)->dir;
            free(*no);
            *no = temp;
        } else if ((*no)->dir == NULL) {
            NO_AVL* temp = (*no)->esq;
            free(*no);
            *no = temp;
        } else {
            // Dois filhos: substitui pelo maior da esquerda
            NO_AVL* temp = (*no)->esq;
            while (temp->dir) temp = temp->dir;
            (*no)->chave = temp->chave;
            removeElementoAVL(&(*no)->esq, temp->chave);
        }
    }

    if (*no == NULL) return;

    (*no)->h = 1 + maxAlturaFilhos(no);
    int fB = calculaFB(no);

    // Rebalanceamento
    if (fB == 2) {
        if (calculaFB(&(*no)->dir) >= 0) rotacaoSimplesEsq(no);
        else {
            rotacaoSimplesDir(&(*no)->dir);
            rotacaoSimplesEsq(no);
        }
    } else if (fB == -2) {
        if (calculaFB(&(*no)->esq) <= 0) rotacaoSimplesDir(no);
        else {
            rotacaoSimplesEsq(&(*no)->esq);
            rotacaoSimplesDir(no);
        }
    }
}

void destruirAVL(NO_AVL** no) {
    if (estaVazia(no)) return;
    destruirAVL(&(*no)->esq);
    destruirAVL(&(*no)->dir);
    free(*no);
    *no = NULL;
}
