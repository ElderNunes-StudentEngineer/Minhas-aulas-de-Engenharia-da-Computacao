#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct objeto{
    int CPF;
    int idade;
    char nome[30];
    struct objeto *prox;
}OBJETOS;

typedef struct{
    OBJETOS* inicio;
    OBJETOS* final;
    int tamanho;
}FILA_DINAMICA;

void iniciaFila(FILA_DINAMICA* fila){
    fila->inicio = fila->final = NULL;
    fila->tamanho = 0;
}//iniciaFila

bool estaVazia(FILA_DINAMICA* fila){
    return fila->tamanho == 0;
}//estaVazia

int tamanho(FILA_DINAMICA* fila){
    return fila->tamanho;
}//tamanho

void insereFila(FILA_DINAMICA* fila, int cpf, char nome[], int idade){
    OBJETOS* aux = (OBJETOS*) malloc(sizeof(OBJETOS));
    if(aux == NULL){
        printf("Erro ao alocar memória!\n");
        return;
    }//if

    aux->CPF = cpf;
    aux->idade = idade;
    strcpy(aux->nome, nome);
    aux->prox = NULL;

    if(estaVazia(fila) == true){
        fila->inicio = aux;
    }else{
        fila->final->prox = aux;
    }//else

    fila->tamanho++;
    fila->final = aux;

}//insereFila

void removerElemento(FILA_DINAMICA* fila){
    OBJETOS* aux = fila->inicio;
    if(estaVazia(fila) == true){
        printf("Fila Vazia!\n");
        return;
    }//if

        fila->inicio = fila->inicio->prox;
        free(aux);
        fila->tamanho = fila->tamanho - 1;

}//removerElemento;

void imprimePrimeiroFila(FILA_DINAMICA* fila){
    if(estaVazia(fila) == true){
        printf("Fila Vazia!\n");
        return;
    }//if
    printf("===============================================================\n");
    printf("Primeiro da Fila | Nome: %s | CPF: %d | Idade: %d\n", fila->inicio->nome, 
                                                                  fila->inicio->CPF, 
                                                                  fila->inicio->idade);
    printf("===============================================================\n");

}//imprimePrimeiroFila

void imprimeUltimoFila(FILA_DINAMICA* fila){
    if(estaVazia(fila) == true){
        printf("Fila Vazia!\n");
        return;
    }//if
    printf("===============================================================\n");
    printf("Último da Fila | Nome: %s | CPF: %d | Idade: %d\n", fila->final->nome, 
                                                                fila->final->CPF, 
                                                                fila->final->idade);
    printf("===============================================================\n");
}//imprimeUltimoFila

void imprimeElementos(FILA_DINAMICA* fila){
    if(estaVazia(fila) == true){
        printf("Fila Vazia!\n");
        return;
    }//if

    OBJETOS* aux = fila->inicio;
    printf("====================================================================\n");
    while(aux != NULL){
    printf("Nome: %s | CPF: %d | Idade: %d\n", aux->nome, aux->CPF, aux->idade);
    aux = aux->prox;
    }//for
    printf("====================================================================\n");

}//imprimeElementos

void destroiFila(FILA_DINAMICA* fila){
    if(!estaVazia(fila)){
        removerElemento(fila);
    }//if
}//destroiFila

int main(){

    FILA_DINAMICA f;

    iniciaFila(&f);
    insereFila(&f, 12345, "Elder Nunes", 19);
    insereFila(&f, 54321, "Felipe Nunes", 13);
    insereFila(&f, 55543, "LUcas Nunes", 32);
    insereFila(&f, 11222, "Gui Nunes", 29);
    //imprimeElementos(&f);
    
    removerElemento(&f);

    imprimePrimeiroFila(&f);
    imprimeUltimoFila(&f);
    destroiFila(&f);

    return 0;
}//main