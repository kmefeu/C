#include <stdio.h>

int main()
{

    system("cls");

    int m[5][5], i, j, xi, xj, x, xv = 0;

    printf("Digite o valor de X: ");
    scanf("%d", &x);

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {

            printf("\n\nElemento m[%d] [%d]=", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {

            if (m[i][j] == x)
            {

                xi = i;
                xj = j;
                xv = 1;
            }
        }
    }

    if (xv == 0)
    {
        printf("Nao foi encontrado nenhum valor igual X");
    }
    else
    {
        printf("\n\nO elemento m[%d] [%d] tem o mesmo valor de X", xi, xj);
    }

    printf("\n\n");

    return 0;
}