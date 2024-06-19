#include <stdio.h>
#include <string.h>

// Escreva uma função que recebe 3 parâmetros inteiros correspondendo aos valores de
// dia, mês e ano, respectivamente. A função deve retornar o número de dias já transcorridos
// em relação à data de 17/09/2020, incluindo o dia final no cálculo. Implemente um programa
// que utilize a função pedida, lendo da entrada padrão uma série de datas e imprimindo o
// número de dias conforme função solicitada.


int ehAnoBissexto(int ano) {
    if (ano % 400 == 0) {
        return 1;
    }
    if (ano % 100 == 0) {
        return 0;
    }
    if (ano % 4 == 0) {
        return 1;
    }
    return 0;
}

int diasMes(int ano, int mes) {
    int diasMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (mes == 2 && ehAnoBissexto(ano)) {
        return 29;
    }
    return diasMes[mes - 1];
}

int diasTotais(int dia, int mes, int ano) {
    int dias = 0;
    while (ano < 2020 || (ano == 2020 && mes < 9) || (ano == 2020 && mes == 9 && dia < 17)) {
        dias += 1;
        dia += 1;
        if (dia > diasMes(ano, mes)) {
            dia = 1;
            mes += 1;
        }
        if (mes > 12) {
            mes = 1;
            ano += 1;
        }
    }
    dias += 1;
    return dias;
}

int main() {
    int dia, mes, ano;
    char linha[50];
    do {
        fgets(linha, 50, stdin);
        if (!strcmp(linha, "\n")){
            break;
        }
        sscanf(linha, "%d %d %d", &dia, &mes, &ano);
        int dias = diasTotais(dia, mes, ano);
        printf("%d\n", dias);
    } while (strlen(linha) > 0);
    return 0;
}