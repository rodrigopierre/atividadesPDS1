#include <stdio.h>
#include <stdlib.h>

// Implemente um programa que conta quantas vezes a letra 'a' aparece em um arquivo texto. O
// nome do arquivo deve ser passado para o programa como PARÂMETRO de entrada.
// Ex.: ./contaLetras nomedoarquivo.txt 


int main(int argc, char *argv[]) { 
    char c;
    int contador = 0;
    FILE *arquivo;
    arquivo = fopen(argv[1], "r");
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