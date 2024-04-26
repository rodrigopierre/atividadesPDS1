#include <stdio.h>

// Maior da Matriz:
// Faça um programa que encontre o maior elemento de uma matriz. Inicialmente é
// fornecido o número de linhas e colunas da matriz. Em seguida, os valores de cada
// posição da matriz são informados em uma linha separada por espaços simples.

int main(){
    int i, j, c, cc, maior = 0;
    scanf("%d%d", &i, &j);
    int matriz[i][j];
    for (c = 0; c < i; c++){
        for (cc = 0; cc < j; cc++){
            scanf("%d", &matriz[c][cc]);
            if (matriz[c][cc] >= maior)
                maior = matriz[c][cc];
        }
    }
    printf("%d\n", maior);
}