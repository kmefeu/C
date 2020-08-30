//Algoritimo de calculo de media escolar

#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");

    int n1,n2,n3,n4;

    printf("Digite a nota da P1:");

    scanf("%i", &n1);

    printf("\nDigite a nota da P2:");

    scanf("%i", &n2);

    printf("\nDigite a nota da P3:");

    scanf("%i", &n3);

    n4 = (n1 + (2 * n2) + (3 * n3)) / 6;

    printf("\nSua media final foi de: %i\n", n4);

    printf("\n\n");

    return 0;
}
