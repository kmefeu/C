#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    system("cls");
    
    float conta(int N)
    {
        int I = 1;
        float E = 1;
        for (I = 1; I <= N; I++)
        {
            E = E + 1 / E;
        }
        return E;
    }

    int n;

    float e;

    printf("\n\n\n Algoritimo que le um numero N inteiro e escreve o valor de E.\n Sendo E = 1/1 + 1/2 + 1/3 + 1/N ...\n\n");

    printf("Porfavor digite o valor de N:");
    scanf("%i", &n);

    e = conta(n);

    printf("\n\nE =%0.2f", e);

    printf("\n\n");

    return 0;
}