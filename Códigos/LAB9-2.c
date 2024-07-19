#include <stdio.h>

void Imprimir_vetor(int vetor[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void Multiplica(int vetor[], int n, int multiplica){
    for (int i = 0; i < n; i++){
        printf("%d ", vetor[i]*multiplica);
    }
    printf("\n");
}

int main(){
    int n, multiplica;
    scanf("%d", &n);
    int vetor[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    scanf("%d", &multiplica);
    Imprimir_vetor(vetor, n);
    Multiplica(vetor, n, multiplica);
    Imprimir_vetor(vetor, n);

}