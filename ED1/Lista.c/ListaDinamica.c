#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct objeto {
    int CPF;
    char nome[30];
    int idade;
    struct objeto* prox;
} OBJETO;

typedef struct {
    OBJETO* inicio;
    int tamanho;
} LISTA_DINAMICA;

void iniciaLista(LISTA_DINAMICA* lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}//iniciaLista

bool estaVazia(LISTA_DINAMICA* lista) {
    return lista->tamanho == 0;
}//estaVazia

int tamanhoLista(LISTA_DINAMICA* lista) {
    return lista->tamanho;
}//tamanhoLista

// Lista organizada por ordem crescente de idade
void insereLista(LISTA_DINAMICA* lista, int cpf, char nome[], int idade) {
    OBJETO* novo = (OBJETO*) malloc(sizeof(OBJETO));
    if (novo == NULL) {
        printf("Não foi possível alocar memória!\n");
        return;
    }//if

    novo->CPF = cpf;
    novo->idade = idade;
    strcpy(novo->nome, nome);
    novo->prox = NULL;

    if (estaVazia(lista)) {
        lista->inicio = novo;
    } else {
        if (lista->inicio->idade > idade) {
            novo->prox = lista->inicio;
            lista->inicio = novo;
        } else {
            OBJETO* aux = lista->inicio;
            while (aux->prox != NULL && aux->prox->idade < idade) {
                aux = aux->prox;
            }//while
            novo->prox = aux->prox;
            aux->prox = novo;
        }//else
    }//else

    lista->tamanho++;
}//insereLista

void imprimeLista(LISTA_DINAMICA* lista) {
    OBJETO* aux = lista->inicio;
    printf("\n==================================================================\n");
    while (aux != NULL) {
        printf("\n Idade: %d | Nome: %s | CPF: %d", aux->idade, aux->nome, aux->CPF);
        aux = aux->prox;
    }//while
    printf("\n==================================================================\n");
}//imprimeLista

void deletaLista(LISTA_DINAMICA* lista) {
    OBJETO* x = NULL;
    while (lista->inicio != NULL) {
        x = lista->inicio;
        lista->inicio = x->prox;
        free(x);
    }//while
    iniciaLista(lista);
}//deletaLista

void removeElementoLista(LISTA_DINAMICA* lista, int idade) {
    if (estaVazia(lista)) {
        printf("Lista vazia! Não tem nada pra você aqui!\n");
        return;
    }//if

    if (lista->inicio->idade > idade) {
        printf("\nEsta idade %d não esta na lista", idade);
        return;
    }//if

    if (lista->inicio->idade == idade) {
        printf("\n\n O elemento de idade %d foi removido com sucesso", idade);
        OBJETO* aux = lista->inicio;
        lista->inicio = aux->prox;
        free(aux);
        lista->tamanho--;
        return;
    }//if
    OBJETO* aux = lista->inicio;
    while(aux->prox != NULL && aux->prox->idade < idade){
        aux = aux->prox;
    }//while

    if(aux->prox->idade != idade){
        printf("\nEsta idade %d não esta na lista", idade);
        return;
    }else{
        OBJETO* tchau = aux->prox;
        aux->prox = tchau->prox;
        free(tchau);
        lista->tamanho--;
        printf("\nO elemento com idade %d foi removido com sucesso!\n", idade);
        return;
    }//else
}//removeElementoLista

void pesquisaLista(LISTA_DINAMICA* lista, int num) {
    OBJETO* aux = lista->inicio;
    while (aux != NULL) {
        if (aux->CPF == num) {
            printf("Encontrado: Idade: %d | Nome: %s | CPF: %d\n", aux->idade, aux->nome, aux->CPF);
            return;
        }//if
        aux = aux->prox;
    }//while
    printf("\nElemento com CPF %d não encontrado!\n", num);
}//pesquisaLista

void maximoElemento(LISTA_DINAMICA* lista) {
    if (estaVazia(lista)) {
        printf("Lista vazia!\n");
        return;
    }//if
    OBJETO* aux = lista->inicio;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }//while
    printf("\nMáximo: Idade: %d | Nome: %s | CPF: %d\n", aux->idade, aux->nome, aux->CPF);
}//maximoElemento

void minimoElemento(LISTA_DINAMICA* lista) {
    if (estaVazia(lista)) {
        printf("Lista vazia!\n");
        return;
    }//if
    OBJETO* aux = lista->inicio;
    printf("\nMínimo: Idade: %d | Nome: %s | CPF: %d\n", aux->idade, aux->nome, aux->CPF);
}//minimoElemento

void proximoElemento(LISTA_DINAMICA* lista, int cpf) {
    OBJETO* aux = lista->inicio;

    while (aux != NULL) {
        if (aux->CPF == cpf) {
            if (aux->prox != NULL) {
                printf("\nPróximo: Idade: %d | Nome: %s | CPF: %d\n",
                       aux->prox->idade,
                       aux->prox->nome,
                       aux->prox->CPF);
            } else {
                printf("\nNão há próximo elemento!\n");
            }//else
            return;
        }//if
        aux = aux->prox;
    }//while
    printf("\nElemento com CPF %d não encontrado!\n", cpf);
}//proximoElemento

void anteriorElemento(LISTA_DINAMICA* lista, int cpf) {
    OBJETO* aux = lista->inicio;
    OBJETO* anterior = NULL;

    while (aux != NULL) {
        if (aux->CPF == cpf) {
            if (anterior != NULL) {
                printf("\nAnterior: Idade: %d | Nome: %s | CPF: %d\n",
                       anterior->idade,
                       anterior->nome,
                       anterior->CPF);
            } else {
                printf("Não há elemento anterior (é o primeiro elemento)!\n");
            }//else
            return;
        }//if
        anterior = aux;
        aux = aux->prox;
    }//while
    printf("\nElemento com CPF %d não encontrado!\n", cpf);
}//anteriorElemento

int main() {
    LISTA_DINAMICA l;

    iniciaLista(&l);

    insereLista(&l, 12345, "Elder Nunes", 19);
    insereLista(&l, 54321, "Daniel Elder", 20);
    insereLista(&l, 34432, "José Elder", 60);
    insereLista(&l, 65443, "Lucas Elder", 26);
    insereLista(&l, 22113, "Masaji Ohya", 100);

    imprimeLista(&l);

    int num;
    printf("Digite o CPF do elemento a ser pesquisado:");
    scanf("%d", &num);

    pesquisaLista(&l, num); 
    
    removeElementoLista(&l, 19);
    imprimeLista(&l); 

    maximoElemento(&l);
    minimoElemento(&l);

    proximoElemento(&l, 12345); 
    anteriorElemento(&l, 54321);

    deletaLista(&l);

    return 0;
}//main