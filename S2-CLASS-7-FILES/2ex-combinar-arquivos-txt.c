//Escreva um programa que leia do usuário os nomes de dois arquivos texto. Crie um terceiro arquivo texto com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do segundo).

#include <stdio.h>

int main()
{
    FILE *file1;
    FILE *file2;
    FILE *file3;

    char reader[1000];
    char name1[300], name2[300];

    system("cls");

    printf("File 1: ");
    scanf("%s", name1);
    printf("File 2: ");
    scanf("%s", name2);

    file1 = fopen(name1, "r");

    if (!file1)
    {
        printf("Error opening file 1. System Pause\n");
        system("pause");
        exit(1);
    }
    file2 = fopen(name2, "r");
    if (!file2)
    {
        printf("Error opening file 2. System Pause\n");
        system("pause");
        exit(1);
    }
    file3 = fopen("file3.txt", "a");
    if (!file3)
    {
        printf("Error opening file 3. System Pause!\n");
        system("pause");
        exit(1);
    }

    // add string size detector

    while (fgets(reader, sizeof reader, file1) != NULL)
    {
        fputs(reader, file3);
    }
    while (fgets(reader, sizeof reader, file2) != NULL)
    {
        fputs(reader, file3);
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);
    return 0;
}