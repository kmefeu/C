// Escreva uma função que receba como parâmetro o nome de um arquivo texto
//  e retorne qunatas vogais esse arquivo possui.

#include <stdio.h>
#include <string.h>

void main()
{

    char fileName[100];
    char letter;
    int n = 0;

    printf("\nFile:");
    scanf("%s", &fileName);
    strcat(fileName, ".txt");

    FILE *file = fopen(fileName, "r");

     if (file == NULL)
   {
      printf("\nError opening file. System Pause.\n");
      system("pause");
      exit(1);
   }

    while ((letter = fgetc(file)) != EOF)
    {
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u')
            n++;
    }

    printf("\n\nVowel incidences: %d\n", n);
    fclose(file);

    printf("\n\n");

    return 0;
}
