// Escreva um programa para conveter o conteúdo de arquivo texto em caracteres maiúsculo. O programa deverá ler do usuário o nome do arquivo a ser convertido e o nome do arquivo a ser salvo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    system("cls");
    
    FILE *file1;
    FILE *file2;

    char reader [1000];
    char fileName1 [300], fileName2 [300];

    printf ("\nFile:");
    scanf ("%s", fileName1);
    strcat(fileName1, ".txt");

    
    printf ("\nSave converted file as:");
    scanf ("%s", fileName2);
    strcat(fileName2, ".txt");


    file1 = fopen (fileName1, "r");
    file2 = fopen(fileName2, "w+");
  
     if (file1 == NULL)
   {
      printf("Error opening file. System Pause.\n");
      system("pause");
      exit(1);
   }

    while (fgets (reader, sizeof reader, file1) != NULL)
    {
        fputs (strupr(reader), file2);
    }
    
    fclose (file1);
    fclose (file2);
    
    return 0;
}
