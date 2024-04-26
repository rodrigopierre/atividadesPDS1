#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// PI:
// Aproxime o valor de Pi empregando a série infinita de Gregory-Leibniz:
// Pi = 4 - 4/3 + 4/5 - 4/7 + ...
// Executando a série acima, a sua função deve retornar o número de iterações necessárias para encontrar um valor 
// próximo ao valor de M_PI (uma constante com o valor de PI da biblioteca math.h) com uma diferença máxima de X, 
// que é fornecida como entrada. No exemplo abaixo: foi necessário calcular 100001 termos da série para obter um 
// valor próximo ao valor de PI (M_PI) com uma diferença de 0.000010. Use o tipo double para acumular a soma acima.

int main(){
    double x, dif, dif2, pia, soma = 0;
    int c;
    printf("Digite a diferença máxima desejada: \n");
    scanf("%lf", &x);
    for (c = 0; c <= 100000; c++){
        if (c % 2 == 0) 
            soma = soma + 1.0/(2*c + 1);
        else 
            soma = soma - 1.0/(2*c + 1);
        pia = soma * 4;
        dif = pia - M_PI;
        dif2 = M_PI - pia;
        if (dif <= x && dif >= 0)
            break;
        if (dif2 <= x && dif2 >= 0)
            break;
    }
    system("clear");
    printf("%d\n", c+1);
    return 0;
}
