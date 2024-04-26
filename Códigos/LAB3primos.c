#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Números Primos:
// Faça um programa para imprimir todos os números primos num intervalo entre A e B, 
// sendo A e B números inteiros positivos e menores que 10000. 
// A e B devem ser fornecidos pelo usuário do seu programa.
// A entrada consiste em dois números inteiros que representam o intervalo A e B.

int main(){
    int inicio, fim, ehprimo, c, i;
    printf("Digite dois números inteiros: \n");
    scanf("%d%d", &inicio, &fim);
    system("clear");
    for (c = inicio; c <= fim; c++){
        ehprimo = 1;
        if (c == 0 || c == 1)
            continue;
        for (i = 2; i < c; i++){
            if ((c % i) == 0){
                ehprimo = 0;
                break;
            }
        }
        if (ehprimo == 1)
            printf("%d\n", c);
    }
}