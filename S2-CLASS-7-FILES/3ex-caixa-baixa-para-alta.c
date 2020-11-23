//3) Escreva um programa para converter o conteúdo de um arquivo texto em caracteres maiúsculos. O programa deverá ler do usuário o nome do arquivo a ser convertido e o nome do arquivo a ser salvo.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *file1;
    FILE *file2;

    char reader[1000];
    char name1[300], name2[300];

    int result;

    system("cls");

    printf("File to go uppercase: ");
    scanf("%s", name1);
    printf("Save file as: ");
    scanf("%s", name2);

    file1 = fopen(name1, "r");

    if (!file1)
    {
        printf("Error opening file 1. System Pause\n");
        system("pause");
        exit(1);
    }
    file2 = fopen(name2, "w");
    if (!file2)
    {
        printf("Error opening file 2. System Pause\n");
        system("pause");
        exit(1);
    }

    // add string size detector

    while (fgets(reader, sizeof reader, file1) != NULL)
    {
       result = fputs(tolower(reader), file2);
    }

    if (result == EOF){printf("fputs FAIL");}

    fclose(file1);
    fclose(file2);
    return 0;
}