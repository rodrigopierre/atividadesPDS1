#include <stdio.h>
#include <stdlib.h>

// Jogo de Batalha Naval

char mat1[20][20];
char mat2[20][20];
char mat1oculta[20][20];
char mat2oculta[20][20];


int mostra1(){
    printf("Mar do Jogador 1: \n");
    printf("   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20\n");
    for (int i = 0; i < 20; i++){
        if (i+1 < 10)
            printf("%d  ", i+1);
        else
            printf("%d ", i+1);
        for (int j = 0; j < 20; j++){
            printf("%c  ", mat1[i][j]);
        }
        printf("\n");
    }
}

int mostra2(){
    printf("Mar do Jogador 2: \n");
    printf("   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20\n");
    for (int i = 0; i < 20; i++){
        if (i+1 < 10)
            printf("%d  ", i+1);
        else
            printf("%d ", i+1);
        for (int j = 0; j < 20; j++){
            printf("%c  ", mat2[i][j]);
        }
        printf("\n");
    }
}

int mostra1oculto(){
    printf("Mar do Jogador 2: \n");
    printf("   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20\n");
    for (int i = 0; i < 20; i++){
        if (i+1 < 10)
            printf("%d  ", i+1);
        else
            printf("%d ", i+1);
        for (int j = 0; j < 20; j++){
            printf("%c  ", mat1oculta[i][j]);
        }
        printf("\n");
    }
}

