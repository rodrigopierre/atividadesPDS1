#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implemente um programa que calcula e apresenta em tela a soma duas matrizes de dimensão
// 5x5. Estas matrizes devem estar salvas em um único arquivo binário. Observe que o arquivo binário
// que contém as matrizes, também pode ser gerado pelo programa. No entanto, para fins de teste,
// o programa deve solicitar o nome do arquivo. 


int main() { 
    char nome_arquivo[20];
    char nome_arquivo2[20];
    int i = 0, j = 0;
    long int matriz1[5][5];
    long int matriz2[5][5];

    fgets(nome_arquivo, 20, stdin);
    for (int i = 0; i < (strlen(nome_arquivo) - 1); i++){
        nome_arquivo2[i] = nome_arquivo[i];
    }

    FILE *arquivo;
    arquivo = fopen(nome_arquivo2, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++){
            fscanf(arquivo, "%li", &matriz1[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++){
            fscanf(arquivo, "%li", &matriz2[i][j]);
        }
    }

     for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++){
            printf("%li ", matriz1[i][j]+matriz2[i][j]);
        }
        printf("\n");
    }
   
    return 0;
}