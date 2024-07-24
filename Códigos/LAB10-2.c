#include <stdio.h>
#include <string.h>

int main(){
    int linhas, colunas;
    scanf("%d\n%d", &linhas, &colunas);
    getchar();
    for (int i = 0; i < linhas; i++){
        char linha[100];
        fgets(linha, 100, stdin);
        printf("%s", linha);
    }
}
