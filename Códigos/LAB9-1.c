#include <stdio.h>

enum Mes {JAN, FEV, MAR, ABR, MAI, JUN, AGO, SET, OUT, NOV, DEZ};

struct Data {
    int dia;
    enum Mes mes;
    int ano;
};

struct Evento {
    char nome[100];
    char local[100];
    struct Data data;
};

void Cadastrar_eventos(struct Evento evento[], int n){
    for (int i = 0; i < n; i++){
        scanf("%s %s %d %d %d", evento[i].nome, evento[i].local, &evento[i].data.dia, &evento[i].data.mes, &evento[i].data.ano);
    }
}

void Imprimir_evento(struct Evento evento[], struct Data data_busca, int n){
    int encontrou = 0;
    for (int i = 0; i < n; i++){
        if(data_busca.dia == evento[i].data.dia){
            if(data_busca.mes == evento[i].data.mes){
                if(data_busca.ano == evento[i].data.ano){
                    printf("%s %s\n", evento[i].nome, evento[i].local);
                    encontrou = 1;
                }
            }
        }
    }
    if (encontrou == 0){
        printf("Nenhum evento encontrado!");
    }
}

int main(){
    int n;
    scanf("%d", &n);
    struct Evento agenda[n];
    Cadastrar_eventos(agenda, n);
    struct Data data_busca;
    printf("Nenhum evento encontrado!");
    do {
        data_busca.ano = 0;
        scanf("%d %d %d", &data_busca.dia, &data_busca.mes, &data_busca.ano);
        if (data_busca.ano == 0){
            break;
        }
        Imprimir_evento(agenda, data_busca, n);
    } while (1);
}