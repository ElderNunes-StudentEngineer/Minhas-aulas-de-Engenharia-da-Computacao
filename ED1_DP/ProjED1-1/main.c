/**
 * @file main.c
 * @brief Sistema de gerenciamento de filas para um consultório veterinário.
 * @details Este programa gerencia filas de pacientes em um consultório veterinário, permitindo adicionar pacientes com prioridade e exibir as filas.
 * @author Elder, Cadu, Rafael
 * @version 1.0
 * @note Este código é um exemplo de implementação de filas e pilhas em C.
 * 
 */
#include "Veterinaria.h"

#define ARQUIVO_NORMAL "fila_normal.dat"
#define ARQUIVO_PRIORITARIA "fila_prioritaria.dat"

int main() {
    FILAORD fila_prioritaria;
    FILA fila_normal;

    iniciaFilaOrd(&fila_prioritaria);
    iniciaFila(&fila_normal);

    if(!carregaFilaOrd(&fila_prioritaria, ARQUIVO_PRIORITARIA)) {
        printf("Erro ao carregar a fila prioritária do arquivo %s\n", ARQUIVO_PRIORITARIA);
    }

    if(!carregaFila(&fila_normal, ARQUIVO_NORMAL)) {
        printf("Erro ao carregar a fila normal do arquivo %s\n", ARQUIVO_NORMAL);
    }

    int opcao = 0;
    char NomePET[TAM_NOME];
    int Prioridade = 0;

    while (1) {
        printf("\n\n=== SISTEMA VETERINÁRIO ===\n");
        printf("1 - Adicionar novo paciente urgente\n");
        printf("2 - Adicionar novo paciente normal\n");
        printf("3 - Exibir filas\n");
        printf("4 - Pesquisar paciente\n");
        printf("5 - Salvar e Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        setbuf(stdin, NULL);

        switch (opcao) {
            case 1:
                printf("\nNome do PET: ");
                scanf("%24[^\n]", NomePET);
                setbuf(stdin, NULL);
                
                printf("Prioridade (1-5): ");
                scanf("%d", &Prioridade);
                setbuf(stdin, NULL);
                
                if (Prioridade < 1 || Prioridade > 5) {
                    printf("Prioridade inválida! Use 1-5.\n");
                    break;
                }
                
                inseriNovoPET(&fila_prioritaria, NomePET, Prioridade);
                printf("Pet %s adicionado à fila prioritária!\n", NomePET);
                break;
                
            case 2:
                printf("\nNome do PET: ");
                scanf("%24[^\n]", NomePET);
                setbuf(stdin, NULL);
                
                insereNaFila(&fila_normal, NomePET);
                printf("Pet %s adicionado à fila normal!\n", NomePET);
                break;
                
            case 3:
                printf("\n=== FILA PRIORITÁRIA ===\n");
                exibePrioridades(&fila_prioritaria);
                printf("\n=== FILA NORMAL ===\n");
                exibeFila(&fila_normal);
                break;
            case 4:
                printf("\nDigite o nome do PET a pesquisar: ");
                scanf("%24[^\n]", NomePET);
                setbuf(stdin, NULL);

                printf("\nPesquisando na Fila Normal...\n");
                pesquisarNaFila(&fila_normal, NomePET);
                printf("\nPesquisando na Fila Prioritária...\n");
                pesquisarNaFilaOrd(&fila_prioritaria, NomePET);
                printf("\nPesquisa concluída!\n");                    
                break;
            case 5:
                printf("\nSalvando dados...\n");
                
                if(salvaFilaOrd(&fila_prioritaria, ARQUIVO_PRIORITARIA)) {
                    printf("Dados salvos da Fila Prioritária realizado com sucesso!\n");
                } else {
                    printf("Erro ao salvar os dados da Fila Prioritária!\n");
                }

                if(salvaFila(&fila_normal, ARQUIVO_NORMAL)) {
                    printf("Dados salvos da Fila realizado com sucesso!\n");
                } else {
                    printf("Erro ao salvar os dados da Fila!\n");
                }

                liberaFilaOrd(&fila_prioritaria);
                liberaFila(&fila_normal);
                printf("Sistema encerrado. Até logo!\n");
                return 0;
                
            default:
                printf("Opção inválida!\n");
        }
    }
}