//Algoritimo de calculo de imposto sobre salario

#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");

    float n1, n2, n3;

    printf("Insira seu salario atual:");

    scanf("%f", &n1);

    n2 = (n1 * 0.15) + n1;

    n3 = (n2 * 0.92);

    printf("\n O valor do seu salrio com o aumento de 15pct eh de: %f \n\n O valor do seu salrio com aumento menos impostos eh %0.2f)\n", n2, n3);

    printf("\n\n");

    return 0;
}
