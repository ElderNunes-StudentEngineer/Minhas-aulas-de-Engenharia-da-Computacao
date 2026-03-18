#include <stdio.h>
#include "PIlha.h"

int main() {
    PILHA p;
    inicializaPilha(&p);

    printf("Inserindo elementos na pilha...\n");
    inserePilha(&p, 10);
    inserePilha(&p, 20);
    inserePilha(&p, 30);

    exibirPilha(&p);

    printf("Tamanho atual da pilha: %d\n", tamanhoPilha(&p));
    printf("A pilha está vazia? %s\n", estaVazia(&p) ? "Sim" : "Não");

    int removido = removerPilha(&p);
    printf("Removido: %d\n", removido);

    exibirPilha(&p);

    printf("Tamanho final da pilha: %d\n", tamanhoPilha(&p));
    return 0;
}
