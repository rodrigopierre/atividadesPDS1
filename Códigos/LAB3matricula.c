#include <stdio.h>

// Matrícula em Comum:
// Faça um programa que leia dois vetores de inteiros representando o número de
// matrícula de alunos matriculados respectivamente em AEDS 1 e Cálculo 1. Em
// seguida, o programa deverá imprimir o número de matrícula dos alunos que estão
// matriculados simultaneamente nestas duas disciplinas (ou seja, calcular a interseção
// dos dois vetores).
// O primeiro valor se refere à quantidade de alunos na disciplina de AEDS 1. Em
// seguida, são informadas as matrículas de cada aluno na disciplina. A mesma
// sequência é fornecida para a disciplina de Cálculo 1. Por fim, deve-se imprimir a
// matrícula dos alunos que estão matriculados em ambas disciplinas.

int main(){
    int aeds1, calc1, i, c;
    scanf("%d", &aeds1);
    int m_aeds1[aeds1], m_calc1[calc1];
    for (i = 0; i < aeds1; i++)
        scanf("%d", &m_aeds1[i]);
    scanf("%d", &calc1);
    for (i = 0; i < calc1; i++)
        scanf("%d", &m_calc1[i]);
    for (i = 0; i < calc1; i++){
        for (c = 0; c < aeds1; c++){
            if (m_calc1[i] == m_aeds1[c])
                printf("%d\n", m_calc1[i]);
        }
    }
}