#include <stdio.h>

int main()
{
    system("cls");
    
    float n1, n2, n3, n4;

    printf("\nAlgoritimo de identificacao de triangulos\n");

    printf("\n Digite a medida do primeiro lado do triangulo:");
    scanf("%f", &n1);

    printf("\n Digite a medida do segundo lado do triangulo:");
    scanf("%f", &n2);

    printf("\n Digite a medida do terceiro lado do triangulo:");
    scanf("%f", &n3);

    if (n1 != n2 && n2 != n3)
    {
        printf("\n Seu triangulo eh ESCALENO pois tem tres lados diferentes\n\n");
    }

    else if (n1 == n2 && n2 == n3)
    {
        printf("\n Seu triangulo eh EQUILATERO pois tem tres lados iguais\n\n");
    }

    else if (n1 == n2 || n2 == n3 || n3 == n1)
    {
        printf("\n Seu triangulo eh ISOCELES pois tem apenas um lado diferente\n\n");
    }

    else
    {
        printf("\nValor invalido!\n");
    }

    printf("\n\n");

    return 0;
}
