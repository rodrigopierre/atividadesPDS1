#include <stdio.h>
#include <string.h>

// Atividade: Substring
// Faça um programa que verifica se uma string S2 é substring de uma string S1. Em caso positivo, 
// seu programa deve imprimir “É substring” e, em caso negativo, “Não é substring”. 
// Observe que a saída deve ser exatamente o que foi solicitado acima, 
// com a primeira letra maiúscula e acentuação gráfica.
// A entrada consiste de duas string, uma em cada linha, as quais corresponderão, respectivamente, a S1 e S2.

int main() {
    char string1[100], string2[100], string3[100];
    char* p;
    fgets(string1, 100, stdin);
    fgets(string2, 100, stdin);
    for (int i = strlen(string2) - 2; i >= 0; i--){
        string3[i] = string2[i];
    }
    p = strstr(string1, string3);
    if (p)
        printf("É substring");
    else
        printf("Não é substring");
}