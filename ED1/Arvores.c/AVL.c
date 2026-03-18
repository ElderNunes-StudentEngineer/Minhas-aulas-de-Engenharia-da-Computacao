#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noArvore {
    int chave;
    struct noArvore* esq;
    struct noArvore* dir;
    int h;
} NO_ARVORE;

void inicializaAVL(NO_ARVORE** raiz) {
    (*raiz) = NULL;
}

// Verifica se a árvore está vazia
bool estaVaziaAVL(NO_ARVORE** raiz) {
    return (*raiz) == NULL;
}

int maxAlturaFilhos(NO_ARVORE** no){
    int hE, hD;
    if((*no)->esq != NULL) hE = (*no)->esq->h;
    else hE = -1;
    if((*no)->dir != NULL) hD = (*no)->dir->h;
    else hD = -1;

    return hE>hD ? hE : hD;
}

int calculaFB(NO_ARVORE** no){
    int fB, hD, hE;
    hD = (*no)->dir != NULL ? (*no)->dir->h : -1; // altura do filho direita
    hE = (*no)->esq != NULL ? (*no)->esq->h : -1; // altura do filho esquerda
    return (fB = hD - hE); // calculo do fator de balanceamento do nó
}

void rotacaoSimplesEsquerda(NO_ARVORE** no){
    NO_ARVORE *aux = (*no)->dir;
    (*no)->dir = aux->esq;
    aux->esq=(*no);
    (*no)=aux;
    (aux)->esq->h = 1+ maxAlturaFilhos(&(*no)->esq);
    (*no)->h = 1+maxAlturaFilhos(no);
}

void rotacaoSimplesDireita(NO_ARVORE** no){
    NO_ARVORE* aux = (*no)->esq;
    (*no)->esq = aux->dir;
    aux->dir=(*no);
    (*no)=aux;
    (aux)->dir->h = 1+maxAlturaFilhos(&(*no)->dir);
    (*no)->h = 1+maxAlturaFilhos(no);
}

// Função para inserir um nó na árvore binária de busca
void insereAVL(NO_ARVORE** no, int ch) {
    if (estaVaziaAVL(no)) {
        (*no) = (NO_ARVORE*)malloc(sizeof(NO_ARVORE));
        if ((*no) == NULL) {
            printf("Não foi possível alocar memória!\n");
            return;
        }
        (*no)->dir = (*no)->esq = NULL;
        (*no)->chave = ch;
        (*no)->h = 0;
        return;
    }
    if ((*no)->chave == ch) return;  // Não permite valores duplicados
    if ((*no)->chave > ch) insereAVL(&(*no)->esq, ch);
    else insereAVL(&(*no)->dir, ch);
    (*no)->h = 1 + maxAlturaFilhos(no);
    int fB = calculaFB(no); // calculo do fator de balanceamento do nó

    switch (fB)
    {
    case 2: //rotação à esquerda
        switch(calculaFB(&(*no)->dir)){//consultar o fb do filho a direita
            case 0:
            case +1://rotação simples à esquerda
                rotacaoSimplesEsquerda(no);
                break;

            case -1://rotação dupla à esquerda
                rotacaoSimplesDireita(&(*no)->dir);
                rotacaoSimplesEsquerda(no);
                break;    
        }

        break;

    case -2://rotação à direita
        switch(calculaFB(&(*no)->esq)){//consultar o fb do filho a esquerda
            case 0:
            case -1://rotação simples à direita
                rotacaoSimplesDireita(no);
                break;

            case +1://rotação dupla à direita
                rotacaoSimplesEsquerda(&(*no)->esq);
                rotacaoSimplesDireita(no);
                break;    
        }
        break;
    }

}

// Função de travessia pré-ordem
void preOrdem(NO_ARVORE** no) {
    if (estaVaziaAVL(no)) return;
    printf("\n info = %d[h = %d] \n", (*no)->chave, (*no)->h);
    preOrdem(&(*no)->esq);
    preOrdem(&(*no)->dir);
}

// Função de travessia em ordem
void emOrdem(NO_ARVORE** no) {
    if (estaVaziaAVL(no)) return;
    emOrdem(&(*no)->esq);
    printf(" %d ", (*no)->chave);
    emOrdem(&(*no)->dir);
}

// Função de travessia pós-ordem
void posOrdem(NO_ARVORE** no) {
    if (estaVaziaAVL(no)) return;
    posOrdem(&(*no)->esq);
    posOrdem(&(*no)->dir);
    printf(" %d ", (*no)->chave);
}

// Função para buscar um elemento na árvore
void buscarAVL(NO_ARVORE** no, int ch) {
    if (estaVaziaAVL(no)) {
        printf("\nElemento não encontrado!\n");
        return;
    }
    if ((*no)->chave == ch) {
        printf("\nElemento encontrado: %d\n", ch);
        return;
    } else {
        if ((*no)->chave > ch) buscarAVL(&(*no)->esq, ch);
        else buscarAVL(&(*no)->dir, ch);
    }
}

