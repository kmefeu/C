#include <stdio.h>
#include <stdlib.h>

maior_valor(int n1, int n2)
{

    int maior;

    if (n1 > n2)
    {
        maior = n1;
    }
    else
    {
        maior = n2;
    }

    return maior;
}

int main()
{

    system("cls");
    
    int n1, n2, maior;

    printf("\n\nInsira um numero:");
    scanf("%f", &n1);

    printf("\n\nInsira um numero:");
    scanf("%f", &n2);

    maior = maior_valor(n1, n2);

    printf("\n\nO Maior valor foi de %i", maior);

    return 0;
}