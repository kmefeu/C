//Algoritimo de calculo do valor da compra de Macas

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    
    float n1, n2;

    printf("\nEscreva o numero de macas compradas:");
    scanf("%f", &n1);

    if (n1 < 12 && n1 > 0)
    {

        n2 = (n1 * 0.3);
        printf("\nO valor total da sua compra foi de: R$%0.2f\n\n", n2);
    }
    else if (n1 > 12)
    {

        n2 = (n1 * 0.25);
        printf("\nO valor total da sua compra foi de: R$%0.2f\n\n", n2);
    }
    else
    {
        printf("\nValor invalido!\n");
    }

    printf("\n\n");

    return 0;
}
