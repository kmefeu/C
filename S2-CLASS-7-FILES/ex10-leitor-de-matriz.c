// Um arquivo texto possui uma matriz de valores inteiroes dentro dele. Os dois primeiros números são as dimensões da matriz (linhas e colunas), enquanto o restante dos números são os valores de cada elemento da matriz. Escreva uma funçõa  que receba o nome do arquivo e retorne o ponteiro para uma matriz alocada dinamicamente contendo os valoreslidos do arquivo.

#include <stdio.h>
#include <locale.h>

int **AlocaMatriz(int m, int n)
{
  int **M;
  int i;

  M = (int **)malloc(sizeof(int *) * m);
  if (M == NULL)
  {
    printf("\n Out of Memory");
    exit(1);
  }
  for (i = 0; i < m; i++)
  {
    M[i] = (int *)malloc(sizeof(int) * n);
    if (M[i] == NULL)
    {
      printf("\n Out of Memory");
      exit(1);
    }
  }
  return M;
}

int main()
{
  FILE *file;
  char fileName[100];
  int **matrix, line, column, i, j;

  printf("\nFile:");
  scanf("%s", &fileName);
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

    line = (int)fgetc(file) - 48;
    column = (int)fgetc(file) - 48;
    matrix = AlocaMatriz(line, column);

    for (i = 0; i < line; i++)
    {

      for (j = 0; j < column; j++)
      {
        matrix[i][j] = (int)fgetc(file) - 48;
      }
    }

    fgetc(file);

    if (feof(file))
    {
      break;
    }
  }

   printf("\nMATRIZ:");
  printf(" %dx%d:\n", line, column);

  for (i = 0; i < line; i++)
  {

    for (j = 0; j < column; j++)

    {
      printf("%d ", matrix[i][j]);
    }

    printf("\n");
  }

  fclose(file);

  return 0;
}