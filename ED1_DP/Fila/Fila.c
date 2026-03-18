#include "fila.h"

void inicializaFila(FILA_DINAMICA* f){
    f->inicio = f->final = NULL;
    f->tamanho = 0;
}

bool estaVazia(FILA_DINAMICA* f){
    return f->tamanho == 0;
}

int tamanhoFila(FILA_DINAMICA* f) {
    return f->tamanho;
}

//Ordenar por idade crescente
void insereFila(FILA_DINAMICA* f, char nome[], int cpf, int idade){
    OBJETOS* novo = (OBJETOS*) malloc(sizeof(OBJETOS));
    if(novo == NULL){
        printf("Erro ao alocar memória!\n");
        return;
    }

    novo->CPF = cpf;
    novo->idade = idade;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if(estaVazia(f)){ //inserir na fila vazia
        f->inicio = f->final = novo;
    }else if(idade < f->inicio->idade){ //inserir no início da fila
        novo->prox = f->inicio;
        f->inicio = novo;
    }else{ //inserir no meio ou no final
        OBJETOS* atual = f->inicio;
        while(atual->prox != NULL && idade >= atual->prox->idade){
            atual = atual->prox;
        }

        novo->prox = atual->prox; 
        atual->prox = novo;

        if(novo->prox == NULL){
            f->final = novo; // atualiza o fim se foi inserido no final
        }

    }

    f->tamanho++;
}

    OBJETOS* removeElemento(FILA_DINAMICA* fila){
    if(estaVazia(fila)){
        printf("Fila Vazia!\n");
        return NULL;
    }

    OBJETOS* aux = fila->inicio;

    fila->inicio = fila->inicio->prox;
    aux->prox = NULL;
    fila->tamanho--;

    if (fila->inicio == NULL) {
        fila->final = NULL;
    }

    return aux;
}

void imprimePrimeiroFila(FILA_DINAMICA* fila){
    if(estaVazia(fila) == true){
        printf("Fila Vazia!\n");
        return;
    }
    printf("\n---------------------------------\n");
    printf("Imprimindo Primeiro da Fila...\n");
    printf("Nome: %s| CPF: %d| Idade: %d", fila->inicio->nome, fila->inicio->CPF, fila->inicio->idade);
    printf("\n---------------------------------\n");
}

void imprimeUltimoFila(FILA_DINAMICA* fila){
    if(estaVazia(fila) == true){
        printf("Fila Vazia!\n");
        return;
    }
    printf("\n---------------------------------\n");
    printf("Imprimindo Último da Fila...\n");
    printf("Nome: %s| CPF: %d| Idade: %d", fila->final->nome, fila->final->CPF, fila->final->idade);
    printf("\n---------------------------------\n");
}

void imprimeFila(FILA_DINAMICA* fila){
    OBJETOS* aux = fila->inicio;
    if(estaVazia(fila) == true){
        printf("Fila Vazia!\n");
        return;
    }
    printf("\n---------------------------------\n");
    printf("Imprimindo Fila...\n");
    while(aux != NULL){
        printf("Nome: %s| CPF: %d| Idade: %d\n", aux->nome, aux->CPF, aux->idade);
        aux = aux->prox;
    }
    printf("\n---------------------------------\n");
}

void destroiFila(FILA_DINAMICA* fila){
    while(!estaVazia(fila)){
        removeElemento(fila);
    }
}

void pesquisaElemento(FILA_DINAMICA* fila, int cpf){
    if(estaVazia(fila) == true){
        printf("Fila Vazia!\n");
        return;
    }

    OBJETOS* aux = fila->inicio;
    while(aux != NULL){
        if(cpf == aux->CPF){
            printf("Elemento encontrado!\n");
            printf("Nome: %s| CPF: %d| Idade: %d\n", aux->nome, aux->CPF, aux->idade);
            return;
        }
        aux = aux->prox;
    }

    printf("Elemento com CPF %d não encontrado na fila.\n", cpf);

}