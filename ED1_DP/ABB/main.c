#include "ABB.h"

int main(void){
    NO_ARVORE *raiz;
    inicializaABB(&raiz);

    insereABB(&raiz, 65);
    insereABB(&raiz, 42);
    insereABB(&raiz, 51);

    printf("Pré-Ordem:\n");
    preOrdem(&raiz);
    printf("\nEm Ordem:\n");
    emOrdem(&raiz);
    printf("\nPós-Ordem:\n");
    posOrdem(&raiz);
    printf("\n");

    printf("\nBuscar Elementos:\n");
    printf("Elemento %d: %s\n", 38 ,pesquisaABB(&raiz, 38) ? "Encontrado" : "Não encontrado");
    printf("Elemento %d: %s\n", 42 ,pesquisaABB(&raiz, 42) ? "Encontrado" : "Não encontrado");   
    
    printf("\nRemoção de elementos:\n");
    removeABB(&raiz, 3);
    removeABB(&raiz, 42);

    destruirABB(&raiz);
    printf("\n");

    return 0;
}
