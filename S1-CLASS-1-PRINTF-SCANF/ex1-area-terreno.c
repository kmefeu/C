//Algoritimo de calculo da area de um terreno

#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");

    float n1, n2, n3;

    printf("Digite o valor de comprimento em metros:\n");

    scanf("%f", &n1);

    printf("Digite o valor de largura em metros:\n");

    scanf("%f", &n2);

    n3 = n1 * n2;

    printf("A area total do tereno eh de: %f\n", n3);

    return 0;
}
