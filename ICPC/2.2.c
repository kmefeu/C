#include <stdio.h>

void main()
{
    int mapa[10][10];
    int N, D, L, R, C, flag = 0;

    for (int r = 0; r < 10; r++)

    {
        for (int j = 0; j < 10; j++)
        {
            mapa[r][j] = 0;
        }
    }

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d %d", &D, &L, &R, &C);
        if (D == 1)
        {
            for (int j = 0; j < L; j++)
            {
                if (C + j > 10)
                {
                    flag = 1;
                }
                else
                {
                    printf("%d \n", mapa[R][C+j]);
                    mapa[R][C + j] = mapa[R][C + j] + 1;
                }
            }
        }
        else
        {
            for (int j = 0; j < L; j++)
            {
                if (R + j > 10)
                {
                    flag = 1;
                }
                else
                {
                    printf("%d\n", mapa[R + j][C]);
                    mapa[R + j][C] = mapa[R + j][C] + 1;
                }
            }
        }
    }

    for (int r = 0; r < 10; r++)

    {
        printf("\n");
        for (int j = 0; j < 10; j++)
        {
            printf("\n");
            printf("%d", mapa[r][j]);

            if (mapa[r][j] > 1)
            {
                flag = 1;
            }
        }
    }
    printf("%d", flag);
    if (flag == 0)
    {
        printf("Y");
    }
    else
    {
        printf("N");
    }

    return 0;
}