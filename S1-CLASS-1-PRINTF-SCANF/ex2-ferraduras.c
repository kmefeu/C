//Algoritimo de calculo do numero de ferraduras

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    int n1, n2;

    printf("Digite o numero de cavalos:");

    scanf("%i", &n1);

    n2 = (n1 * 4);

    printf("\n\no numero de ferraduras necessarias sao de: %i\n", n2);

    return 0;
}
