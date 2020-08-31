#include <stdio.h>

int main()
{

    system("cls");

    int m[4][4], i, j, mi, mj, mv = 0;

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

            if (m[i][j] > mv)
            {

                mi = i;
                mj = j;
                mv = m[i][j];
            }
        }
    }

    printf("\n\nO elemento de maior valor da matriz  m[%d] [%d]= %d", mi, mj, m[mi][mj]);

    printf("\n\n");

    return 0;
}