#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void menu(){                                        //funcao que imprime o menu
    printf("1 - Informacoes do Professor\n");
    printf("2 - Informacoes do Aluno\n");
    printf("3 - Inserir Aluno\n");
    printf("4 - Lancar Notas\n");
    printf("5 - Informacoes da Turma\n");
    printf("6 - Situacao dos Alunos\n");
    printf("7 - Exportar Dados\n");
}

struct Professor {                           // estrutura base para armazenar os dados do professor
    char nome[100];
    int registro;
    int numturmas;
    char turma1nome[100];
    char turma1codigo[10];
    char turma2nome[100];
    char turma2codigo[10];
};

struct aluno {                                 // estrutura para armazenar os dados de cada aluno
    char nome[100];
    int registro;
    int prova1, prova2, prova3, notafinal;
    char conceito;
    char situacao[20];
};

struct Turma {                                 // estrutura usada para cada uma das 2 turmas
    int numalunos;
    struct aluno aluno[6];
};
                                             // funcao 1: imprime as informações do professor
void Informacoes_professor(struct Professor prof, struct Turma turma1, struct Turma turma2){
    printf("Professor %sRegistro numero %d\n", prof.nome, prof.registro);
    printf("Turma 1: %s - %s, %d alunos\n", prof.turma1codigo, prof.turma1nome, turma1.numalunos);
    if (prof.numturmas == 2) 
        printf("Turma 2: %s - %s, %d alunos\n", prof.turma2codigo, prof.turma2nome, turma2.numalunos);
}

void Informacoes_aluno(struct Professor prof, struct Turma turma1, struct Turma turma2){
    int matricula_aluno;
    char codigo[10];
    scanf("%d", &matricula_aluno);           // funcao 2: imprime as informações de um aluno específico
    getchar();
    fgets(codigo, 10, stdin);
    codigo[strlen(codigo)-1] = '\0';
    if (!strcmp(codigo, prof.turma1codigo)) {
        for (int i = 0; i < turma1.numalunos; i++) {
            if (matricula_aluno == turma1.aluno[i].registro) {
                printf("Aluno: %sMatricula: %d\n", turma1.aluno[i].nome, turma1.aluno[i].registro);
                printf("Prova 1: %d / Prova 2: %d / Prova 3: %d\nNota Final: %d - Conceito %c\n", turma1.aluno[i].prova1, turma1.aluno[i].prova2, turma1.aluno[i].prova3, turma1.aluno[i].notafinal, turma1.aluno[i].conceito);
                break;
        }   }
    } else {
        for (int i = 0; i < turma2.numalunos; i++) {
            if (matricula_aluno == turma2.aluno[i].registro) {
                printf("Aluno: %sMatricula: %d\n", turma2.aluno[i].nome, turma2.aluno[i].registro);
                printf("Prova 1: %d / Prova 2: %d / Prova 3: %d\nNota Final: %d - Conceito %c\n", turma2.aluno[i].prova1, turma2.aluno[i].prova2, turma2.aluno[i].prova3, turma2.aluno[i].notafinal, turma2.aluno[i].conceito);
                break;
}   }   }   }

void Inserir_aluno(struct Professor *prof, struct Turma *turma1, struct Turma *turma2){
    char nome_aluno[100], codigo_turma2[10];
    int matricula_aluno;                            // funcao 3: recebe as informações de um novo aluno
    fgets(nome_aluno, 100, stdin);                  // e armazena esses dados nas devidas estruturas
    scanf("%d", &matricula_aluno);
    getchar();
    fgets(codigo_turma2, 10, stdin);
    codigo_turma2[strlen(codigo_turma2)-1] = '\0';
    if (!strcmp(codigo_turma2, prof->turma1codigo)) {
        strcpy(turma1->aluno[turma1->numalunos].nome, nome_aluno);
        turma1->aluno[turma1->numalunos].registro = matricula_aluno;
        turma1->numalunos++;
    } else {
        strcpy(turma2->aluno[turma2->numalunos].nome, nome_aluno);
        turma2->aluno[turma2->numalunos].registro = matricula_aluno;
        turma2->numalunos++;
}   }

