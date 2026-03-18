#include "fila.h"

int main(void){
    FILA_DINAMICA f;
    inicializaFila(&f);

    insereFila(&f, "Elder", 12345, 19);
    insereFila(&f, "Lucas", 34567, 21);
    insereFila(&f, "Gui", 54464, 26);
    insereFila(&f, "Kiko", 11122, 29);

    imprimeFila(&f);

    printf("Removendo elemento da fila...\n");
    OBJETOS* removido = removeElemento(&f);
    if(removido != NULL){
    printf("Removido: %s(CPF: %d)\n", removido->nome, removido->CPF);
    free(removido);
    }
    
    imprimeFila(&f);

    imprimePrimeiroFila(&f);
    imprimeUltimoFila(&f);

    pesquisaElemento(&f, 11122);

    destroiFila(&f);
    return 0;
}