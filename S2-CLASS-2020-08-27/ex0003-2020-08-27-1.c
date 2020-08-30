

//Leia um vetor de 12 posições e em seguida ler também dois valores X e Y quaisquer correspondentes a duas posições no vetor. Ao final seu programa deverá escrever a soma dos valores encontrados nas respectivas posições X e Y.

#include <stdio.h>
#include <string.h>

int main()
{

    system("cls");

    int v[12], x, y, i, s = 0;

    for (i = 0; i < 12; i++)
    {

        printf("\n\n Elemento V[%d] = ", i);
        scanf("%d", &v[i]);
    }

    printf("\n\n Escolha um elemento X do vetor V [0 - 11] = ");
    scanf("%d", &x);

    printf("\n\n Escolha um elemento y do vetor V [0 - 11] = ");
    scanf("%d", &y);

    printf("\n\n X + Y = %d", s = v[x] + v[y]);

    printf("\n\n);
}