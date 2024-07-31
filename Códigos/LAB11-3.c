#include <stdio.h>
#include <string.h>

int main(){
    char palavra[100];
    char letra;
    int soma = 0;
    fgets(palavra, 100, stdin);
    scanf("%c", &letra);
    for (int i = 0; i < strlen(palavra); i++){
        if (palavra[i] == letra){
            soma += 1;
        }
    }
    printf("%d", soma);
}