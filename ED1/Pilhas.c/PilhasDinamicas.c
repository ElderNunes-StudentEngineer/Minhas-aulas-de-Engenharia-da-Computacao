#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct objeto{
    int CPF;
    char nome[30];
    int idade;
    struct objeto *prox;
}OBJETO;

typedef struct{
    OBJETO *topo;
    int qtd_Elementos;
}PILHA_DINAMICA;

void inicializa_Pilha(PILHA_DINAMICA *pilha){
    pilha->qtd_Elementos = 0;
    pilha->topo = NULL;
}//inicializa_Pilha

bool estaVazia(PILHA_DINAMICA *pilha){
    return pilha->qtd_Elementos == 0;
}//estaVazia

int tamanhoPilha(PILHA_DINAMICA *pilha){
    return pilha->qtd_Elementos;
}//tamanhoPilha

void empilha(PILHA_DINAMICA *pilha, int cpf, char nome[], int idade){  
    OBJETO *aux = (OBJETO*)malloc(sizeof(OBJETO)); 
    if(aux == NULL){
        printf("Não foi possível alocar memória!\n");
        return;
    }//if

    aux->CPF = cpf;
    strcpy(aux->nome, nome);
    aux->idade = idade;

    aux->prox = pilha->topo;
    pilha->topo = aux;

    pilha->qtd_Elementos++;
}//empilha

OBJETO* topo(PILHA_DINAMICA *pilha){
    return pilha->topo;
}//topo

void remover(PILHA_DINAMICA *pilha){
    OBJETO *aux = pilha->topo;
    if(aux == NULL){
        printf("Pilha Vazia!\n");
        return;
    }//if

    pilha->topo = aux->prox;
    free(aux);
    pilha->qtd_Elementos--;
}//remove

void imprimeTopo(PILHA_DINAMICA *pilha){
    if(estaVazia(pilha) == true){
        printf("\nA pilha está vazia!\n");
        return;
    }//if
    printf("\n===================================================\n");
    printf("Nome: %s | CPF: %d | idade: %d", pilha->topo->nome, pilha->topo->CPF, pilha->topo->idade);
    printf("\n===================================================\n");
}//imprimeTopo

void destruirPilha(PILHA_DINAMICA *pilha){
    while(estaVazia(pilha) == true){
        remover(pilha);
    }//while
}//destruirPilha

int main(){

    PILHA_DINAMICA p;

    inicializa_Pilha(&p);
    empilha(&p, 12345, "Elder Nunes", 19);
    empilha(&p, 15456, "Felipe Campos", 32);
    empilha(&p, 98766, "Hugo Santos", 56);
    remover(&p);

    imprimeTopo(&p);

    destruirPilha(&p);

    return 0;
}//main