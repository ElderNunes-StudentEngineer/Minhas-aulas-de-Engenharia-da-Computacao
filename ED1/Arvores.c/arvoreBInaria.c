#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct noArvore {
    int chave;
    struct noArvore* esq;
    struct noArvore* dir;
} NO_ARVORE;

void inicializaArvore(NO_ARVORE** raiz) {
    (*raiz) = NULL;
}

// Verifica se a árvore está vazia
bool estaVazia(NO_ARVORE** raiz) {
    return (*raiz) == NULL;
}

// Função para inserir um nó na árvore binária de busca
void insereArvore(NO_ARVORE** no, int ch) {
    if (estaVazia(no)) {
        (*no) = (NO_ARVORE*)malloc(sizeof(NO_ARVORE));
        if ((*no) == NULL) {
            printf("Não foi possível alocar memória!\n");
            return;
        }
        (*no)->dir = (*no)->esq = NULL;
        (*no)->chave = ch;
        return;
    }
    if ((*no)->chave == ch) return;  // Não permite valores duplicados
    if ((*no)->chave > ch) insereArvore(&(*no)->esq, ch);
    else insereArvore(&(*no)->dir, ch);
}

// Função de travessia pré-ordem
void preOrdem(NO_ARVORE** no) {
    if (estaVazia(no)) return;
    printf(" %d ", (*no)->chave);
    preOrdem(&(*no)->esq);
    preOrdem(&(*no)->dir);
}

// Função de travessia em ordem
void emOrdem(NO_ARVORE** no) {
    if (estaVazia(no)) return;
    emOrdem(&(*no)->esq);
    printf(" %d ", (*no)->chave);
    emOrdem(&(*no)->dir);
}

// Função de travessia pós-ordem
void posOrdem(NO_ARVORE** no) {
    if (estaVazia(no)) return;
    posOrdem(&(*no)->esq);
    posOrdem(&(*no)->dir);
    printf(" %d ", (*no)->chave);
}

// Função para buscar um elemento na árvore
void buscarArvore(NO_ARVORE** no, int ch) {
    if (estaVazia(no)) {
        printf("\nElemento não encontrado!\n");
        return;
    }
    if ((*no)->chave == ch) {
        printf("\nElemento encontrado: %d\n", ch);
        return;
    } else {
        if ((*no)->chave > ch) buscarArvore(&(*no)->esq, ch);
        else buscarArvore(&(*no)->dir, ch);
    }
}

// Função para remover um nó na árvore
void remocaoElemento(NO_ARVORE** no, int ch) {
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
            remocaoElemento(&(*no)->esq, (*no)->chave);  // Remove o nó duplicado
            return;
        }
    } else {
        if ((*no)->chave > ch) remocaoElemento(&(*no)->esq, ch);
        else remocaoElemento(&(*no)->dir, ch);
    }
}

// Função para destruir a árvore
void destruirArvore(NO_ARVORE** no) {
    if (estaVazia(no)) return;
    destruirArvore(&(*no)->esq);
    destruirArvore(&(*no)->dir);
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
    inicializaArvore(&raiz);

    // Inserção de elementos
    insereArvore(&raiz, 65);
    insereArvore(&raiz, 42);
    insereArvore(&raiz, 51);
    insereArvore(&raiz, 32);
    insereArvore(&raiz, 12);
    insereArvore(&raiz, 38);
    insereArvore(&raiz, 80);
    insereArvore(&raiz, 92);
    insereArvore(&raiz, 71);
    insereArvore(&raiz, 69);
    insereArvore(&raiz, 60);
    insereArvore(&raiz, 90);

    // Exibindo as travessias
    printf("Pré-Ordem:\n");
    preOrdem(&raiz);
    printf("\nEm Ordem:\n");
    emOrdem(&raiz);
    printf("\nPós-Ordem:\n");
    posOrdem(&raiz);
    printf("\n");

    // Buscar elementos
    printf("\nBuscar Elementos:\n");
    buscarArvore(&raiz, 38);
    buscarArvore(&raiz, 93);
    buscarArvore(&raiz, 69);

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

    // Remover e destruir a árvore
    printf("\nRemoção de elementos:\n");
    remocaoElemento(&raiz, 3);
    remocaoElemento(&raiz, 4);
    remocaoElemento(&raiz, 12);
    remocaoElemento(&raiz, 92);
    remocaoElemento(&raiz, 38);
    remocaoElemento(&raiz, 38);


    // Destruir a árvore
    destruirArvore(&raiz);
    printf("\n");

    return 0;
}