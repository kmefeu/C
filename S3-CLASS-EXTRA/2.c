#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string.h>

int main(void)
{

    int i, j, a, b, c;
    int n = 0;

    printf("N Elementos : ");
    scanf("%d", &n);

    int vector[n];
    char alphaVector[n];
    int matrix[n][n];
    char alphaMatrix[n][n];

    for (i = 0; i < n; i++)
    {
        printf("Insira o %d� elemento: ", i);
        fflush(stdin);
        scanf("%c", &alphaVector[i]);
        vector[i] = i;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%i %i - Adicione o valor de %c x %c: ", i, j, alphaVector[i], alphaVector[j]);
            fflush(stdin);
            scanf("%c", &alphaMatrix[i][j]);
            for (int m = 0; m < n; m++)
            {
                if (alphaMatrix[i][j] == alphaVector[m])
                {
                    matrix[i][j] = vector[m];
                }
            }
        }
    }

    printf("%4c |", ' ');
    for (i = 0; i < n; i++)
    {
        printf("%4c", alphaVector[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%4c |", alphaVector[i]);
        for (j = 0; j < n; j++)
        {
            printf("%4c", alphaMatrix[i][j]);
        }
        printf("\n");
    }

    for (a = 0; a < n; a++)
    {
        for (b = 0; b < n; b++)
        {
            for (c = 0; c < n; c++)
            {
                if (matrix[matrix[a][b]][c] != matrix[matrix[b][c]][a])
                {
                    printf("%i != %i\n", matrix[matrix[a][b]][c], matrix[matrix[b][c]][a]);
                    printf("A operacao nao eh associativa\n");
                    system("pause");
                    return 0;
                }
                if (matrix[matrix[a][b]][c] == matrix[matrix[b][c]][a])
                {
                    printf("x=%i|y=%i|z=%i|%c = %c = V\n", a, b, c, alphaMatrix[matrix[a][b]][c], alphaMatrix[matrix[b][c]][a]);
                }
            }
        }
    }
    printf("A operacao e associativa!\n");
}
