//4) Elabore um programa no qual o usuário informe o nome de um arquivo texto e uma palavra, e o programa informe o número de vezes que aquela palavra aparece dentro do arquivo.

#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file1;

    char reader[100];
    char name1 = "file.txt", word = "banana";
    int result = 0;

    system("cls");

    // printf("File to search: ");
    // scanf("%s", name1);
    // printf("Word to count: ");
    // scanf("%s", word);

    file1 = fopen(name1, "r");

    if (!file1)
    {
        printf("Error opening file 1. System Pause\n");
        system("pause");
        exit(1);
    }

    while (fgets(reader, strlen(word), file1) != EOF)
    {
        if (reader == word)
        {
            result = result + 1;
        }

        strcpy(reader, "");
    }

    printf("Number of incidences:%i", result);

    fclose(file1);

    return 0;
}