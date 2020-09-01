#include <stdio.h>

int main()
{

    system("cls");

    int m[4][4], i, j, mi, mj, mv = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            m[i][j] = i * j;
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            printf("\n\nElemento m[%d] [%d]=%d", i, j, m[i][j]);
        }
    }

    printf("\n\n");
    
    return 0;
}