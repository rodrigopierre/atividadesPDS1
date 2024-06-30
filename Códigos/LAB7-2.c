#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Implemente um programa que conta quantas vezes a letra 'a' aparece em um arquivo
// binário. O nome do arquivo deve ser solicitado pelo programa. 


int main() { 
    char nome_arquivo[20];
    char nome_arquivo2[20];
    char c;
    int contador = 0;

    fgets(nome_arquivo, 20, stdin);
    for (int i = 0; i < (strlen(nome_arquivo) - 1); i++){
        nome_arquivo2[i] = nome_arquivo[i];
    }

    printf("%s", nome_arquivo2);

    FILE *arquivo;
    arquivo = fopen(nome_arquivo2, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        system("pause");
        exit(1);
    }

    while ((c = fgetc(arquivo)) != EOF) {
        if (c == 'a') {
            contador++;
        }
    }

    fclose(arquivo);
    printf("%d\n", contador);
    
    
    return 0;
}