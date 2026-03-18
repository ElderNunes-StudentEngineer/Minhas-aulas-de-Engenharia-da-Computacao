#include "PIlha.h"

void inicializaPilha(PILHA* p) {
    p->topo = NULL;
    p->tamanho = 0;
}

bool estaVazia(PILHA* p) {
    return p->topo == NULL;
}

int tamanhoPilha(PILHA* p) {
    return p->tamanho;
}

void inserePilha(PILHA* p, int d) {
    NO* aux = (NO*) malloc(sizeof(NO));
    if (aux == NULL) {
        printf("Não foi possível alocar memória!\n");
        return;
    }
    aux->dado = d;
    aux->prox = p->topo;
    p->topo = aux;
    p->tamanho++;
}

int removerPilha(PILHA* p) {
    if (estaVazia(p)) {
        printf("Pilha vazia! Nada para remover.\n");
        return -1;
    }
    NO* aux = p->topo;
    int valor = aux->dado;
    p->topo = aux->prox;
    free(aux);
    p->tamanho--;
    return valor;
}

void exibirPilha(PILHA* p){
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    NO* aux = p->topo;

    printf("Exibindo Pilha...\n");
    while(aux != NULL){
        printf("%d\n", aux->dado);
        aux = aux->prox;
    }
}
