//Leia um vetor de 16 posições e troque os 8 primeiros valores pelos 8 últimos e vice-e-versa. Escreva ao final o vetor obtido.

#include <stdio.h>
#include <string.h>

int main()
{

    system("cls");

    int v1[16], v2[16], i;

    for (i = 0; i < 16; i++)
    {

        printf("\n\n Elemento V1 [%d] = ", i);
        scanf("%d", &v1[i]);

        if (i < 8)
        {
            v2[8 + i] = v1[i];
        }

        else
        {
            v2[i - 8] = v1[i];
        }
    }

    for (i = 0; i < 16; i++)
    {

        printf("\n\n Elemento V2 [%d] = %d ", i, v2[i]);
    }

    printf("\n\n");
}