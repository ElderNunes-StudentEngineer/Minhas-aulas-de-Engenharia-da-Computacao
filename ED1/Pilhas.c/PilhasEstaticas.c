#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define N 10

typedef struct{
    int CPF;
    char nome[30];
    int idade;
    //outras infos
}OBJETOS;

typedef struct{
    int topo;
    OBJETOS elementos[N];
    int qtd_elementos;
}PILHA_ESTATICA;

void inicializaPilha(PILHA_ESTATICA* pilha){
    pilha->qtd_elementos = 0;
    pilha->topo = 0;
}//inicializaPilha

bool estaVazia(PILHA_ESTATICA* pilha){
    return pilha->qtd_elementos == 0;
}//estaVazia

bool estaCheia(PILHA_ESTATICA* pilha){
    return pilha->qtd_elementos == N;
}//estaCheia

int tamanhoPilha(PILHA_ESTATICA* pilha){
    return pilha->qtd_elementos;
}//tamanhoPilha

void inserirPilha(PILHA_ESTATICA *pilha, int cpf, char nome[], int idade){
    if(estaCheia(pilha) == true){
        printf("\n Pilha cheia -> insercao não concluída!\n");
    }//if
    
    pilha->elementos[pilha->topo].CPF = cpf;  
    pilha->elementos[pilha->topo].idade = idade;
    strcpy(pilha->elementos[pilha->topo].nome, nome);

    pilha->qtd_elementos++;
    pilha->topo++;
}//inserirPilha

OBJETOS topoPilha(PILHA_ESTATICA* pilha){
    if(estaVazia(pilha) == true){
        printf("\nPIlha Vazia não a topo!\n");
        return pilha->elementos[pilha->topo];
    }//if
    return pilha->elementos[pilha->topo-1];
}//topoPilha;    

void imprimeTopo(PILHA_ESTATICA* pilha){
    OBJETOS p = topoPilha(pilha);
    if(estaVazia(pilha) == true){
        printf("Não foin possível imprimir, pois a pilha esta vazia!\n");
    }    
    printf("\n============================================\n");
    printf("\nOBJETO TOPO CPF = %d | Nome = %s | Idade = %d\n", p.CPF, p.nome, p.idade);
    printf("\n============================================\n");
}//imprimeTopo

void desempilha(PILHA_ESTATICA* pilha){
    if(estaVazia(pilha) == true){
        printf("\n A pilha esta vazia, não tem como dempilhar!\n");
        return;
    }//if
    pilha->topo--;
    pilha->qtd_elementos--;

}//desempilha

int main(){

    PILHA_ESTATICA p;

    inicializaPilha(&p);

    inserirPilha(&p, 12345, "Elder Nunes", 18);
    inserirPilha(&p, 75465, "Felipe Campos", 43);
    inserirPilha(&p, 98999, "João Lucas", 76);
    inserirPilha(&p, 99999, "Sofia Lima", 23);
    imprimeTopo(&p);

    desempilha(&p);
    return 0;
}//main