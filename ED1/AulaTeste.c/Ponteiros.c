#include<stdio.h>
#include<stdlib.h>

void colocaEndereco(int* num, int** endNum){
    (*endNum) = num;
}//colocaEndereco

int main(){

    int num = 10;
    int *endNum = NULL;

    colocaEndereco(&num, &endNum);

    printf("Endereço de endNum: %d | Endereço: %p == %p\n", *endNum, endNum, &num);


    return 0;
}