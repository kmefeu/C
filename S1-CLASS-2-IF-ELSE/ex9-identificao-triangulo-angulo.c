#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    system("cls");

    float n1, n2, n3;

    printf("\nAlgoritimo de identificacao de triangulos\n");

    printf("\n Digite a medida do primeiro angulo do triangulo:");
    scanf("%f", &n1);

    printf("\n Digite a medida do segundo angulo do triangulo:");
    scanf("%f", &n2);

    printf("\n Digite a medida do terceiro angulo do triangulo:");
    scanf("%f", &n3);

    if (n1 + n2 + n3 != 180)
    {
        printf("\n A soma dos lados de um triangulo precisam ser 180 \n\n");
    }

    else if (n1 > 90 || n2 > 90 || n3 > 90)
    {
        printf("\n Seu triangulo eh OBTUSANGULO \n\n");
    }

    else if (n1 < 90 && n2 < 90 && n3 < 90)
    {
        printf("\n Seu triangulo eh ACUTANGULO \n\n");
    }

    else if (n1 == 90 || n2 == 90 || n3 == 90)
    {
        printf("\n Seu triangulo eh RETANGULO \n\n");
    }

    else
    {
        printf("\nValor invalido!\n");
    }

    printf("\n\n");

    return 0;
}
