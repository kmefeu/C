//Algoritimo que le 5 valores e identifica o numero de valores negativos

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    system("cls");

    int cont, cont_neg = 0;
    float v1;

    for (cont = 0; cont < 5; cont++)
    {
        printf("\n\nPor favor insira um numero real: ");
        scanf("%f", &v1);

        if (v1 < 0)
        {
            cont_neg = cont_neg + 1;
        }
    }

    printf("\n\n O total de numeros negativos digitados foi de  %i", cont_neg);

    printf("\n\n");

    return 0;
}