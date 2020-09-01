//Leia um vetor de 40 posições e atribua valor 0 para todos os elementos que possuírem valores negativos.

#include <stdio.h>
#include <string.h>

int main()
{

    system("cls");

    int v[40], i;

    for (i = 0; i < 40; i++)
    {

        printf("\n\n Elemento V [%d] = ", i);
        scanf("%d", &v[i]);

        if (v[i] < 0){v[i] = 0;}
    }

    for (i = 0; i < 40; i++)
    {

        printf("\n\n Elemento V [%d] = %d ", i, v[i]);
    }

    printf("\n\n");
}