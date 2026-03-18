#include "Lista_Encadeada.h"

int main(void){ 
    LISTA_ENCADEADA f;
    inicializaLista(&f);

    printf("Inserindo elementos na fila...\n");
    insereLista(&f,"Elder",1, "LOL");
    insereLista(&f, "Lucas", 2, "FIFA");

    adicionarEm(&f, "Felipe", 4, "LOL", 2);

    exibirLista(&f);

    removerNoLista(&f, 2);

    encontrarJogador(&f, 2);
    encontrarJogador(&f, 1);

    exibirLista(&f);

    liberarLista(&f);


    return 0;
}