void Lancar_notas(struct Professor *prof, struct Turma *turma1, struct Turma *turma2){
    int matricula_aluno, p1, p2, p3, media, soma = 0;
    char codigo[10];
    scanf("%d", &matricula_aluno);                  // funcao 4: recebe as notas de um aluno específico e
    fgets(codigo, 10, stdin);                       // armazena esses dados na estrutura daquele aluno
    fgets(codigo, 10, stdin);
    codigo[strlen(codigo)-1] = '\0';
    scanf("%d %d %d", &p1, &p2, &p3);
    getchar();
    if (!strcmp(codigo, prof->turma1codigo)) {
        for (int i = 0; i < turma1->numalunos; i++) {
            if (matricula_aluno == turma1->aluno[i].registro) {
                turma1->aluno[i].prova1 = p1;
                turma1->aluno[i].prova2 = p2;
                turma1->aluno[i].prova3 = p3;
                soma = p1 + p2 + p3;
                media = soma / 3;
                turma1->aluno[i].notafinal = media;
                if (media < 40) {
                    turma1->aluno[i].conceito = 'F';
                    strcpy(turma1->aluno[i].situacao, "Reprovado");
                } else if (media <= 59) {
                    turma1->aluno[i].conceito = 'E';
                    strcpy(turma1->aluno[i].situacao, "Exame Especial");
                } else if (media <= 69) {
                    turma1->aluno[i].conceito = 'D';
                    strcpy(turma1->aluno[i].situacao, "Aprovado");
                } else if (media <= 79) {
                    turma1->aluno[i].conceito = 'C';
                    strcpy(turma1->aluno[i].situacao, "Aprovado");
                } else if (media <= 89) {
                    turma1->aluno[i].conceito = 'B';
                    strcpy(turma1->aluno[i].situacao, "Aprovado");
                } else if (media <= 100) {
                    turma1->aluno[i].conceito = 'A';
                    strcpy(turma1->aluno[i].situacao, "Aprovado");
                }
                break;
        }   }
    } else {
        for (int i = 0; i < turma2->numalunos; i++) {
            if (matricula_aluno == turma2->aluno[i].registro) {
                turma2->aluno[i].prova1 = p1;
                turma2->aluno[i].prova2 = p2;
                turma2->aluno[i].prova3 = p3;
                soma = p1 + p2 + p3;
                media = soma / 3;
                turma2->aluno[i].notafinal = media;
                if (media < 40) {
                    turma2->aluno[i].conceito = 'F';
                    strcpy(turma2->aluno[i].situacao, "Reprovado");
                } else if (media <= 59) {
                    turma2->aluno[i].conceito = 'E';
                    strcpy(turma2->aluno[i].situacao, "Exame Especial");
                } else if (media <= 69) {
                    turma2->aluno[i].conceito = 'D';
                    strcpy(turma2->aluno[i].situacao, "Aprovado");
                } else if (media <= 79) {
                    turma2->aluno[i].conceito = 'C';
                    strcpy(turma2->aluno[i].situacao, "Aprovado");
                } else if (media <= 89) {
                    turma2->aluno[i].conceito = 'B';
                    strcpy(turma2->aluno[i].situacao, "Aprovado");
                } else if (media <= 100) {
                    turma2->aluno[i].conceito = 'A';
                    strcpy(turma2->aluno[i].situacao, "Aprovado");
                }
                break;
}   }   }   }                               // funcao 5: imprime as informações de todos os alunos de alguma turma

void Informacoes_turma(struct Professor prof, struct Turma turma1, struct Turma turma2){
    char codigo_turma[10];
    fgets(codigo_turma, 10, stdin);
    codigo_turma[strlen(codigo_turma)-1] = '\0';
    if (!strcmp(codigo_turma, prof.turma1codigo)) {
        printf("Informacoes da turma %s - %s:\n", prof.turma1codigo, prof.turma1nome);
        printf("%d alunos\n", turma1.numalunos);
        for (int i = 0; i < turma1.numalunos; i++) {
            printf("Aluno: %s", turma1.aluno[i].nome);
            printf("Matricula: %d\n", turma1.aluno[i].registro);
        }
    } else {
        printf("Informacoes da turma %s - %s:\n", prof.turma2codigo, prof.turma2nome);
        printf("%d alunos\n", turma2.numalunos);
        for (int i = 0; i < turma2.numalunos; i++) {
            printf("Aluno: %s", turma2.aluno[i].nome);
            printf("Matricula: %d\n", turma2.aluno[i].registro);
}   }   }
                                           // funcao 6: imprime as notas e situações de todos os alunos de alguma turma
void Situacao_alunos(struct Professor prof, struct Turma turma1, struct Turma turma2){
    char codigo_turma[10];
    fgets(codigo_turma, 10, stdin);
    codigo_turma[strlen(codigo_turma)-1] = '\0';
    if (!strcmp(codigo_turma, prof.turma1codigo)) {
        printf("Situacao na Turma %s - %s\n", prof.turma1codigo, prof.turma1nome);
        for (int i = 0; i < turma1.numalunos; i++) {
            printf("Aluno: %s", turma1.aluno[i].nome);
            printf("Matricula: %d\n", turma1.aluno[i].registro);
            printf("Nota Final: %d - Conceito %c\n", turma1.aluno[i].notafinal, turma1.aluno[i].conceito);
            printf("Situacao: %s\n", turma1.aluno[i].situacao);
        }
    } else {
        printf("Situacao na Turma %s - %s\n", prof.turma2codigo, prof.turma2nome);
        for (int i = 0; i < turma2.numalunos; i++) {
            printf("Aluno: %s", turma2.aluno[i].nome);
            printf("Matricula: %d\n", turma2.aluno[i].registro);
            printf("Nota Final: %d - Conceito %c\n", turma2.aluno[i].notafinal, turma2.aluno[i].conceito);
            printf("Situacao: %s\n", turma2.aluno[i].situacao);
}   }   }

