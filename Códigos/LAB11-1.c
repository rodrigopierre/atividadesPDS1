#include <stdio.h>

int somaVetor(int vet[], int n){
    int soma;
    if (n == 0){
        return 0;
    }
    soma = vet[n-1] + somaVetor(vet, n-1);
    return soma;
}

int main() {
    int n, soma;
    scanf("%d", &n);
    int vet[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }
    soma = somaVetor(vet, n);
    printf("%d", soma);
}