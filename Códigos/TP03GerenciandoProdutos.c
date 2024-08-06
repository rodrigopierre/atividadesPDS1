#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct noh {                 // Estrutura usada para cada nó da árvore
    int id; 
    struct noh *esq;
    struct noh *dir;
    char nome[50];
    char dep[50];
    float preco;
};

void menu(){                // função que imprime o menu de opções para o usuário
    printf("1 - Procurar por ID\n");
    printf("2 - Procurar por Departamento\n");
    printf("3 - Inserir Produto\n");
    printf("4 - Filtrar por Preco\n5 - Sair\n");
}

struct noh* criarNoh(struct noh *noh, char *linha){      // função que cria um novo nó na árvore
    int id;
    char nome[100], dep[100];
    float preco;
    sscanf(linha, "%d %s %s %f", &id, nome, dep, &preco);
    if (noh == NULL) {
        noh = (struct noh*)malloc(sizeof(struct noh));
        noh->id = id;
        strcpy(noh->nome, nome);
        strcpy(noh->dep, dep);
        noh->preco = preco;
        noh->esq = noh->dir = NULL;
    } else if (id > noh->id)
        noh->dir = criarNoh(noh->dir, linha);
    else
        noh->esq = criarNoh(noh->esq, linha);         // retorna a nova árvore
    return noh;
}
                                // função que remove o espaço de memória usado para a árvore na heap (alocação dinamica)
void freeArvore(struct noh *noh) { 
    if (noh != NULL) {
        freeArvore(noh->dir);
        freeArvore(noh->esq);
        free(noh);
}   }
                                // função usada para procurar um nó que contenha o ID buscado e imprime o produto referente
void procurarID(struct noh *noh, int id) {   
    if (noh != NULL) {
        printf("(%s) %s - R$ %.2f\n", noh->dep, noh->nome, noh->preco);
        if (noh->id == id) return;
        if (id < noh->id) {
            return procurarID(noh->esq, id);
        } else {
            return procurarID(noh->dir, id);
    }   }
    printf("Produto nao encontrado!\n");
}
                                // função usada para procurar todos os nós referentes a um departamento buscado
int procurarDepartamento(struct noh *noh, char *departamento, int *ids, int qntd) {
    if (noh != NULL) {
        qntd = procurarDepartamento(noh->dir, departamento, ids, qntd);
        qntd = procurarDepartamento(noh->esq, departamento, ids, qntd);
        if (!strcmp(noh->dep, departamento)) {
            ids[qntd] = noh->id;
            qntd++;
    }   }  
    return qntd;                // retorna a quantidade de nós (produtos) encontrados
}
                                // função que busca todos os nós que possuem produtos com um preço inferior ou igual ao buscado
int encontrarPrecos(struct noh *noh, float *precos, float preco, int qntd){
    if (noh != NULL) {
        if (noh->preco <= preco) {
            precos[qntd] = noh->preco;
            qntd++;
        }
        qntd = encontrarPrecos(noh->dir, precos, preco, qntd);
        qntd = encontrarPrecos(noh->esq, precos, preco, qntd);
    }     
    return qntd;                // retorna a quantidade de nós (produtos) encontrados
}

void ordenarPrecos(float *vet, int n){    // função que ordena os preços dentro de um vetor (float)
    int i, j;
    float temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (vet[j] > vet[j+1]) {
                temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
}   }   }   }

void ordenarIds(int *vet, int n){       // função que ordena os IDs dentro de um vetor (int)
    int i, j;
    int temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (vet[j] > vet[j+1]) {
                temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
}   }   }   }
                                        // função que busca o nó do produto com o preço em questão e imprime os dados
void imprimirProdutoPreco(struct noh *noh, float preco){ 
    if (noh != NULL) {
        if (noh->preco == preco) { printf("(%s) %s - R$ %.2f\n", noh->dep, noh->nome, noh->preco); return; } 
    imprimirProdutoPreco(noh->dir, preco);
    imprimirProdutoPreco(noh->esq, preco);
}   }
                                        // função que busca o nó do produto com o ID em questão e imprime os dados
void imprimirProdutoId(struct noh *noh, int id){
    if (noh != NULL) {
        if (noh->id == id) { printf("(%s) %s - R$ %.2f\n", noh->dep, noh->nome, noh->preco); return; } 
    imprimirProdutoId(noh->dir, id);
    imprimirProdutoId(noh->esq, id);
}   } 

int main(int argc, char **argv){
    struct noh *noh1 = NULL;
    FILE *f1 = fopen(argv[1], "r");
    if (!f1) { fprintf(stderr, "Erro ao abrir o arquivo"); return 1; }
    char* linha;
    linha=(char*)malloc(200*sizeof(char));      // Lê dados do arquivo externo e cria um nó para cada produto
    while (fgets(linha, 200 , f1) != NULL)
        noh1 = criarNoh(noh1, linha);
    free(linha);
    fclose(f1);

    int loop = 1;
    menu();
    while (loop) {
        int comando, id, qntd = 0, ids[20];
        float preco, precos[20];
        char departamento[50], linha[200];
        scanf("%d", &comando); getchar();               // recebe o comando do usuário
        switch (comando) {
            case 1:
                scanf("%d", &id); getchar();            // procura produto pelo ID
                procurarID(noh1, id);
                break;
            case 2:
                fgets(departamento, 50, stdin);
                departamento[strlen(departamento)-1] = '\0';    // procura produtos pelo departamento 
                qntd = procurarDepartamento(noh1, departamento, ids, qntd);
                if (!qntd) printf("Departamento vazio!\n");
                else {
                    ordenarIds(ids, qntd);
                    for (int i = 0; i < qntd; i++)
                        imprimirProdutoId(noh1, ids[i]);
                }
                break;
            case 3:
                fgets(linha, 200, stdin);
                noh1 = criarNoh(noh1, linha);          // insere novo produto e cria novo nó
                break;
            case 4:
                scanf("%f", &preco); getchar();     // pega os produtos com preço inferior ao digitado e imprime de forma ordenada (crescente)
                qntd = encontrarPrecos(noh1, precos, preco, qntd); 
                if (!qntd) printf("Sem resultados para o filtro!\n");
                else {
                    ordenarPrecos(precos, qntd);
                    for (int i = 0; i < qntd; i++)
                        imprimirProdutoPreco(noh1, precos[i]);
                }
                break;
            case 5:
                loop = 0;               // quebra o loop
                break;
    }   }

    freeArvore(noh1);           // libera a memória de toda a árvore
}