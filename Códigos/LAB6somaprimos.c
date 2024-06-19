#include <stdio.h>
#include <string.h>

// Faça uma função para calcular a soma dos N primeiros números primos. O programa
// deverá ter as funções “Soma_Primos” e “Primo”, sendo que a primeira será responsável
// pela soma dos números que forem primos e a segunda será responsável por verificar se o
// número em questão é primo ou não. Implemente um programa que utilize a função pedida,
// lendo da entrada padrão uma série de números e imprimindo o resultado conforme função
// solicitada.


int detectorPrimos(int num) {
    int tem_divisor = 0;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

long int somaPrimos(int num) {
    int c = 0;
    int i = 2;
    long int soma = 0;
    while (c < num) {
        int ehprimo = detectorPrimos(i);
        if (ehprimo) {
            soma += i;
            c++;
        }
        i++;
    }
    return soma;
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
        long int soma = somaPrimos(num);
        printf("%li\n", soma);
    } while (strlen(linha) > 0);
    return 0;
}