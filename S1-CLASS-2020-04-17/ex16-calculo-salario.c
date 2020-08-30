//A empresa Hipotheticus paga R$10,00 por hora normal trabalhada, e R$15,00 por hora extra. Faça um algoritmo para calcular e imprimir o salário bruto e o salário líquido de um determinado funcionário. Considere que o salário líquido é igual ao salário bruto descontando-se 10% de impostos.

#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");

    float hn, he, sb, sl;

    printf("Calculadora de salario\n");

    printf("\nInsira o numero de horas normais:");
    scanf("%f", &hn);

    printf("\nInsira o numero de horas extra:");
    scanf("%f", &he);

    sb = (hn * 10) + (he * 15);
    sl = (sb * 0.9);

    printf("\nSeu salario bruto eh de %0.2f e seu salario liquido eh de %0.2f\n", sb, sl);

    printf("\n\n");

    return 0;
}