// Função para remover um nó na árvore
void remocaoElemento(NO_ARVORE** no, int ch) {
    if (estaVaziaAVL(no)) {
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
            remocaoElemento(&(*no)->esq, (*no)->chave);  // Remove o nó duplicado
            return;
        }
    } else {
        if ((*no)->chave > ch) remocaoElemento(&(*no)->esq, ch);
        else remocaoElemento(&(*no)->dir, ch);
    }

    (*no)->h = 1 + maxAlturaFilhos(no);
    int fB = calculaFB(no); // calculo do fator de balanceamento do nó

    switch (fB)
    {
    case 2: //rotação à esquerda
        switch(calculaFB(&(*no)->dir)){//consultar o fb do filho a direita
            case 0:
            case +1://rotação simples à esquerda
                rotacaoSimplesEsquerda(no);
                break;

            case -1://rotação dupla à esquerda
                rotacaoSimplesDireita(&(*no)->dir);
                rotacaoSimplesEsquerda(no);
                break;    
        }

        break;

    case -2://rotação à direita
        switch(calculaFB(&(*no)->esq)){//consultar o fb do filho a esquerda
            case 0:
            case -1://rotação simples à direita
                rotacaoSimplesDireita(no);
                break;

            case +1://rotação dupla à direita
                rotacaoSimplesEsquerda(&(*no)->esq);
                rotacaoSimplesDireita(no);
                break;    
        }
        break;
}
}

// Função para destruir a árvore
void destruirAVL(NO_ARVORE** no) {
    if (estaVaziaAVL(no)) return;
    destruirAVL(&(*no)->esq);
    destruirAVL(&(*no)->dir);
    free(*no);
    (*no) = NULL;
}

// Função para encontrar o maior elemento da árvore (máximo)
int max(NO_ARVORE* no) {
    if (no == NULL) return -1; // Ou outro valor indicando que a árvore está vazia
    while (no->dir != NULL) {
        no = no->dir;
    }
    return no->chave;
}

// Função para encontrar o menor elemento da árvore (mínimo)
int min(NO_ARVORE* no) {
    if (no == NULL) return -1; // Ou outro valor indicando que a árvore está vazia
    while (no->esq != NULL) {
        no = no->esq;
    }
    return no->chave;
}

// Função para calcular o tamanho da árvore
int tamanho(NO_ARVORE* no) {
    if (no == NULL) return 0;
    return 1 + tamanho(no->esq) + tamanho(no->dir);
}

// Função para encontrar o próximo elemento (sucessor)
NO_ARVORE* proximo(NO_ARVORE* no) {
    if (no == NULL) return NULL;
    if (no->dir != NULL) {
        no = no->dir;
        while (no->esq != NULL) {
            no = no->esq;
        }
        return no;
    }
    NO_ARVORE* pai = NULL;
    NO_ARVORE* raiz = no;
    while (raiz != NULL) {
        if (raiz->chave > no->chave) {
            pai = raiz;
            raiz = raiz->esq;
        } else if (raiz->chave < no->chave) {
            raiz = raiz->dir;
        } else {
            break;
        }
    }
    return pai;
}

// Função para encontrar o anterior (antecessor)
NO_ARVORE* anterior(NO_ARVORE* no) {
    if (no == NULL) return NULL;
    if (no->esq != NULL) {
        no = no->esq;
        while (no->dir != NULL) {
            no = no->dir;
        }
        return no;
    }
    NO_ARVORE* pai = NULL;
    NO_ARVORE* raiz = no;
    while (raiz != NULL) {
        if (raiz->chave < no->chave) {
            pai = raiz;
            raiz = raiz->dir;
        } else if (raiz->chave > no->chave) {
            raiz = raiz->esq;
        } else {
            break;
        }
    }
    return pai;
}

// Função principal para testar
int main(void) {
    NO_ARVORE *raiz;
    inicializaAVL(&raiz);

    // Inserção de elementos
    insereAVL(&raiz, 10);
    insereAVL(&raiz, 15);
    insereAVL(&raiz, 13);
    insereAVL(&raiz, 6);
    insereAVL(&raiz, 3);
    insereAVL(&raiz, 5);
    insereAVL(&raiz, 4);
    insereAVL(&raiz, 32);
    insereAVL(&raiz, 12);
    insereAVL(&raiz, 38);
    insereAVL(&raiz, 80);
    insereAVL(&raiz, 92);
    insereAVL(&raiz, 71);
    insereAVL(&raiz, 69);
    insereAVL(&raiz, 60);
    insereAVL(&raiz, 90);

    // Exibindo as travessias
    printf("Pré-Ordem:\n");
    preOrdem(&raiz);
    /*
    printf("\nEm Ordem:\n");
    emOrdem(&raiz);
    printf("\nPós-Ordem:\n");
    posOrdem(&raiz);
    printf("\n");

    // Buscar elementos
    printf("\nBuscar Elementos:\n");
    buscarAVL(&raiz, 38);
    buscarAVL(&raiz, 93);
    buscarAVL(&raiz, 69);

    // Funções max, min e tamanho
    printf("\nMáximo: %d\n", max(raiz));
    printf("Mínimo: %d\n", min(raiz));
    printf("Tamanho: %d\n", tamanho(raiz));

    // Testando sucessor e antecessor
    NO_ARVORE* no = raiz; // Vamos testar o sucessor e antecessor de 65
    NO_ARVORE* next = proximo(no);
    NO_ARVORE* prev = anterior(no);
    if (next != NULL) printf("Próximo de %d: %d\n", no->chave, next->chave);
    if (prev != NULL) printf("Anterior de %d: %d\n", no->chave, prev->chave);
*/
    // Remover e destruir a árvore
    printf("\nRemoção de elementos:\n");
    remocaoElemento(&raiz, 80);

    printf("Pré-Ordem:\n");
    preOrdem(&raiz);


    // Destruir a árvore
    destruirAVL(&raiz);
    printf("\n");

    return 0;
}