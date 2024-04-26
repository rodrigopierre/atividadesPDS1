#include <stdio.h>
#include <string.h>

// Atividade: Substituição
// Faça um programa que substitua a primeira ocorrência do caractere C1 na string S
// pelo caractere C2. A entrada consiste em uma string, o caractere C1 e o caractere C2, nessa ordem.
// Seu programa deve imprimir a string após a substituição.

int main() {
    char string[100], string_subst[100], caract1, caract2;
    int c = 0;
    fgets(string, 100, stdin);
    scanf("%c", &caract1);
    getchar();
    scanf("%c", &caract2);
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == caract1 && c == 0) {
            string_subst[i] = caract2;
            c++;
            continue;
        }
        string_subst[i] = string[i];
    }
    printf("%s", string_subst);
}
