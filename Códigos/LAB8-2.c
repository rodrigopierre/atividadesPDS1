#include <stdio.h>


void primo(int m, int *p1, int *p2){
    int primo1, primo2, n1 = m, n2 = m;
    while (1){
        int ehprimo = 1;
        n1--;
        for(int i = 2; i < n1; i++){
            if (n1 % i == 0){
                ehprimo = 0;
            }
        }
        if (ehprimo){
            break;
        }
    }
    while (1){
        int ehprimo = 1;
        n2++;
        for(int i = 2; i < n2; i++){
            if (n2 % i == 0){
                ehprimo = 0;
            }
        }
        if (ehprimo){
            break;
        }
    }
    *p1 = n1;
    *p2 = n2;
}

int main(){
    int m, primo1, primo2, *p1, *p2;
    scanf("%d", &m);
    p1 = &primo1;
    p2 = &primo2;
    primo(m, p1, p2);
    printf("%d\n%d\n", primo1, primo2);
}