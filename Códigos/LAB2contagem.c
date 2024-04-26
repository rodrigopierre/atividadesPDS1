#include <stdio.h>
#include <stdlib.h>

// Contagem:
// Faça um programa que mostre uma contagem na tela de 233 a 457, 
// só que contando de 3 em 3 quando estiver entre 300 e 400 e de 5 em 5 quando não estiver.

int main(){
    int num = 233;
    do {
        printf("%d\n", num);
        if (num > 300 && num < 400)
            num += 3;
        else
            num += 5;
    } while (num <= 457);
}