#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Você foi contratado para desenvolver um sistema multithread para simular operações de atualização de saldo em uma conta bancária 
compartilhada. Cada thread irá realizar uma operação específica, que consiste em calcular um novo saldo com base em um número 
identificador único fornecido a ela. Para garantir o funcionamento correto das operações e evitar condições de corrida, é necessário 
implementar o controle de concorrência.

Especificações do Sistema:
Saldo inicial: A conta bancária começa com um saldo de 1000.
Número de threads: O sistema deve criar 5 threads, cada uma responsável por calcular um novo saldo. O identificador de cada thread será 
um número de 1 a 5.

Cálculo do novo saldo:

Cada thread deve:
Ler o saldo atual.
Calcular o novo saldo. 
Imprimir o identificador da thread e o novo saldo calculado.

Retorno do resultado:
Cada thread deve retornar o novo saldo calculado ao término da sua execução usando pthread_exit. O resultado será capturado no programa principal.
Controle de Concorrência:
Como o saldo é compartilhado, utilize um mutex para proteger a leitura e escrita do saldo durante a operação de cálculo.

Saldo final:
O programa principal deve somar os saldos retornados por cada thread e exibir o saldo final.

Tarefas:
Complete a implementação da função AtualizaSaldo para realizar o cálculo descrito e proteger a atualização do saldo com um mutex.
No programa principal:
Crie e inicie as threads.
Aguarde o término de todas as threads e capture os valores retornados.
Some os saldos retornados por cada thread para calcular o saldo final.
Exiba o saldo final ao final da execução do programa.
Saída Esperada:
A saída esperada é:

Sou a Thread 1. Novo saldo: 1100
Sou a Thread 2. Novo saldo: 1200
Sou a Thread 3. Novo saldo: 1300
Sou a Thread 4. Novo saldo: 1400
Sou a Thread 5. Novo saldo: 1500
Saldo Final: 6500
*/

#define NUM_THREADS 5
#define saldo 1000

pthread_mutex_t m;

void *atualizaSaldo(void *n){
    int num = (intptr_t)n;
    int novoSaldo;

    pthread_mutex_lock(&m); // início da seção crítica
    novoSaldo = saldo + (num* 100);
    pthread_mutex_unlock(&m); // fim da seção crítica

    printf("Eu sou a thread %d. Novo saldo: %d\n", num, novoSaldo);

    int *saldoptr = malloc(sizeof(int));
    *saldoptr = novoSaldo;
    pthread_exit(saldoptr);     
}

int main(){
    pthread_t threads[NUM_THREADS];
    void *status;
    int resultado = 0;

    //inicia o mutex
    pthread_mutex_init(&m, NULL);

    for(int i=0; i<NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, atualizaSaldo, (void*)(intptr_t)(i+1));
        pthread_join(threads[i], &status);
        resultado += *((int *)status);
        free(status); 
    }

    printf("Saldo Final: %d\n", resultado);

    pthread_mutex_destroy(&m);
    return 0;
}