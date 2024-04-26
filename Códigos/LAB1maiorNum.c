#include <stdio.h>

// Atividade: Maior
// Faça um programa que lê 3 valores inteiros e imprima o maior deles.

int main (){
    int num1, num2, num3;
    printf("Digite três valores inteiros: \n");
    scanf("%d%d%d", &num1, &num2, &num3);
    if (num2 > num1)
        num1 = num2;
    if (num3 > num1)
    num1 = num3;
    printf("O maior número inteiro digitado foi: %d\n", num1);
}