void Exportar_dados(char **argv, struct Professor prof, struct Turma turma1, struct Turma turma2){
    FILE *f2 = fopen(argv[2], "w");
    if (!f2) {                                       // funcao 7: Imprime os dados organizados em um arquivo externo
        fprintf(stderr, "Erro ao abrir o arquivo");
        return 1;
    }
    prof.nome[strlen(prof.nome)-1] = '\0';
    fprintf(f2, "DADOS EXPORTADOS\n");
    fprintf(f2, "\nProfessor %s - Registro %d\n", prof.nome, prof.registro);
    fprintf(f2, "\nTurma %s - %s\n", prof.turma1codigo, prof.turma1nome);
    for (int i = 0; i < turma1.numalunos; i++){
        fprintf(f2, "Aluno: %s", turma1.aluno[i].nome);
        fprintf(f2, "Matricula: %d\n", turma1.aluno[i].registro);
        fprintf(f2, "Nota Final: %d - Conceito %c - %s\n", turma1.aluno[i].notafinal, turma1.aluno[i].conceito, turma1.aluno[i].situacao);
    }
    if (prof.numturmas == 2){
        fprintf(f2, "\nTurma %s - %s\n", prof.turma2codigo, prof.turma2nome);
        for (int i = 0; i < turma2.numalunos; i++){
            fprintf(f2, "Aluno: %s", turma2.aluno[i].nome);
            fprintf(f2, "Matricula: %d\n", turma2.aluno[i].registro);
            fprintf(f2, "Nota Final: %d - Conceito %c - %s\n", turma2.aluno[i].notafinal, turma2.aluno[i].conceito, turma2.aluno[i].situacao);
    }   }       
    fclose(f2);
}

int main(int argc, char **argv) {
    struct Professor prof;
    struct Turma turma1, turma2;
    FILE *f1 = fopen(argv[1], "r");
    if (!f1) {
        fprintf(stderr, "Erro ao abrir o arquivo");
        return 1;
    }
                                        // Pega as informações do professor do arquivo externo
    fgets(prof.nome, 100, f1);
    fscanf(f1, "%d\n%d", &prof.registro, &prof.numturmas);
    fgets(prof.turma1nome, 100, f1);
    fgets(prof.turma1nome, 100, f1);
    fgets(prof.turma1codigo, 10, f1);
    prof.turma1codigo[strlen(prof.turma1codigo)-1] = '\0';
    prof.turma1nome[strlen(prof.turma1nome)-1] = '\0';
    if (prof.numturmas == 2){
        fgets(prof.turma2nome, 100, f1);
        fgets(prof.turma2codigo, 10, f1);
        prof.turma2codigo[strlen(prof.turma2codigo)-1] = '\0';
        prof.turma2nome[strlen(prof.turma2nome)-1] = '\0';
    }
                                            //Pega as informações dos alunos da turma 1
    fscanf(f1, "%d", &turma1.numalunos);
    for (int i = 0; i < turma1.numalunos; i++){
        fgets(turma1.aluno[i].nome, 100, f1);
        fgets(turma1.aluno[i].nome, 100, f1);
        fscanf(f1, "%d", &turma1.aluno[i].registro);
    }
                                            //Pega as informações dos alunos da turma 2 (se existir)
    if (prof.numturmas == 2){
        fscanf(f1, "%d", &turma2.numalunos);
        for (int i = 0; i < turma2.numalunos; i++){
            fgets(turma2.aluno[i].nome, 100, f1);
            fgets(turma2.aluno[i].nome, 100, f1);
            fscanf(f1, "%d", &turma2.aluno[i].registro);
        }
    }
    fclose(f1);
                                            //Seta todos os valores de nota final dos alunos para 0
    for (int i = 0; i < 6; i++){
        turma1.aluno[i].notafinal = 0;
        turma1.aluno[i].conceito = 'F';
        strcpy(turma1.aluno[i].situacao, "Reprovado");
        turma2.aluno[i].notafinal = 0;
        turma2.aluno[i].conceito = 'F';
        strcpy(turma2.aluno[i].situacao, "Reprovado");
    }

    int loop = 1;
    menu();
    while (loop) {                           // Loop para receber os inputs e rodar o programa (chamando funções)
        int comando;
        scanf("%d", &comando);
        getchar();
        switch (comando) {
            case 1:
                Informacoes_professor(prof, turma1, turma2);
                break;
            case 2:
                Informacoes_aluno(prof, turma1, turma2);
                break;
            case 3:
                Inserir_aluno(&prof, &turma1, &turma2);
                break;
            case 4:
                Lancar_notas(&prof, &turma1, &turma2);
                break;
            case 5:
                Informacoes_turma(prof, turma1, turma2);
                break;
            case 6:
                Situacao_alunos(prof, turma1, turma2);
                break;
            case 7:                          // o case 7 para o loop e exporta os dados
                loop = 0;
                Exportar_dados(argv, prof, turma1, turma2);
                break;
    }   }

    return 0;
}