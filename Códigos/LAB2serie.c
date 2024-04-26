#include <stdio.h> 
#include <stdlib.h>

// Série:
// Implemente um programa que imprima todos os termos da série dado n, e os termos x0 e x1. 
// Os outros termos da série serão:
// xn = 4xn-1 -2xn-2
// O primeiro valor é referente à variável n, ou seja, o valor de termos da série, seguida de (x0) e (x1). 
// O programa deve imprimir o valor de cada termo até o enésimo termo. 
// No exemplo abaixo, com o valor de n=4, x0=3 e x1=4, o programa deve imprimir o valor de x0, x1, x2, x3 e x4.

int main(){
    int n, x[100];
    printf("Digite três valores inteiros: \n");
    scanf("%d%d%d", &n, &x[0], &x[1]);
    system("clear");
    for (int i = 0; i <= n; i++){
        if(i>1){
            x[i] = (4 * x[i-1]) - (2 * x[i-2]);
        }
        printf("X%d: %d\n", i, x[i]);
    }
    return 0;
}