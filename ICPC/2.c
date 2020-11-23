#include <stdio.h>
#include <string.h>

struct barco
{
    int x, y, l, d;

    int cord[10] = [0,0,0,0,0,0,0,0,0,0];

} barcos[100];

int main()
{
    int n, ny = 0, nx = 0;
    system("cls");

    printf("N Barcos:");
    scanf("%d", &n);

    if (n <= 100 && n >= 1)
    {

        for (int i = 0; i < n; i++)
        {
            printf("X Y L D:");
            scanf("%d %d %d %d", &barcos[i].x, &barcos[i].y, &barcos[i].l, &barcos[i].d);

            for (int j = 0; j < barcos[i].l; j++)
            {
                if (barcos[i].d == 1)
                {
                    for (int k = 0; k < 10; k++)
                    {

                        if (k % 2 == 0)
                        {
                            barcos[i].cord[k] = barcos[i].x;
                        }
                        else
                        {

                            barcos[i].cord[k] = barcos[i].y + ny;
                            ny = ny + 1;
                        }

                        printf("%d",barcos[i].cord[k]);
                    }

                    ny = 0;
                }
                else
                {
                    for (int k = 0; k < 10; k++)
                    {

                        if (k % 2 == 0)
                        {
                            barcos[i].cord[k] = barcos[i].x + nx;
                            nx = nx + 1;
                        }
                        else
                        {
                            barcos[i].cord[k] = barcos[i].y;
                        }
                        printf("%d",barcos[i].cord[k]);
                    }
                    nx = 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int k; k < n; k++)
        {
            printf("%d",barcos[i].cord[k]);
        }
    }

    printf("\n\n");

    return 0;
}