#include <stdio.h>

int fibonacci(int n){
    int valor;
    if (n == 1 || n == 2){
        return 1;
    }
    valor = fibonacci(n-1) + fibonacci(n-2);
    return valor;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", fibonacci(n));
}