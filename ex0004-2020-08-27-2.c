//Declare um vetor de 10 posições e o preencha com os 10 primeiros números impares e o escreva.

#include <stdio.h>
#include <string.h>

int main()
{

    system("cls");

    int v[10], i;

    for (i = 0; i < 20; i++)
    {

        if (i % 2 != 0)
        {
            v[i] = i;

            printf("\n\n Elemento V [%d] = %d ", i, v[i]);
        }
    }

    printf("\n\n");
}