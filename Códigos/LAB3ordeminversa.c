#include <stdio.h>
#include <stdlib.h>

// Ordem Inversa:
// Faça um programa para ler um vetor X de 10 elementos e gerar um outro vetor com
// esses 10 elementos em ordem inversa. Exemplo: Se X= {3, 5, 2, 8, 4}, deverá ser
// gerado um vetor Y= {4, 8, 2, 5, 3}. O valor de n é lido pelo teclado.
// Cada posição do vetor deve ser impressa em uma linha através do “\n”.

int main(){
    int serie[10], i;
    for (i = 0; i < 10; i++)
        scanf("%d", &serie[i]);
    system("clear");
    for (i = 9; i >= 0; i--)
        printf("%d\n", serie[i]);
}