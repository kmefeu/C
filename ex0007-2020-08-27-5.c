//Leia um vetor de 40 posições. Contar e escrever quantos valores pares ele possui.

#include <stdio.h>
#include <string.h>

int main()
{

    system("cls");

    int v[40], p, i;

    for (i = 0; i < 40; i++)
    {

        printf("\n\n Elemento V [%d] = ", i);
        scanf("%d", &v[i]);

        if(v[i]%2 == 0){ p = p + 1;}

    }

    printf("\n\nO Total de %d valores pares foram encontrados no vetor",p);
    

    printf("\n\n");
}