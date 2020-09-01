//Algoritimo de calculo da area de poligonos regulares!

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float n1, n2, n3, n4;

    system("cls");
    
    printf("\n Digite o numero de lados do poligono regular{3,4,5}:");
    scanf("%f", &n1);

    printf("\n Digite a medida do lado do poligono em CM (use ponto nao virgula):");
    scanf("%f", &n2);

    if (n1 == 3)
    {
        n3 = ((n2 * n2) * sqrt(3) / 4);
        printf("\n A area do triangulo eh:%0.2f cm2\n\n", n3);
    }

    else if (n1 == 4)
    {
        n3 = (n2 * n2);
        printf("\n A area do quadrado eh:%0.2f cm2\n\n", n3);
    }

     else if (n1 == 5)
    {
        n3 = ((n2 * n2) * sqrt(3) / 4 * 5);
        printf("\n A area do pentagono eh:%0.2f cm2\n\n", n3);
    }

    else
    {
        printf("\nValor invalido!\n");
    }

    printf("\n\n");
    
    return 0;
}
