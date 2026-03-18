#include "Veterinaria.h"
//Fila Normal

void iniciaFila(FILA *f) {
    f->inicio = f->fim = NULL;
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
    
    strncpy(novo->NomePet, nomePet, TAM_NOME - 1);
    novo->NomePet[TAM_NOME - 1] = '\0';
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
        printf("| %-23s | %-11s |\n", "NULL", "NULL");
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

void pesquisarNaFila(FILA *fila, char nomePet[]) {
    NO *aux = fila->inicio;
    bool encontrado = false;
    
    while (aux != NULL) {
        if (strcmp(aux->NomePet, nomePet) == 0) {
            printf("Paciente %s encontrado na fila normal!\n", nomePet);
            encontrado = true;
            break;
        }
        aux = aux->prox;
    }

    if (!encontrado) {
        printf("Paciente %s não encontrado na fila normal.\n", nomePet);
    }
}

bool salvaFila(FILA *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return false;
    }

    NO *aux = f->inicio;
    while (aux != NULL) {
        fwrite(aux, sizeof(NO), 1, arquivo);
        aux = aux->prox;
    }

    fclose(arquivo);
    return true;
}

bool carregaFila(FILA *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return false;
    }

    NO temp;
    while (fread(&temp, sizeof(NO), 1, arquivo)) {
        insereNaFila(f, temp.NomePet);
    }

    fclose(arquivo);
    return true;
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

    strncpy(NovoNo->NomePet, NomePet, TAM_NOME - 1);
    NovoNo->NomePet[TAM_NOME - 1] = '\0';    
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
    printf("| %-23s | %-11s |\n", "Nome do Pet", "Prioridade");
    printf("+------------------------------+-------+\n");

    if (aux == NULL) {
        printf("| %-23s | %-11s |\n", "NULL", "NULL");
    }

    while (aux != NULL) {
        printf("| %-23s | %11d |\n", aux->NomePet, aux->prioridade);
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

void pesquisarNaFilaOrd(FILAORD *fila, char NomePet[]) {
    NO *aux = fila->cabeca;
    bool encontrado = false;

    while (aux != NULL) {
        if (strcmp(aux->NomePet, NomePet) == 0) {
            printf("Paciente %s encontrado na fila prioritária!\n", NomePet);
            encontrado = true;
            break;
        }
        aux = aux->prox;
    }

    if (!encontrado) {
        printf("Paciente %s não encontrado na fila prioritária.\n", NomePet);
    }
}

bool salvaFilaOrd(FILAORD *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return false;
    }

    NO *aux = f->cabeca;
    while (aux != NULL) {
        fwrite(aux, sizeof(NO), 1, arquivo);
        aux = aux->prox;
    }

    fclose(arquivo);
    return true;
}

bool carregaFilaOrd(FILAORD *f, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return false;
    }

    NO temp;
    while (fread(&temp, sizeof(NO), 1, arquivo)) {
        inseriNovoPET(f, temp.NomePet, temp.prioridade);
    }

    fclose(arquivo);
    return true;
}


