//Algoritimo de calculo de litros abastecidos

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    float n1;

    float n2;

    float n3;

    printf("Digite o valor do litro da gasolina:");

    scanf("%f", &n1);

    printf("\nDigite o valor total pago para abastecer:");

    scanf("%f", &n2);

    n3 = (n2 / n1);

    printf("\nVoce abasteceu %0.2f litros\n", n3);

    return 0;
}
