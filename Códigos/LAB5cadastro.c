#include <stdio.h>
#include <string.h>


// Escreva um programa que leia os dados de 8 produtos descritos em termos de:
// ● nome (máximo 50 caracteres)
// ● marca (máximo 50 caracteres)
// ● preco (float)
// E imprima:
// ● o número de produtos de cada marca
// ● o preço médio dos produtos total
// ● o preço médio por marca


int main() {

struct produto {
    char nome[50];
    char marca[50];
    float preco;
    int repetidos;
    float media_repetidos;
};

struct produto p[8];
float mediatotal = 0, media_repetidos = 0; 
int repetidos = 0, maior = 0, primeiro, segundo, terceiro, quarto, quinto, sexto, setimo, oitavo;

segundo = terceiro = quarto = quinto = sexto = setimo = oitavo = 10;

for (int i = 0; i < 8; i++) {
    scanf("%s %s %f", p[i].nome, p[i].marca, &p[i].preco);
}

for (int i = 0; i < 8; i++) {
    mediatotal += p[i].preco;
}
mediatotal = mediatotal / 8;

for (int i = 0; i < 8; i++) {
    repetidos = 0;
    media_repetidos = 0;
    for (int c = 0; c < 8; c++) {
        if (!strcmp(p[i].marca, p[c].marca)) {
            repetidos++;
            media_repetidos += p[c].preco;
        }
    p[i].media_repetidos = media_repetidos / repetidos;
    p[i].repetidos = repetidos;
    }
}


for (int i = 0; i < 8; i++) {
    if (p[i].repetidos > maior) {
        maior = p[i].repetidos; 
        primeiro = i;
    }
}

maior = 0;
for (int i = 0; i < 8; i++) {
    if (p[i].repetidos > maior && strcmp(p[i].marca, p[primeiro].marca)) {
        maior = p[i].repetidos; 
        segundo = i;
    }
}

maior = 0;
for (int i = 0; i < 8; i++) {
    if (p[i].repetidos > maior && strcmp(p[i].marca, p[primeiro].marca) && strcmp(p[i].marca, p[segundo].marca)) {
        maior = p[i].repetidos; 
        terceiro = i;
    }
}

maior = 0;
for (int i = 0; i < 8; i++) {
    if (p[i].repetidos > maior && strcmp(p[i].marca, p[primeiro].marca) && strcmp(p[i].marca, p[segundo].marca) && strcmp(p[i].marca, p[terceiro].marca)) {
        maior = p[i].repetidos; 
        quarto = i;
    }
}

maior = 0;
for (int i = 0; i < 8; i++) {
    if (p[i].repetidos > maior && strcmp(p[i].marca, p[primeiro].marca) && strcmp(p[i].marca, p[segundo].marca) && strcmp(p[i].marca, p[terceiro].marca) && strcmp(p[i].marca, p[quarto].marca)) {
        maior = p[i].repetidos; 
        quinto = i;
    }
}

maior = 0;
for (int i = 0; i < 8; i++) {
    if (p[i].repetidos > maior && strcmp(p[i].marca, p[primeiro].marca) && strcmp(p[i].marca, p[segundo].marca) && strcmp(p[i].marca, p[terceiro].marca) && strcmp(p[i].marca, p[quarto].marca) && strcmp(p[i].marca, p[quinto].marca)) {
        maior = p[i].repetidos; 
        sexto = i;
    }
}

maior = 0;
for (int i = 0; i < 8; i++) {
    if (p[i].repetidos > maior && strcmp(p[i].marca, p[primeiro].marca) && strcmp(p[i].marca, p[segundo].marca) && strcmp(p[i].marca, p[terceiro].marca) && strcmp(p[i].marca, p[quarto].marca) && strcmp(p[i].marca, p[quinto].marca) && strcmp(p[i].marca, p[sexto].marca)) {
        maior = p[i].repetidos; 
        setimo = i;
    }
}

maior = 0;
for (int i = 0; i < 8; i++) {
    if (p[i].repetidos > maior && strcmp(p[i].marca, p[primeiro].marca) && strcmp(p[i].marca, p[segundo].marca) && strcmp(p[i].marca, p[terceiro].marca) && strcmp(p[i].marca, p[quarto].marca) && strcmp(p[i].marca, p[quinto].marca) && strcmp(p[i].marca, p[sexto].marca) && strcmp(p[i].marca, p[setimo].marca)) {
        maior = p[i].repetidos; 
        oitavo = i;
    }
}


printf("%s %d\n", p[primeiro].marca, p[primeiro].repetidos);

if (segundo != 10) {
    printf("%s %d\n", p[segundo].marca, p[segundo].repetidos);
    if (terceiro != 10) {
        printf("%s %d\n", p[terceiro].marca, p[terceiro].repetidos);
        if (quarto != 10) {
            printf("%s %d\n", p[quarto].marca, p[quarto].repetidos);
            if (quinto != 10) {
                printf("%s %d\n", p[quinto].marca, p[quinto].repetidos);
                if (sexto != 10) {
                    printf("%s %d\n", p[sexto].marca, p[sexto].repetidos);
                    if (setimo != 10) {
                        printf("%s %d\n", p[setimo].marca, p[setimo].repetidos);
                        printf("%s %d\n", p[oitavo].marca, p[oitavo].repetidos);
}}}}}}

printf("media total %.2f\n", mediatotal);
printf("media %s %.2f\n", p[primeiro].marca, p[primeiro].media_repetidos);

if (segundo != 10) {
    printf("media %s %.2f\n", p[segundo].marca, p[segundo].media_repetidos);
    if (terceiro != 10) {
        printf("media %s %.2f\n", p[terceiro].marca, p[terceiro].media_repetidos);
        if (quarto != 10) {
            printf("media %s %.2f\n", p[quarto].marca, p[quarto].media_repetidos);
            if (quinto != 10) {
                printf("media %s %.2f\n", p[quinto].marca, p[quinto].media_repetidos);
                if (sexto != 10) {
                    printf("media %s %.2f\n", p[sexto].marca, p[sexto].media_repetidos);
                    if (setimo != 10) {
                        printf("media %s %.2f\n", p[setimo].marca, p[setimo].media_repetidos);
                        printf("media %s %.2f\n", p[oitavo].marca, p[oitavo].media_repetidos);   
}}}}}}

}
