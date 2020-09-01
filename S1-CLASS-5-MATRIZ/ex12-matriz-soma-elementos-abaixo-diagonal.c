#include <stdio.h>

int main()
{

    system("cls");

    int m[3][3], i, j, s = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {

            printf("\n\nElemento m[%d] [%d]=", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {

            if (j < i)
            {
                s = s + m[i][j];
            }
        }
    }

    printf("\n\n A Soma dos elementos abaixo da diagonal principal eh: %d", s);

    printf("\n\n");

    return 0;
}