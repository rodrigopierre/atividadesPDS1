#include <stdio.h>
#include <stdlib.h>

// A sequência de Fibonacci pode ser definida como:
// fib(0) = 0
// fib(1) = 1
// fib(n) = fib(n-1) + fib(n-2), para n>2
// Implemente um programa que calcule a série de Fibonacci para um determinado n
// fornecido pelo usuário. Você deve armazenar em um vetor cada elemento da série, de
// forma que a posição 0 armazene o termo 0, a posição 1 o termo 1, e assim por diante.
// Seu programa deve receber do usuário um número entre 0 e 800 e imprimir o termo
// correspondente ao número recebido. O usuário deve ser capaz de entrar com vários
// números interativamente em uma mesma execução. O programa termina quando o
// usuário entrar com um número negativo ou maior que 800.

int main(){
    int num, serie[801], i;
    for (i = 0; i <= 800; i++){
        if (i == 0 || i == 1)
            serie[i] = i;
        else if (i == 2)
            serie[i] = 1;
        else
            serie[i] = serie[i-1] + serie[i-2];
    }

    while (1){
        scanf("%d", &num);
        if (num > 800 || num < 0)
            break;
        else
            printf("%d\n", serie[num]);
    }
}
