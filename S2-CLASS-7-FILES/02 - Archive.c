// Escreva um programa que leia do usuário os nomes de dois 
// arquivos texto. Crie um terceiro arquivo texto com o conteúdo dos dois primeiros juntos
// (o conteúdo do primeiro seguido do segundo).
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *arch1, *arch2, *arch3;
    char archive1[100], archive2[100];
    printf("Hello! please, enter name of archive 1\n");
    scanf("%s",&archive1);
    printf("please, enter name of archive 2\n");
    scanf("%s",&archive2);
    arch1=fopen(archive2,"r");
    arch2=fopen(archive1,"r");
    arch3=fopen(strcat(strcat(archive1, archive2),".txt") ,"w");
    if (arch1==NULL || arch2==NULL || arch3==NULL){
        printf("Error to open archive\n");
        system("pause");
        exit(1);
    }
    char letra;
    while( (letra = fgetc(arch1)) != EOF ){
        fprintf(arch3, "%c", letra);
    }
        while( (letra = fgetc(arch2)) != EOF ){
        fprintf(arch3, "%c", letra);
    }
    fclose(arch1);
    fclose(arch2);
    fclose(arch3);
    return 0;
}