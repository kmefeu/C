#include <stdio.h>

int main()
{

    system("cls");

    int m[10][10], i, j;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {

            if (i < j)
            {
                m[i][j] = (2 * i) + ((7 * j) - 2);
            }
            if (j == i)
            {
                m[i][j] = ((3 * (i * i)) - 1);
            }
            if (i > j)
            {
                m[i][j] = (4 * (i * i * i)) - ((5 * (j * j)) + 1);
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {

            printf("\n\nElemento m[%d] [%d]=%d", i, j, m[i][j]);
        }
    }

    return 0;
}