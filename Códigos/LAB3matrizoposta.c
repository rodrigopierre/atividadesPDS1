#include <stdio.h>

// Matriz Oposta:
// Chama-se matriz oposta de A a matriz –A cuja soma com A resulta na matriz nula.
// Faça um programa que receba como entrada os valores de uma matriz n x m e imprima a sua matriz oposta. 
// O formato de entrada é similar ao exercício anterior. 
// Obs: para a saída, deve-se imprimir os valores separadas por um espaço simples.

int main(){
    int i, j, c, cc;
    scanf("%d%d", &i, &j);
    int matriz[i][j];
    for (c = 0; c < i; c++){
        for (cc = 0; cc < j; cc++)
            scanf("%d", &matriz[c][cc]);
    }
    for (c = 0; c < i; c++){
        for (cc = 0; cc < j; cc++)
            printf("%d ", (-1 * matriz[c][cc]));
    }
}