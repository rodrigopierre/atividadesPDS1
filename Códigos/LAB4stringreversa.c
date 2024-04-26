#include <stdio.h>
#include <string.h>

// String Reversa:
// Faça um programa para imprimir uma string ao contrário. 
// A entrada será uma única string e seu programa deve imprimir ela invertida.

int main() {
    char string[100], string_reversa[100];
    int c = 0;
    fgets(string, 100, stdin);
    for (int i = strlen(string) - 1; i >= 0; i--) {
        string_reversa[c] = string[i];
        c++;
    }
    printf("%s", string_reversa);

}