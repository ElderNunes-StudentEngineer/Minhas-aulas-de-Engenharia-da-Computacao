#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct grafo{
    bool ehDigrafo;
    int numVertices;
    int **matrizAdj;
} GRAFO;

typedef struct elemPilha{
    int vertice;
    struct elePilha* prox;
}ELEM_PILHA;

typedef struct pilha{
    ELEM_PILHA* topo;
    int qtd_elementos;
}PILHA_DINAMICA;

void inicializaPilha(PILHA_DINAMICA* p){
    p->topo = NULL;
    p->qtd_elementos = 0;
}

void empilha(PILHA_DINAMICA* p, int vertice){
    ELEM_PILHA* novo = (ELEM_PILHA*) malloc(sizeof(ELEM_PILHA));
    novo->vertice = vertice;
    novo->prox = p->topo;
    p->topo = novo;
    p->qtd_elementos++;
}

void desempilha(PILHA_DINAMICA* p){
    ELEM_PILHA* aux = p->topo;
    int vertice = aux->vertice;
    p->topo = aux->prox;
    p->qtd_elementos--;
    free(aux);
    return vertice;
}

void DFS(GRAFO* g, int vIni){
    int *visitado = (int*) malloc(sizeof(int)*g->numVertices);
    int cont = 0;
    PILHA_DINAMICA pilha;
    bool retira = true;

    for(int i=0; i<g->numVertices; i++){
        visitado[i] = 0;
    }
    inicializaPilha(&pilha);

    visitado[vIni] = ++cont;
    empilha(&pilha, vIni);
    while(pilha.topo != NULL){
        retira = true;
        int i = pilha.topo->vertice;
        for(int j=0; j<g->numVertices; j++){
            if(g->matrizAdj[i][j] > 0 && visitado[j] == 0){
                visitado[j] = ++cont;
                empilha(&pilha, i);
                retira = false;
                break;
            }
        }
        if(retira == true){
            --cont;
            desempilha(&pilha);
        }
    }

    free(visitado);
}

void inicializaGrafo(GRAFO *g, int numV, bool digrafo){
    g->ehDigrafo = digrafo;
    g->numVertices = numV;

    g->matrizAdj = (int**) malloc(sizeof(int*) * numV);
    for(int i=0; i<numV; i++){
        g->matrizAdj[i] = (int*) malloc(sizeof(int) * numV);
        for(int j=0; j<numV; j++){
            g->matrizAdj[i][j]=0;
        }
    }
}

void destroiGrafo(GRAFO *g){
    for(int i=0; i<g->numVertices; i++){
        free(g->matrizAdj[i]);
    }
    free(g->matrizAdj);
}

void incluiAresta(GRAFO *g, int origem, int destino){
    g->matrizAdj[origem][destino]=1;
    g->ehDigrafo==0 ? g->matrizAdj[destino][origem]=1 : false;
}

int main(void){
    GRAFO g;

    inicializaGrafo(&g, 5, 0); 
    //------- Montando o grafo-----
    incluiAresta(&g, 0, 1);
    incluiAresta(&g, 1, 2);
    incluiAresta(&g, 0, 2);
    incluiAresta(&g, 0, 3);
    incluiAresta(&g, 0, 4);
    incluiAresta(&g, 2, 3);
    incluiAresta(&g, 3, 4);
    //----------------------------
    destroiGrafo(&g);
    return EXIT_SUCCESS;
}