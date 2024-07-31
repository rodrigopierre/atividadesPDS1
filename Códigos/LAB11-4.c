#include <stdio.h>
#include <string.h>

int main(){
    char palavra[100];
    char palavra2[100];
    char letra;
    int soma = 0;
    fgets(palavra, 100, stdin);
    scanf("%c", &letra);
    int c = 0;
    for (int i = 0; i < strlen(palavra); i++){
        if (palavra[i] != letra){
            palavra2[c] = palavra[i];
            c++;
        }
    }
    printf("%s", palavra2);
}