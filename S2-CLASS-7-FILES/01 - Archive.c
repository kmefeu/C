// Escreva um programa que leia do usuário o nome de um arquivo texto.
// Em seguida, mostre na tela quantas linhas esse arquivo possui.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
   int nlines = 0;
   FILE *file;
   char fileName[50];
   char letter;

   printf("File:");
   gets(fileName);
   strcat(fileName, ".txt");

   file = fopen(fileName, "r");

   if (file == NULL)
   {
      printf("Error opening file. System Pause.\n");
      system("pause");
      exit(1);
   }

   while (!feof(file))
   {
      letter = fgetc(file);

      if (letter == '\n')
      {
         nlines = nlines + 1;
      }
   }

   printf("\nNumber of lines: %d\n", nlines);
   getchar();
   fclose(file);
}
