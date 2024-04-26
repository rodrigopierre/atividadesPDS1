#include <stdio.h>
#include <stdlib.h>

// Soma:
// Faça um programa que pegue um número do teclado e calcule a soma de todos os números de 1 até ele (use laço for()). 
// Ex.: o usuário entra 7, o programa vai mostrar 28, pois 1+2+3+4+5+6+7=28.

int main(){
    int num, i, soma = 0;
    printf("Digite um número inteiro: \n");
    scanf("%d", &num);
    for (i = 1; i <= num; i++)
        soma += i;
    system("clear");
    printf("%d\n", soma);
}