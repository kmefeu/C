//Algoritimo de calculo de dias que ja passaram em determinado ano

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    int n1;

    int n2;

    int n3;

    printf("Digite o numero correspondente ao mes atual:");

    scanf("%i", &n1);

    printf("\nDigite o numero correspondente de dias do mes atual:");

    scanf("%i", &n2);

    n3 = ((n1 - 1) * 30) + n2;

    printf("\n Ja se passaram %i dias esse ano.", n3);

    printf("\n\n");

    return 0;
}
