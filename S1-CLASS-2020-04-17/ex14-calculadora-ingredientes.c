//A lanchonete Gostosura vende apenas um tipo de sanduíche, cujo recheio inclui duas fatias de queijo, uma fatia de presunto e uma rodela de hambúrguer. Sabendo que cada fatia de queijo ou presunto pesa 50 gramas, e que a rodela de hambúrguer pesa 100 gramas, faça um algoritmo em que o dono forneça a quantidade de sanduíches a fazer, e a máquina informe as quantidades (em quilos) de queijo, presunto e carne necessários para compra.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    float h, q, p, s;

    printf("Calculadora de ingredientes\n");

    printf("\nInsira a quantidade de sanduiches:");
    scanf("%f", &s);

    q = (100 * s) / 1000;
    p = (50 * s) / 1000;
    h = (100 * s) / 1000;

    printf("\nA voce devera comprar:%0.2fkg de presunto,%0.2fkg de queijo e %0.2fkg de hamburguer\n", p, q, h);

    printf("\n\n");

    return 0;
}