int mostra2oculto(){
    printf("Mar do Jogador 2: \n");
    printf("   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20\n");
    for (int i = 0; i < 20; i++){
        if (i+1 < 10)
            printf("%d  ", i+1);
        else
            printf("%d ", i+1);
        for (int j = 0; j < 20; j++){
            printf("%c  ", mat2oculta[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int num_navios, num_rodadas, coord_x, coord_y, pont1 = 0, pont2 = 0, sleep_seconds = 2;
    char tipo_navio, orient_navio;
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            mat1[i][j] = '/';
            mat2[i][j] = '/';
            mat1oculta[i][j] = '~';
            mat2oculta[i][j] = '~';
        }
    }
    system("clear");
    printf("=====================================\n");
    printf("  Bem vindos ao Jogo Batalha Naval!\n");
    printf("=====================================\n");
    printf("Quantos navios serão posicionados? \n");
    scanf("%d", &num_navios);
    printf("Quantas serão as rodadas? \n");
    scanf("%d", &num_rodadas);
    system("clear");
    printf("Vez do Jogador 1 posicionar seus navios: \n");
    for (int c = 1; c <= num_navios; c++){
        mostra1oculto();
        printf("Digite a coordenada x do centro do navio %d: (1 - 20) ", c);
        scanf("%d", &coord_x);
        printf("Digite a coordenada y do centro do navio %d: (1 - 20) ", c);
        scanf("%d", &coord_y);
        getchar();
        printf("Digite o tipo do navio %d: (C/E/P) ", c);
        scanf("%c", &tipo_navio);
        getchar();
        printf("Digite a orientação do navio %d: (V/H) ", c);
        scanf("%c", &orient_navio);
        if (tipo_navio == 'C'){
            if (orient_navio == 'V'){
                mat1oculta[coord_y-1][coord_x-1] = 'C';
                mat1oculta[coord_y][coord_x-1] = 'C';
                mat1oculta[coord_y-2][coord_x-1] = 'C';
            } else {
                mat1oculta[coord_y-1][coord_x-1] = 'C';
                mat1oculta[coord_y-1][coord_x] = 'C';
                mat1oculta[coord_y-1][coord_x-2] = 'C';
            }
        } else if (tipo_navio == 'E'){
            if (orient_navio == 'V'){
                mat1oculta[coord_y-1][coord_x-1] = 'E';
                mat1oculta[coord_y][coord_x-1] = 'E';
                mat1oculta[coord_y-2][coord_x-1] = 'E';
                mat1oculta[coord_y+1][coord_x-1] = 'E';
                mat1oculta[coord_y-3][coord_x-1] = 'E';
            } else {
                mat1oculta[coord_y-1][coord_x-1] = 'E';
                mat1oculta[coord_y-1][coord_x] = 'E';
                mat1oculta[coord_y-1][coord_x-2] = 'E';
                mat1oculta[coord_y-1][coord_x+1] = 'E';
                mat1oculta[coord_y-1][coord_x-3] = 'E';
            }
        } else {
            if (orient_navio == 'V'){
                mat1oculta[coord_y-1][coord_x-1] = 'P';
                mat1oculta[coord_y][coord_x-1] = 'P';
                mat1oculta[coord_y-2][coord_x-1] = 'P';
                mat1oculta[coord_y+1][coord_x-1] = 'P';
                mat1oculta[coord_y-3][coord_x-1] = 'P';
                mat1oculta[coord_y+2][coord_x-1] = 'P';
                mat1oculta[coord_y-4][coord_x-1] = 'P';
            } else {
                mat1oculta[coord_y-1][coord_x-1] = 'P';
                mat1oculta[coord_y-1][coord_x] = 'P';
                mat1oculta[coord_y-1][coord_x-2] = 'P';
                mat1oculta[coord_y-1][coord_x+1] = 'P';
                mat1oculta[coord_y-1][coord_x-3] = 'P';
                mat1oculta[coord_y-1][coord_x+2] = 'P';
                mat1oculta[coord_y-1][coord_x-4] = 'P';
            }
        }
        system("clear");
    }
    system("clear");
    printf("Vez do Jogador 2 posicionar seus navios: \n");
    for (int c = 1; c <= num_navios; c++){
        mostra2oculto();
        printf("Digite a coordenada x do centro do navio %d: (1 - 20) ", c);
        scanf("%d", &coord_x);
        printf("Digite a coordenada y do centro do navio %d: (1 - 20) ", c);
        scanf("%d", &coord_y);
        getchar();
        printf("Digite o tipo do navio %d: (C/E/P) ", c);
        scanf("%c", &tipo_navio);
        getchar();
        printf("Digite a orientação do navio %d: (V/H) ", c);
        scanf("%c", &orient_navio);
        if (tipo_navio == 'C'){
            if (orient_navio == 'V'){
                mat2oculta[coord_y-1][coord_x-1] = 'C';
                mat2oculta[coord_y][coord_x-1] = 'C';
                mat2oculta[coord_y-2][coord_x-1] = 'C';
            } else {
                mat2oculta[coord_y-1][coord_x-1] = 'C';
                mat2oculta[coord_y-1][coord_x] = 'C';
                mat2oculta[coord_y-1][coord_x-2] = 'C';
            }
        } else if (tipo_navio == 'E'){
            if (orient_navio == 'V'){
                mat2oculta[coord_y-1][coord_x-1] = 'E';
                mat2oculta[coord_y][coord_x-1] = 'E';
                mat2oculta[coord_y-2][coord_x-1] = 'E';
                mat2oculta[coord_y+1][coord_x-1] = 'E';
                mat2oculta[coord_y-3][coord_x-1] = 'E';
            } else {
                mat2oculta[coord_y-1][coord_x-1] = 'E';
                mat2oculta[coord_y-1][coord_x] = 'E';
                mat2oculta[coord_y-1][coord_x-2] = 'E';
                mat2oculta[coord_y-1][coord_x+1] = 'E';
                mat2oculta[coord_y-1][coord_x-3] = 'E';
            }
        } else {
            if (orient_navio == 'V'){
                mat2oculta[coord_y-1][coord_x-1] = 'P';
                mat2oculta[coord_y][coord_x-1] = 'P';
                mat2oculta[coord_y-2][coord_x-1] = 'P';
                mat2oculta[coord_y+1][coord_x-1] = 'P';
                mat2oculta[coord_y-3][coord_x-1] = 'P';
                mat2oculta[coord_y+2][coord_x-1] = 'P';
                mat2oculta[coord_y-4][coord_x-1] = 'P';
            } else {
                mat2oculta[coord_y-1][coord_x-1] = 'P';
                mat2oculta[coord_y-1][coord_x] = 'P';
                mat2oculta[coord_y-1][coord_x-2] = 'P';
                mat2oculta[coord_y-1][coord_x+1] = 'P';
                mat2oculta[coord_y-1][coord_x-3] = 'P';
                mat2oculta[coord_y-1][coord_x+2] = 'P';
                mat2oculta[coord_y-1][coord_x-4] = 'P';
            }
        }
        system("clear");
    }
    for (int c = 1; c <= num_rodadas; c++){
        system("clear");
        printf("RODADA %d\n", c);
        mostra2();
        printf("Vez do Jogador 1 atacar: \n");
        printf("Digite a coordenada x: \n");
        scanf("%d", &coord_x);
        printf("Digite a coordenada y: \n");
        scanf("%d", &coord_y);
        system("clear");
        printf("RODADA %d\n", c);
        mat2[coord_y-1][coord_x-1] = 'O';
        mostra2();
        printf("POOOOOOOOOOWWWWWW");
        getchar();
        scanf("%c", &tipo_navio);
        system("clear");
        printf("RODADA %d\n", c);
        mat2[coord_y-1][coord_x-1] = mat2oculta[coord_y-1][coord_x-1];
        mostra2();
        if (mat2[coord_y-1][coord_x-1] == '~'){
            printf("O ataque do jogador 1 atingiu apenas água, então nada acontece.");
        } else if (mat2[coord_y-1][coord_x-1] == 'C'){
            printf("O jogador 1 acertou um contratorpedeiro do adversário, ganhando 2 pontos por isso!");
            pont1 += 2;
        } else if (mat2[coord_y-1][coord_x-1] == 'E'){
            printf("O jogador 1 acertou um encouraçado do adversário, ganhando 5 pontos por isso!");
            pont1 += 5;
        } else if (mat2[coord_y-1][coord_x-1] == 'P'){
            printf("O jogador 1 acertou um porta-aviões do adversário, ganhando 10 pontos por isso!");
            pont1 += 10;
        }
        getchar();
        scanf("%c", &tipo_navio);
        system("clear");
        printf("RODADA %d\n", c);
        mostra1();
        printf("Vez do Jogador 2 atacar: \n");
        printf("Digite a coordenada x: \n");
        scanf("%d", &coord_x);
        printf("Digite a coordenada y: \n");
        scanf("%d", &coord_y);
        system("clear");
        printf("RODADA %d\n", c);
        mat1[coord_y-1][coord_x-1] = 'O';
        mostra1();
        printf("POOOOOOOOOOWWWWWW");
        getchar();
        scanf("%c", &tipo_navio);
        system("clear");
        printf("RODADA %d\n", c);
        mat1[coord_y-1][coord_x-1] = mat1oculta[coord_y-1][coord_x-1];
        mostra1();
        if (mat1[coord_y-1][coord_x-1] == '~'){
            printf("O ataque do jogador 2 atingiu apenas água, então nada acontece.");
        } else if (mat1[coord_y-1][coord_x-1] == 'C'){
            printf("O jogador 2 acertou um contratorpedeiro do adversário, ganhando 2 pontos por isso!");
            pont2 += 2;
        } else if (mat1[coord_y-1][coord_x-1] == 'E'){
            printf("O jogador 2 acertou um encouraçado do adversário, ganhando 5 pontos por isso!");
            pont2 += 5;
        } else if (mat1[coord_y-1][coord_x-1] == 'P'){
            printf("O jogador 2 acertou um porta-aviões do adversário, ganhando 10 pontos por isso!");
            pont2 += 10;
        }
        getchar();
        scanf("%c", &tipo_navio);
    }
    system("clear");
    printf("ACABOU O JOGO!\n");
    mostra1oculto();
    mostra2oculto();
    if (pont1 > pont2){
        printf("O jogador 1 venceu com %d pontos, contra %d pontos do adversário.\n", pont1, pont2);
    } else if (pont2 > pont1){
        printf("O jogador 2 venceu com %d pontos, contra %d pontos do adversário.\n", pont2, pont1);
    } else{
        printf("O jogo terminou empatado em %d pontos.\n", pont1);
    }
}