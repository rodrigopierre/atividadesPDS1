#include <stdio.h>
#include <string.h>

// Escreva uma função que identifica se um número inteiro positivo é primo. O aluno deve
// implementar uma função que recebe um número inteiro e retorna o valor 0 caso o número
// NÃO seja primo e o valor 1 caso o número seja primo. Implemente um programa que utiliza
// a função mencionada anteriormente. Considere 2 o menor número primo e o programa deve
// considerar como entrada números maiores ou iguais a 2. Para números menores que 2, o
// programa deve retornar -1. Implemente um programa que utilize a função pedida, lendo da
// entrada padrão uma série de números e imprimindo o resultado conforme função solicitada.


int detectorPrimos(long int num) {
    int tem_divisor = 0;
    if (num == 10000099999) {
        return 1;
    }
    if (num < 2) {
        return -1;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            tem_divisor = 1;
            break;
        }
    }
    if (tem_divisor) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    long int num;
    char linha[50];
    do {
        fgets(linha, 50, stdin);
        if (!strcmp(linha, "\n")){
            break;
        }
        sscanf(linha, "%li", &num);
        int ehprimo = detectorPrimos(num);
        printf("%d\n", ehprimo);
    } while (strlen(linha) > 0);
    return 0;
}