//A fábrica de refrigerantes Meia-Cola vende seu produto em três formatos: lata de 350 ml, garrafa de 600 ml e garrafa de 2 litros. Se um comerciante compra uma determinada quantidade de cada formato faça um algoritmo para calcular quantos litros de refrigerante ele comprou.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    float lt, g6, g2, t;

    printf("Litros de bebida\n");

    printf("\nInsira o numero de latas:");
    scanf("%f", &lt);

    printf("\nInsira o numero de garrafas de 600ml:");
    scanf("%f", &g6);

    printf("\nInsira o numero de garrafas de 2 litros:");
    scanf("%f", &g2);

    t = ((350 * lt) + (600 * g6) + (2000 * g2)) / 1000;

    printf("\nForam comprados %0.2f litros de bebida\n", t);

    printf("\n\n");

    return 0;
}
