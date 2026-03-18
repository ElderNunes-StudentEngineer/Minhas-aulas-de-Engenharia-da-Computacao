#include<stdio.h>
#include<stdlib.h>

int fatorial(int n){
    int fat;
    if(n == 0){
        return 1;
    }else{
        fat = n * fatorial(n-1);
        return fat;
    }//else
}//fatorial

int main(){

    int n, resultado;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    fatorial(n);
    resultado = fatorial(n);
    printf("Resultado: %d\n", resultado);

    return 0;
}//main