#include <stdio.h>
#include <string.h>

// Crie uma função com a lógica acima e implemente um programa que utilize tal função,
// lendo da entrada padrão uma série de números e imprima os resultados conforme
// condições abaixo:
// ● 0, caso o ano NÃO seja bissexto
// ● 1, caso o ano seja bissexto


int detectorBissexto(int ano) {
    if (ano % 400 == 0) {
        return 1;
    }
    if (ano % 100 == 0) {
        return 0;
    }
    if (ano % 4 == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int num;
    char linha[50];
    do {
        fgets(linha, 50, stdin);
        if (!strcmp(linha, "\n")){
            break;
        }
        sscanf(linha, "%d", &num);
        int ehbissexto = detectorBissexto(num);
        printf("%d\n", ehbissexto);
    } while (strlen(linha) > 0);
    return 0;
}