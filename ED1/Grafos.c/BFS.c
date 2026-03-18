
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//----------------Grafos----------------------
typedef struct grafo{
    bool ehDigrafo;
    int numVertices;
    int **matrizAdj;
} GRAFO;

//-----------------Fila-----------------------

typedef struct elemfila{
    int vertice;
    struct elemfila *prox;
}ELEM_FILA;

typedef struct fila{
    ELEM_FILA* inicio;
    ELEM_FILA* fim;
    int qtdElem;
}FILA_DINAMICA;

//--------------------------------------------

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

void imprimeMatriz(GRAFO* g){
    printf("\n-----------Matriz Adjacência-----------------------\n");
    for(int i=0; i<g->numVertices; i++){
        for(int j=0; j<g->numVertices; j++){
            printf("\t%d", g->matrizAdj[i][j]);
        }
        printf("\n");
    }
    printf("\n---------------------------------------------------\n");
}

void inicializaFila(FILA_DINAMICA* fila){
    fila->fim = fila->inicio = NULL;
    fila->qtdElem = 0;
}

void insereElemFila(FILA_DINAMICA* fila, int vertice){
    ELEM_FILA *novo = (ELEM_FILA*) malloc(sizeof(ELEM_FILA));
    if(novo == NULL){
        printf("Erro ao alocar memória!\n");
        return;
    }

    novo->vertice = vertice;
    novo->prox = NULL;
    fila->qtdElem++;

    if(fila->inicio == NULL){
        fila->fim = fila->inicio = novo;
    }else{
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

int retiraElemFila(FILA_DINAMICA* fila){
    ELEM_FILA* aux = fila->inicio;
    int info = aux->vertice;
    fila->qtdElem--;
    fila->inicio = aux->prox;
    free(aux);
    return info;
}
                                                                                                                                                                     
void BFS(GRAFO* g, int vInicio){
    int *visitado;
    FILA_DINAMICA fila;
    int ordemVisita = 1;
    bool incrementa = false;
    visitado = (int*) malloc(sizeof(int)*g->numVertices);
    for(int i=0; i<g->numVertices; i++){
        visitado[i] = 0;
    }
    inicializaFila(&fila);
    visitado[vInicio] = ordemVisita++;
    insereElemFila(&fila, vInicio);

    while(fila.inicio != NULL){
        int aux = retiraElemFila(&fila);
        incrementa = false;
        for(int j=0; j<g->numVertices; j++){
            if(g->matrizAdj[aux][j] > 0 && visitado[j] == 0){
                visitado[j] = ordemVisita;
                insereElemFila(&fila, j);
                incrementa = true;
            }
        }
        if(incrementa == true) ordemVisita++;
        if(fila.inicio == NULL){
            for(int i=0; i<g->numVertices; i++){
                if(visitado[i] == 0){
                    visitado[i] = ordemVisita++;
                    insereElemFila(&fila, i);
                    break;
                }
            }
        }
    }

    printf("\n-----------------------IMPRIMINDO A ORDEM DE VISITA----------------------------\n");
    for(int i=0; i<g->numVertices; i++){
        printf("\t[%d->%d]", i, visitado[i]);
    }
    printf("\n-------------------------------------------------------------------------------\n");
    free(visitado);
}

int main(void){
    GRAFO g;

    inicializaGrafo(&g, 5, 1); 
    //------- Montando o grafo-----
    incluiAresta(&g, 0, 1);
    incluiAresta(&g, 1, 3);
    incluiAresta(&g, 1, 2);
    incluiAresta(&g, 2, 4);
    incluiAresta(&g, 3, 0);
    incluiAresta(&g, 3, 4);
    incluiAresta(&g, 4, 1);
    //----------------------------

    imprimeMatriz(&g);

    BFS(&g, 0); //busca em largura

    destroiGrafo(&g);
    return EXIT_SUCCESS;
}

