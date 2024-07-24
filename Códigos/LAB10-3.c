#include <stdio.h>
#include <stdlib.h>

int SomaVetores(int *vet1, int *vet2, int n, int *c){
    for (int i = 0; i < n; i++){
        c[i] = vet1[i] + vet2[i];
    }
}

int main(){
    int n; 
    scanf("%d", &n);
    int *a, *b, *c;
    a = (int*) malloc(n*sizeof(int));
    b = (int*) malloc(n*sizeof(int));
    c = (int*) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }
    SomaVetores(a, b, n, c);
    for (int i = 0; i < n; i++){
        printf("%d\n", c[i]);
    }
    free(a);
    free(b);
    free(c);
}