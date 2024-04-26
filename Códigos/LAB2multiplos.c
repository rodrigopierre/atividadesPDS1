#include <stdio.h>
#include <stdlib.h>

// Múltiplos:
// Faça um programa que compute quantos são os múltiplos de 2, de 3 e de 5 entre 1 e X ; 
// compute também quantos são os números múltiplos de 2, 3 e 5 ao mesmo tempo.

int main(){
    int x, mult2, mult3, mult5, todos, cont = 1;
    mult2 = todos = mult3 = mult5 = 0;
    printf("Digite um número inteiro: \n");
    scanf("%d", &x);
    while (cont <= x){
        if ((cont % 2) == 0)
            mult2 ++;
        if ((cont % 3) == 0)
            mult3 ++;    
        if ((cont % 5) == 0)
            mult5 ++;
        if (((cont % 5) == 0) && ((cont % 3) == 0) && ((cont % 2) == 0))
            todos ++;
        cont++;
    }
    printf("Múltiplos de 2: %d\n", mult2);
    printf("Múltiplos de 3: %d\n", mult3);
    printf("Múltiplos de 5: %d\n", mult5);
    printf("Múltiplos de todos: %d\n", todos);
}