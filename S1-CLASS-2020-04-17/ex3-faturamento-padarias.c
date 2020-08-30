//Algoritimo de calculo de faturamento e tributos para padarias

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    float n1, n2, n3, n4;

    printf("Digite o numero de paes vendidos:");

    scanf("%f", &n1);

    printf("\nDigite o numero de paes broas vendidas:");

    scanf("%f", &n2);

    n3 = ((n1 * 0.12) + (n2 * 1.5));

    n4 = (n3 * 0.1);

    printf("\nO faturamento total foi de: %0.2f\n", n3);

    printf("\nO total de imposto recolhido deve ser de: %0.2f\n", n4);

    return 0;
}