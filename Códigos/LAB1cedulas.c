#include <stdio.h>
#include <stdlib.h>

// Atividade: Número Minimo de Notas:
// Considerando a existência de notas (cédulas) nos valores R$ 100, R$ 50, R$ 20, R$
// 10, R$ 5, R$ 2 e R$ 1, escreva um programa que capture um valor inteiro em reais
// (R$) e determine o menor número de notas para se obter o montante fornecido. O
// programa deve exibir o número de notas para cada um dos valores de nota existentes.
// Dado o valor inteiro de entrada, deve se imprimir cada cédula seguida de “:” e a
// quantidade de notas necessárias.

int main (){
    int valor, not100, not50, not20, not10, not5, not2, not1;
    not100 = not50 = not20 = not10 = not5 = not2 = not1 = 0;
    system("clear");
    printf("======================= Contador de Cédulas =========================\n");
    printf("Digite o valor inteiro a ser calculado o menor número de cédulas necessárias: \n");
    scanf("%d", &valor);
    while (valor >= 100){
        not100++;
        valor -= 100;
    }
    while (valor >= 50){
        not50++;
        valor -= 50;
    }
    while (valor >= 20){
        not20++;
        valor -= 20;
    }
    while (valor >= 10){
        not10++;
        valor -= 10;
    }
    while (valor >= 5){
        not5++;
        valor -= 5;
    }
    while (valor >= 2){
        not2++;
        valor -= 2;
    }
    if (valor == 1){
        not1++;
        valor--;
    }
    system("clear");
    printf("As cédulas necessárias são: \n");
    printf("100: %d\n50: %d\n20: %d\n10: %d\n5: %d\n2: %d\n1: %d\n", not100, not50, not20, not10, not5, not2, not1);

}