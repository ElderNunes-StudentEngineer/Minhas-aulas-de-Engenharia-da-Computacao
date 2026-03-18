#include "AVL.h"

int main(void) {
    NO_AVL* raiz;
    inicializaAVL(&raiz);

    // Inserções
    insereAVL(&raiz, 10);
    insereAVL(&raiz, 15);
    insereAVL(&raiz, 13);
    insereAVL(&raiz, 6);
    insereAVL(&raiz, 3);
    insereAVL(&raiz, 5);
    insereAVL(&raiz, 4);

    printf("Pré-Ordem após inserções:\n");
    preOrdem(&raiz);
    printf("\n");

    // Tentativa de remoção
    printf("\nRemovendo elemento...\n");
    removeElementoAVL(&raiz, 13);


    printf("\nPré-Ordem após remoção:\n");
    preOrdem(&raiz);
    printf("\n");

    // Limpeza final
    destruirAVL(&raiz);
    printf("\nÁrvore destruída.\n");

    return 0;
}
