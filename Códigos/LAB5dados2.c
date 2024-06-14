#include <stdio.h>
#include <string.h>


// Altere o programa anterior para considerar o endereço das pessoas, além do nome,
// idade e salario. O endereco deve ser composto por:
// ● rua (máximo 50 caracteres)
// ● numero (inteiro sem sinal)
// ● estado (máximo 50 caracteres)
// Assim, cada pessoa será descrita, no vetor de estruturas de tamanho máximo 5, em termos
// de:
// ● nome (máximo 50 caracteres)
// ● idade (inteiro sem sinal)
// ● salario (float)
// ● endereco (conforme detalhado acima)
// As operações básicas são:
// ● inserir: insere os dados de uma pessoa no vetor caso haja espaço. Assim, caso o
// vetor esteja completamente ocupado deve imprimir a string "Espaco insuficiente"
// ● mostrar: imprime os dados de uma pessoa caso a pessoa esteja no vetor, caso
// contrário imprime a string "Registro ausente"
// ● alterar: altera os campos do registro, caso o registro exista, caso contrário imprime a
// string "Registro ausente para alteracao"



struct reg {
    char name[50];
    unsigned int age;
    float wage;
    char street[50];
    unsigned int number;
    char state[50];
};

int main() {
    struct reg ppl[6];
    int i = 0;
    char search[50];
    char action[100];

    while (1) {
        fgets(action, 100, stdin);
        action[strcspn(action, "\n")] = '\0';

        if (!strcmp(action, "inserir")) {
            if (i < 5) {
                scanf("%s %u %f %s %u %s",ppl[i].name, &ppl[i].age, &ppl[i].wage, ppl[i].street, &ppl[i].number, ppl[i].state);
                printf("Registro %s %u %.2f %s %u %s inserido\n", ppl[i].name, ppl[i].age, ppl[i].wage, ppl[i].street, ppl[i].number, ppl[i].state);
                getchar();
                i++;
            } else {
                scanf("%s %u %f %s %u %s", ppl[6].name, &ppl[6].age, &ppl[6].wage, ppl[6].street, &ppl[6].number, ppl[6].state);
                puts("Espaco insuficiente");
                getchar();
            }
        } else if (strcmp(action, "mostrar") == 0) {
            fgets(search, 50, stdin);
            search[strcspn(search, "\n")] = '\0';
            int found = 0;
            for (int c = 0; c < i; c++) {
                if (!strcmp(search, ppl[c].name)) {
                    printf("Registro %s %u %.2f %s %u %s\n", ppl[c].name, ppl[c].age, ppl[c].wage, ppl[c].street, ppl[c].number, ppl[c].state);
                    found = 1;
                }
            }
            if (!found) {
                puts("Registro ausente");
            }
        } else if (!strcmp(action, "alterar")) {
            int found = 0;
            scanf("%s %u %f %s %u %s",ppl[5].name, &ppl[5].age, &ppl[5].wage, ppl[5].street, &ppl[5].number, ppl[5].state);
            for (int c = 0; c < 5; c++) {
                if (!strcmp(ppl[5].name, ppl[c].name)) {
                    ppl[c].age = ppl[5].age;
                    ppl[c].wage = ppl[5].wage;
                    strcpy(ppl[c].street, ppl[5].street);
                    ppl[c].number = ppl[5].number;
                    strcpy(ppl[c].state, ppl[5].state);
                    printf("Registro %s %u %.2f %s %u %s alterado\n", ppl[c].name, ppl[c].age, ppl[c].wage, ppl[c].street, ppl[c].number, ppl[c].state);
                    found = 1;
                    getchar();
                }
            }
            if (!found) {
                puts("Registro ausente para alteracao");
                getchar();
            }
        } else {
            break;
        }
    }

    return 0;
}