//Algoritimo de calculo de faturamento de vendas de camisetas

#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");

    int n1, n2, n3, n4;

    printf("Digite o numero de unidades P vendidas:");

    scanf("%i", &n1);

    printf("\nDigite o numero de unidades M vendidas:");

    scanf("%i", &n2);

    printf("\nDigite o numero de unidades G vendidas:");

    scanf("%i", &n3);

    n4 = (n1 * 10) + (n2 * 12) + (n3 * 15);

    printf("\nO valor total em reais faturado com a venda de camisetas foi de R$%i", n4);

    printf("\n\n");

    return 0;
}
