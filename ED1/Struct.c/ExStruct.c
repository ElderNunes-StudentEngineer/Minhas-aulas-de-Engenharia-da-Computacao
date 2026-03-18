#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int x, y, z;
}Pontos;

int digitaPontos(){
    int num = 0;
    printf("Digite a quantidade de pontos: ");
    scanf("%d", &num);
    return num;
}//digitaPontos

void preencherPontos(Pontos *p, int qtd){
    for(int i = 0; i<qtd; i++){
        p[i].x = i;
        p[i].y = i+1;
        p[i].z = i+2;

    }//for
}//preencherPontos

int main(){
    int qtdPontos = 0;
    Pontos *p = NULL;

    qtdPontos = digitaPontos();

    p = (Pontos*) malloc(qtdPontos * sizeof(Pontos));

    preencherPontos(p, qtdPontos);

    for(int i=0; i<qtdPontos; i++){
        printf("\n\tPonto: %d [Coordenadas: x = %d | y = %d | z = %d]", i+1, p[i].x, p[i].y, p[i].z);
    }//for


    free(p);
    return 0;
}//main