// Elabore um programa no qual o usuário informe o nome de um arquivo texto e uma palavra, e o programa informe o número de vezes que aquela palavra aparece dentro do arquivo

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    system("cls");

    FILE *file;
    char fileName[100], src[100], srcWord[100], line[1000];
    int flag = 0, i = 0;

    printf("\nFile:");
    scanf("%s", &fileName);
    strcat(fileName, ".txt");

    printf("\nWord to Search:");
    scanf("%s", &src);

    printf("\n\n");

    file = fopen(fileName, "r");

    while (fscanf(file, "%s", &srcWord) != EOF)
    {

        if (strcmp(srcWord, src) == 0)
        {
            flag += 1;
        }
    }

    if (flag > 0)
    {
        printf("%d incidences of the %s were found", flag, src);
    }
    else
    {
        printf("Word not Found");
    }

    printf("\n\n");

    return 0;
}
