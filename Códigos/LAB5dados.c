#include <stdio.h>
#include <string.h>


// Crie um programa para processar os dados de pessoas. Os dados das pessoas devem
// ser armazenados em um vetor de estruturas de tamanho máximo 4. Para cada pessoa,
// armazene:
// ● nome (máximo 50 caracteres)
// ● idade (inteiro sem sinal)
// ● salario (float)
// As operações básicas são:
// ● inserir: insere os dados de uma pessoa no vetor caso haja espaço. Assim, caso o
// vetor esteja completamente ocupado deve imprimir a string "Espaco insuficiente"
// ● mostrar: imprime os dados de uma pessoa caso a pessoa esteja no vetor, caso
// contrário imprime a string "Registro ausente"




struct reg {
    char name[50];
    unsigned int age;
    float wage;
};

int main() {
    struct reg ppl[4];
    int i = 0;
    char search[50];
    char action[100];

    while (1) {
        fgets(action, 100, stdin);
        action[strcspn(action, "\n")] = '\0';

        if (strcmp(action, "inserir") == 0) {
            if (i == 4) {
                scanf("%s %u %f",ppl[i].name, &ppl[i].age, &ppl[i].wage);
            getchar();
                puts("Espaco insuficiente");
            } else {
                scanf("%s %u %f",ppl[i].name, &ppl[i].age, &ppl[i].wage);
                printf("Registro %s %u %.2f inserido\n", ppl[i].name, ppl[i].age, ppl[i].wage);
                getchar();
                i++;
            }
        } else if (strcmp(action, "mostrar") == 0) {
            fgets(search, 50, stdin);
            search[strcspn(search, "\n")] = '\0';
            int found = 0;
            for (int c = 0; c < i; c++) {
                if (strcmp(search, ppl[c].name) == 0) {
                    printf("Registro %s %u %.2f\n", ppl[c].name, ppl[c].age, ppl[c].wage);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                puts("Registro ausente");
            }
        } else {
            break;
        }
    }

    return 0;
}