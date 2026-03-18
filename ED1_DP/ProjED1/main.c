#include "Veterinaria.h"

int main() {
    FILAORD fila_prioritaria;
    FILA fila_normal;
    
    iniciaFilaOrd(&fila_prioritaria);
    iniciaFila(&fila_normal);

    int opcao = 0;
    char NomePET[TAM_NOME];
    int Prioridade = 0;

    while (1) {
        printf("\n\n=== SISTEMA VETERINÁRIO ===\n");
        printf("1 - Adicionar novo paciente urgente\n");
        printf("2 - Adicionar novo paciente normal\n");
        printf("3 - Exibir fila prioritária\n");
        printf("4 - Exibir fila normal\n");
        printf("5 - Sair\n");
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
                exibePrioridades(&fila_prioritaria);
                break;
                
            case 4:
                exibeFila(&fila_normal);
                break;
                
            case 5:
                printf("Encerrando sistema...\n");
                liberaFilaOrd(&fila_prioritaria);
                liberaFila(&fila_normal);
                return 0;
                
            default:
                printf("Opção inválida!\n");
        }
    }
}