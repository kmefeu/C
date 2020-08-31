#include <stdio.h>

int main()
{

    system("cls");

    int m1[4][4], m2[4][4], mr[4][4], i, j;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            printf("\n\nElemento m1[%d] [%d]=", i, j);
            scanf("%d", &m1[i][j]);
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            printf("\n\nElemento m2[%d] [%d]=", i, j);
            scanf("%d", &m2[i][j]);
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            if (m1[i][j] < m2[i][j])
            {
                mr[i][j] = m2[i][j];
            }
            else
            {
                mr[i][j] = m1[i][j];
            }
        }
    }
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {

            printf("\n\nElemento mr[%d] [%d]=%d", i, j, mr[i][j]);
        }
    }

    return 0;
}