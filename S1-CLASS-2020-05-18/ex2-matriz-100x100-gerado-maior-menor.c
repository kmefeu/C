#include <stdio.h>

int main()
{

    system("cls");

    int col, lin;

    printf("\n\nInsira o numero de colunas da sua matriz (MAX:100):");
    scanf("%d", &col);

    printf("\n\nInsira o numero de linhas da sua matriz (MAX:100):");
    scanf("%d", &lin);

    int m[col][lin], b[col][lin], c[col][lin], i, j, maior, im, jm, in, jn, menor;

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < lin; j++)
        {

            printf("\n\nElemento A[%d] [%d]=", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    maior = m[0][0];

    menor = m[0][0];

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < lin; j++)
        {

            if (m[i][j] > maior && j != 0)
            {

                maior = m[i][j];

                im = i;

                jm = j;
            }

            if (m[i][j] < menor && j != 0)
            {

                menor = m[i][j];

                in = i;

                jn = j;
            }
        }
    }

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < lin; j++)
        {

            b[i][j] = m[i][j] * maior;
        }
    }

    printf("\n\n  O maior valor registrado foi de A[%d][%d] = %d", im, jm, maior);
    printf("\n\n  O maior valor registrado foi de A[%d][%d] = %d", in, jn, menor);

    printf("\n\n");

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < lin; j++)
        {

            printf("\n\n B[%d] [%d]= %d", i, j, b[i][j]);
        }
    }

    printf("\n\n");

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < lin; j++)
        {

            if (m[i][j] % 2 == 0)
            {
                c[i][j] = 0;
            }
            else
            {
                c[i][j] = 1;
            }
        }
    }

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < lin; j++)
        {

            printf("\n\n C[%d] [%d]= %d", i, j, c[i][j]);
        }
    }

    printf("\n\n");

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < lin; j++)
        {

            printf("\n\nAxB[%d] [%d]= %d", i, j, m[i][j] * b[i][j]);
        }
    }

    printf("\n\n");

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < lin; j++)
        {

            printf("\n\nAxC[%d] [%d]= %d", i, j, m[i][j] * c[i][j]);
        }
    }

    printf("\n\n");

    for (i = 0; i < col; i++)
    {
        for (j = 0; j < lin; j++)
        {

            printf("\n\nCxB[%d] [%d]= %d", i, j, c[i][j] * b[i][j]);
        }
    }

    printf("\n\n");

    return 0;
}