/*
* main.h
*
* Árvore Rubro-Negra para sistema de ranking e pontuação de pessoas.
*
* Autores:
*   Carlos Eduardo Assis
*   Elder Nunes
*   Enzo Livrari
*   Rafael Zaupa
* Data: 05/06
*/


#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum { RED, BLACK } Color;


typedef struct RBNode {
   int id;                // identificador único
   char nome[100];        // primeiro nome
   int pontuacao;         // pontos para ranking
   Color cor;             // RED ou BLACK
   struct RBNode *pai;    // nó pai
   struct RBNode *esq;    // filho esquerdo
   struct RBNode *dir;    // filho direito
} RBNode;


// nó folha único (sempre BLACK) e raiz da árvore
extern RBNode *folha;
extern RBNode *raiz;


// Inicializa 'folha' e define raiz = folha (árvore vazia)
void inicializar_arvore();


// Cria um nó novo (cor = RED) com id e nome, filhos apontam para folha
RBNode *criar_nodo(int id, const char *nome);


// Rotação simples à esquerda em torno de *px (ajusta ponteiros)
void rotacao_esquerda(RBNode **px);


// Rotação simples à direita em torno de *py (ajusta ponteiros)
void rotacao_direita(RBNode **py);


// Insere nó novo na árvore (id, nome, pontuação) e reequilibra
void rb_inserir(int id, const char *nome, int pontuacao_inicial);


// Corrige cores e faz rotações após inserir o nó z
void rb_inserir_correto(RBNode *z);


// Busca nó por id (retorna ponteiro ou folha se não existir)
RBNode *rb_buscar(RBNode *node, int id);


// Remove nó com id e, se necessário, chama correção de balanceamento
void rb_remover(int id);


// Reequilibra árvore após remoção (parte de remoção de cor preta)
void rb_remover_correto(RBNode *x);


// Atualiza pontuação de nó existente (retorna 0 = sucesso, -1 = não existe)
int atualizar_pontuacao(int id, int pontos);


// Retorna posição no ranking (1 = maior pontuação) ou -1 se não existir
int obter_ranking(int id);


// Imprime a árvore em-ordem por id (com nível de indentação)
void exibir_arvore(RBNode *node, int nivel);


// Imprime lista ordenada do maior para o menor por pontuação
void exibir_ranking();


// Libera todos os nós da subárvore a partir de node
void liberar_arvore(RBNode *node);


// Processa comandos no terminal: inserir, remover, buscar, atualizar, exibir, sair
void processar_comando();


#endif // MAIN_H



