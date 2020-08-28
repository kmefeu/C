//Leia um vetor de 20 posições e em seguida um valor X qualquer. Seu programa devera fazer uma busca do valor de X no vetor lido e informar a posição em que foi encontrado ou se não foi encontrado.

#include <stdio.h>
#include <string.h>

int main()
{

    system("cls");

    int v[20], x, i;

    for (i = 0; i < 20; i++)
    {

        printf("\n\n Elemento V [%d] = ", i);
        scanf("%d", &v[i]);
    }

    printf("\n\n Digite o valor que voce deseja encontrar no vetor:");
    scanf("%d", &x);

    for (i = 0; i < 20; i++)
    {

        if (v[i] == x)
        {
            printf("\n\nValor encontrado na posicao V [%d]", i);
        }
        else if (i == strlen(v))
        {
            printf("\n\nValor nao encontrado");
        }
    }

    printf("\n\n");
}