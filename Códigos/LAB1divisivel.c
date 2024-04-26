#include <stdio.h>

// Atividade: Divisível:
// Faça um programa que leia 3 valores inteiros x, y e z e testa se x é divisível por y e por
// z. Caso seja divisível, imprima: “O número é divisível”, caso contrário: “O número
// não é divisível”.
// Os valores devem ser lidos na seguinte ordem: x, y, z. Observe que a saída do
// programa deve estar no formato solicitado, com a primeira letra maiúscula e com
// acentuação gráfica.

int main (){
    int x, y, z;
    printf("Digite três números inteiros: \n");
    scanf("%d%d%d", &x, &y, &z);
    if (x % y == 0 && x % z == 0)
        printf("O número é divisível.\n");
    else
        printf("O número não é divisível. \n");
}