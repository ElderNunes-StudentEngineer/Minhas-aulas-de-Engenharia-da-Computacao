// Lista_Encadeada.c
#include "Lista_Encadeada.h"

void inicializaLista(LISTA_ENCADEADA* lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

bool estaVazia(LISTA_ENCADEADA* lista) {
    return lista->inicio == NULL;
}

int tamanhoLista(LISTA_ENCADEADA* lista) {
    return lista->tamanho;
}

void insereLista(LISTA_ENCADEADA* lista, char nome[], int rank, char jogo[]) {
    JOGADOR* novo = (JOGADOR*) malloc(sizeof(JOGADOR));
    if (novo == NULL) {
        printf("Não foi possível alocar memória!\n");
        return;
    }

    strcpy(novo->nome, nome);
    strcpy(novo->jogo, jogo);
    novo->rank = rank;
    novo->prox = NULL;

    if (estaVazia(lista) || lista->inicio->rank > rank) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
    } else {
        JOGADOR* aux = lista->inicio;
        while (aux->prox != NULL && aux->prox->rank < rank) {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }

    lista->tamanho++;
}

void adicionarEm(LISTA_ENCADEADA* lista, char nome[], int rank, char jogo[], int pos) {
    if (pos < 0 || pos > lista->tamanho) {
        printf("Posição inválida!\n");
        return;
    }

    JOGADOR* novo = (JOGADOR*) malloc(sizeof(JOGADOR));
    if (!novo) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    strcpy(novo->nome, nome);
    strcpy(novo->jogo, jogo);
    novo->rank = rank;
    novo->prox = NULL;

    if (pos == 0) {
        novo->prox = lista->inicio;
        lista->inicio = novo;
    } else {
        JOGADOR* aux = lista->inicio;
        for (int i = 0; i < pos - 1; i++) {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }

    lista->tamanho++;
}

void removerNoLista(LISTA_ENCADEADA* lista, int rank) {
    if (estaVazia(lista)) {
        printf("Lista Vazia!\n");
        return;
    }

    JOGADOR* atual = lista->inicio;
    JOGADOR* anterior = NULL;

    while (atual != NULL && atual->rank < rank) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->rank == rank) {
        if (anterior == NULL) {
            lista->inicio = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
        lista->tamanho--;
        printf("Rank %d removido com sucesso.\n", rank);
    } else {
        printf("Não foi possível remover da lista. Rank %d não encontrado!\n", rank);
    }
}

void encontrarJogador(LISTA_ENCADEADA* lista, int rank) {
    JOGADOR* atual = lista->inicio;
    if (estaVazia(lista)) {
        printf("Lista Vazia!\n");
        return;
    }

    while (atual != NULL) {
        if (atual->rank == rank) {
            printf("Jogador encontrado!\n");
            printf("Nome: %s | Rank: %d | Jogo: %s\n", atual->nome, atual->rank, atual->jogo);
            return;
        }
        atual = atual->prox;
    }

    printf("Jogador do rank %d não encontrado!\n", rank);
}

void exibirLista(LISTA_ENCADEADA* lista) {
    if (estaVazia(lista)) {
        printf("Lista Vazia!\n");
        return;
    }

    printf("\n---------------------------- LISTA ----------------------------\n");
    JOGADOR* aux = lista->inicio;
    while (aux != NULL) {
        printf("Nome: %s | Rank: %d | Jogo: %s\n", aux->nome, aux->rank, aux->jogo);
        aux = aux->prox;
    }
    printf("--------------------------------------------------------------\n");
}

void liberarLista(LISTA_ENCADEADA* lista) {
    JOGADOR* aux = NULL;
    while (lista->inicio != NULL) {
        aux = lista->inicio;
        lista->inicio = aux->prox;
        free(aux);
    }
    lista->tamanho = 0;
}
