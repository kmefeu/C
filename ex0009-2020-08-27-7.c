//Leia dos vetores de 20 posições e calcule um outro vetor contendo, nas posições pares os valores do primeiro e nas posições impares os valores do segundo.

#include <stdio.h>
#include <string.h>

int main()
{

    system("cls");

    int v[40], v1[20], v2[20], i, i1 = 0, i2 = 0;

    for (i = 0; i < 20; i++)
    {
        printf("\n\n Elemento V1 [%d] = ", i);
        scanf("%d", &v1[i]);
    }

    
    for (i = 0; i < 20; i++)
    {
        printf("\n\n Elemento V2 [%d] = ", i);
        scanf("%d", &v2[i]);
    }

    for (i = 0; i < 40; i++)
    {
        
        
        if (i % 2 == 0)
        {
            v[i] = v1[i1];

            i1 = i1 + 1;
        }
        else
        {
            v[i] = v2[i2];

            i2 = i2 + 1;
        }
    }
    for (i = 0; i < 40; i++)
    {

        printf("\n\n Elemento V [%d] = %d ", i, v[i]);
    }
    printf("\n\n");
}