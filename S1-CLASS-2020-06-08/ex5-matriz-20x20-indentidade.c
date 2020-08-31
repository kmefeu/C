#include <stdio.h>

int main()
{

    system("cls");

    int m[20][20], i, j;

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {

            if (i == j)
            {
                m[i][j] = 1;
            }
            else
            {
                m[i][j] = 0;
            }
        }
    }

    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {

            printf("\n\nElemento m[%d] [%d]= %d", i, j, m[i][j]);
        }
    }

    printf("\n\n");

    return 0;
}