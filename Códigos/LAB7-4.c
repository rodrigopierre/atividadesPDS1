#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados{
char name[50];
int age;
char number[20];
};

int main (){
    char arqName[10];
    struct dados person[151];
    scanf("%s", arqName);
    getchar();
    FILE*archive=fopen(arqName, "ab+");

    int count = 0;
    while (fread(&person[count], sizeof(struct dados), 1, archive) == 1) {
        count++;
    }

    fclose(archive);

    int limit=100;
    char action[10];
    do{
        fgets(action,10,stdin);
        action[strlen(action)-1]='\0';
        
        if(!strcmp(action,"Inserir") && count < limit){
            char buffer[50];
            fgets(buffer,50,stdin);
            buffer[strlen(buffer)-1]='\0';
            sscanf(buffer,"%s %d %s",person[count].name, &person[count].age, person[count].number);
            printf("Registro %s %d %s inserido\n", person[count].name, person[count].age, person[count].number);
            count++;
        }
        
        else if(!strcmp(action,"Inserir") && count >= limit){
            char buffer[50];
            fgets(buffer,50,stdin);
            puts("Espaco insuficiente");
        }
        
        else if(!strcmp(action,"Excluir")){
            int find = 0;
            char buffer[50];
            fgets(buffer,50,stdin);
            buffer[strlen(buffer)-1]='\0';
            sscanf(buffer,"%s %d %s",person[150].name, &person[150].age, person[150].number);
            for(int x=0;x<=count;x++){
                if(!strcmp(person[150].name,person[x].name)){
                    find++;
                    limit++;
                    printf("Registro %s %d %s excluido\n", person[x].name, person[x].age, person[x].number);
                    person[x].name[0] = '\0';
                    person[x].age = 0; 
                    person[x].number[0] = '\0';
                    break;
                }
            }
            if(find == 0){
                printf("Registro %s invalido\n",person[150].name);
            }
        }
    
        else if(!strcmp(action,"Alterar")){
            int find = 0;
            char buffer[50];
            fgets(buffer,50,stdin);
            buffer[strlen(buffer)-1]='\0';
            sscanf(buffer,"%s %d %s",person[150].name, &person[150].age, person[150].number);
            for(int x = 0; x <= count; x++){
                if(!strcmp(person[150].name,person[x].name)){
                    find++;
                    printf("Registro %s %d %s inserido\n", person[150].name, person[150].age, person[150].number);
                    person[x].age = person[150].age;
                    strcpy(person[x].name, person[150].name);
                    strcpy(person[x].number, person[150].number);
                    break;
                }
            }
            if(find == 0){
                    printf("Registro %s invalido\n",person[150].name);
            }
        }
   
        else if(!strcmp(action,"Exibir")){
            int find = 0;
            char buffer[50];
            fgets(buffer,50,stdin);
            buffer[strlen(buffer)-1]='\0';
            sscanf(buffer,"%s %d %s",person[150].name, &person[150].age, person[150].number);
            for(int x = 0; x <= count; x++){
                if(!strcmp(person[150].name,person[x].name)){
                    find++;
                    printf("Registro %s %d %s exibido\n", person[x].name, person[x].age, person[x].number);
                    break;
                }
            }
            if(find == 0){
                printf("Registro %s invalido\n",person[150].name);
            }
        }

    }while(strlen(action) > 0);    

    return 0;
}