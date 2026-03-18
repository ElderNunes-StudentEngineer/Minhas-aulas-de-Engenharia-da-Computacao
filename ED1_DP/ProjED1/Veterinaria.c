#include "Veterinaria.h"

//Fila Normal

void iniciaFila(FILA *f) {
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
}

bool verificaFilaVazia(FILA* fila){ 
    return fila->inicio == NULL;
}

void insereNaFila(FILA* fila, char nomePet[]){
    NO* novo = (NO*) malloc(sizeof(NO));
    if(novo == NULL){
        printf("Erro ao alocar memória!\n");
        return;
    }

    strcpy(novo->NomePet, nomePet);
    novo->prioridade = 0;
    novo->prox = NULL;

    if(verificaFilaVazia(fila)){
        fila->inicio = novo;
    }else{
        fila->fim->prox = novo;
    }

    fila->fim = novo;
    fila->tamanho++;
}

void exibeFila(FILA* fila){
    NO* aux = fila->inicio;

    printf("\nFila de Consultas Não Urgentes (FIFO):\n");
    printf("+-------------------------+-------------+\n");
    printf("| %-23s | %-11s |\n", "Nome do Pet", "Prioridade");
    printf("+-------------------------+-------------+\n");

    if (aux == NULL) {
        printf("| %-23s | %-11s |\n", "VAZIA", "0");
    }

    while (aux != NULL) {
        printf("| %-23s | %-11d |\n", aux->NomePet, aux->prioridade);
        aux = aux->prox;
    }

    printf("+-------------------------+-------------+\n");
    printf("Total na fila: %d\n", fila->tamanho);
}

void liberaFila(FILA *fila) {
    NO *aux = fila->inicio;
    while (aux != NULL) {
        NO *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

//Fila ordenada

void iniciaFilaOrd(FILAORD *f) {
    f->cabeca = NULL;
    f->tamanho = 0;
}

void inseriNovoPET(FILAORD *f, char NomePet[], int Prioridade) {
    NO *NovoNo = (NO *)malloc(sizeof(NO));
    if (NovoNo == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    strcpy(NovoNo->NomePet, NomePet);
    NovoNo->prioridade = Prioridade;
    NovoNo->prox = NULL;

    if (f->cabeca == NULL || NovoNo->prioridade > f->cabeca->prioridade) {
        NovoNo->prox = f->cabeca;
        f->cabeca = NovoNo;
    } else {
        NO *aux = f->cabeca;
        NO *anterior = NULL;

        while (aux != NULL && NovoNo->prioridade <= aux->prioridade) {
            anterior = aux;
            aux = aux->prox;
        }

        anterior->prox = NovoNo;
        NovoNo->prox = aux;
    }
    f->tamanho++;
}

void exibePrioridades(FILAORD *f) {
    NO *aux = f->cabeca;

    printf("\nFila de Prioridades:\n");
    printf("+------------------------------+-------+\n");
    printf("| %-28s | %-5s |\n", "Nome do Pet", "Prior.");
    printf("+------------------------------+-------+\n");

    if (aux == NULL) {
        printf("| %-28s | %-5s |\n", "FILA VAZIA", "0");
    }

    while (aux != NULL) {
        printf("| %-28s | %-5d |\n", aux->NomePet, aux->prioridade);
        aux = aux->prox;
    }

    printf("+------------------------------+-------+\n");
    printf("Total na fila: %d\n", f->tamanho);
}

void liberaFilaOrd(FILAORD *f) {
    NO *aux = f->cabeca;
    while (aux != NULL) {
        NO *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    f->cabeca = NULL;
    f->tamanho = 0;
}