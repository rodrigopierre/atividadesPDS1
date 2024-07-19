#include <stdio.h>

struct Iris {
    float comp_sepala;
    float larg_sepala;
    float comp_petala;
    float larg_petala;
    char tipo[50];
};

void Classificar(struct Iris desconhecida, struct Iris planta[], int n){
    float diferenca, menor_dif = 10;
    int index;
    for (int i = 0; i < n; i++){
        diferenca = 0;
        if (desconhecida.comp_sepala > planta[i].comp_sepala)
            diferenca += (desconhecida.comp_sepala - planta[i].comp_sepala);
            else 
            diferenca += (planta[i].comp_sepala - desconhecida.comp_sepala);

        if (desconhecida.larg_sepala > planta[i].larg_sepala)
            diferenca += (desconhecida.larg_sepala - planta[i].larg_sepala);
            else 
            diferenca += (planta[i].larg_sepala - desconhecida.larg_sepala);

        if (desconhecida.comp_petala > planta[i].comp_petala)
            diferenca += (desconhecida.comp_petala - planta[i].comp_petala);
            else 
            diferenca += (planta[i].comp_petala - desconhecida.comp_petala);

        if (desconhecida.larg_petala > planta[i].larg_petala)
            diferenca += (desconhecida.larg_petala - planta[i].larg_petala);
            else 
            diferenca += (planta[i].larg_petala - desconhecida.larg_petala);
    
        if (diferenca < menor_dif){
            menor_dif = diferenca;
            index = i;
        }
    }
    printf("%s", planta[index].tipo);
}

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    struct Iris planta[n];
    for (int i = 0; i < n; i++){
        scanf("%f %f %f %f %s", &planta[i].comp_sepala, &planta[i].larg_sepala, &planta[i].comp_petala, &planta[i].larg_petala, planta[i].tipo);
        getchar();
    }
    struct Iris desconhecida;
    scanf("%f %f %f %f", &desconhecida.comp_sepala, &desconhecida.larg_sepala, &desconhecida.comp_petala, &desconhecida.larg_petala);
    Classificar(desconhecida, planta, n);
    
}