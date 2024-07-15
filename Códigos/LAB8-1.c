#include <stdio.h>


void media(double vet[], int n, int *i){
    double soma = 0, media;
    for (int c = 0; c < n; c++){
        soma += vet[c];
    }
    media = soma / n;
    int index;
    double menor_dif = 1000000;
    for (int c = 0; c < n; c++){
        if (vet[c] >= media){
            if ((vet[c] - media) < menor_dif){
                menor_dif = vet[c] - media;
                index = c;
            }
        } else {
            if ((media - vet[c]) < menor_dif){
                menor_dif = media - vet[c];
                index = c;
            }
        }
        
    }
    *i = index;
}

int main(){
    int v, index;
    int* i;
    scanf("%d", &v);
    double vet[v];

    for (int c = 0; c < v; c++){
        scanf("%lf", &vet[c]);
    }
    i = &index;
    media(vet, v, i);
    printf("%d\n", index);
}