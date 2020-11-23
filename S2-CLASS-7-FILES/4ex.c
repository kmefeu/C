#include <stdio.h>
#include <string.h>

int main()
{

    FILE *arq1;
    char word[128];
    int result = 0;

    arq1 = fopen("file.txt", "r");

    if (arq1 == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    while (fscanf(arq1, "%s", &word) != EOF)
    {
       
        if (strcmp(word, "banana") == 0)
        {
            result += 1;
        }
    }

printf("Number of incidences:%d", result);

    return 0;
}