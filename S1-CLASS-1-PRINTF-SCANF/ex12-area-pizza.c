// Algoritimo de calculo de area de uma pizza redonda

#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");

    float n1, n2;

    printf("Insira a medida do raio da pizza:");

    scanf("%f", &n1);

    n2 = (n1 * n1) * 3.14;

    printf("\n A area da pizza eh %0.2f\n", n2);

    printf("\n\n");

    return 0;
}
