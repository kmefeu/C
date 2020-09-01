#include <stdio.h>

int main()
{

    system("cls");

    int m[3][3], i, j, v = 1;

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

            if (i == j && m[i][j] != 1)
            {
                v = 0;
            }
            else if (i != j && m[i][j] != 0)
            {
                v = 0;
            }
        }
    }

    if (v == 0)
    {
        printf("\n\n!---Nao eh matriz indentidade---!");
    }
    if (v == 1)
    {
        printf("\n\n!---Matriz indentidade---!");
    }

    printf("\n\n");

    return 0;
}
