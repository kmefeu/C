//Leia um vetor de 40 posições e acumule os valores do primeiro elemento no segundo, deste no terceiro e assim por diante. Ao final, escreva o vetor obtido.

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

        if(i != 0 ){v[i] = v[i] + v[i-1];}
    }
    
    for (i = 0; i < 40; i++)
    {
        printf("\n\n Elemento V [%d] = %d", i, v[i]);
        
    }

    printf("\n\n");
}