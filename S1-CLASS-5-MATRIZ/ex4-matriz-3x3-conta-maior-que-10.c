#include <stdio.h>

int main()
{

    system("cls");

    int m[4][4], i, j, contador = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            printf("\n\nElemento m[%d] [%d]=", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            if (m[i][j] > 10)
            {
                contador = contador + 1;
            }
        }
    }

    printf(" A matriz contem %d valores maiores do que 10", contador);

    return 0;
}