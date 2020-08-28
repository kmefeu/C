//Leia uma matriz 3x3 e faça a soma de todos os elementos

#include <stdio.h>

int main()
{

    system("cls");

    int m[3][3], i, j, s = 0;

    for (i = 0; i < 3; i++)
    {

        for (j = 0; j < 3; j++)
        {

            printf("\n\n Elemento m[%d][%d] = ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {

        for (j = 0; j < 3; j++)
        {

            s = s + m[i][j];
        }
    }

    printf("A soma da matriz eh %d", s);
}