//Uma confecção produz X blusas de lã e para isto gasta uma certa quantidade de novelos.Faça um algoritmo para calcular quantos novelos de lã ela gasta por blusa.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    
    float b, n, q;
    
    printf("Novelos por blusa\n");
    
    printf("\nInsira o numero de blusas:");
    scanf("%f", &b);

    printf("\nInsira a quantidade de novelos:");
    scanf("%f", &n);
    
    q = n / b;

    printf("\nForam gastos %0.1f novelos por blusa \n\n", q);

    printf("\n\n");

    return 0;
}
