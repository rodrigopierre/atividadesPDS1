#include <stdio.h>
#include <stdlib.h>

// Atividade: Celsius e Fahrenheit:
// Faça um programa que leia uma temperatura em graus Celsius e a converta para Fahrenheit. 
// Fórmula: F = (1.8 * C + 32).
// O programa deve imprimir o valor (​arredondando os valores) em Fahrenheit, assim como no exemplo abaixo. 
// OBS: utilize ​printf("%.0f ", valor); ​para arredondar.
// Entrada em Celsius	Saída em Fahrenheit
// 10	50
// 1	34

int main (){
    system("clear");
    float tempC, tempF;
    printf("Conversor de Graus Celsius para Fahrenheit: \n");
    printf("=============================================\n");
    printf("Digite a temperatura que você deseja converter: \n");
    scanf("%f", &tempC);
    tempF = (tempC * 1.8) + 32;
    system("clear");
    printf("A temperatura digitada em graus Fahrenheit é: %.0f\n", tempF);
}