#include <stdio.h>
#include <string.h>

// Concatenação de Strings:
// Faça um programa que, dadas duas strings S1 e S2, concatena as duas e imprime a
// nova string gerada. A entrada consiste de duas string, uma em cada linha, as quais
// corresponderão, respectivamente, a S1 e S2.

int main() {
    char string1[100], string2[100], string3[100];
    fgets(string1, 100, stdin);
    fgets(string2, 100, stdin);
    for (int i = 0; i < strlen(string1) - 1; i++){
        string3[i] = string1[i];
    }
    printf("%s%s", string3, string2);
}