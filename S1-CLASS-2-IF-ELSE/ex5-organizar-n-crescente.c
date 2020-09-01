//Algoritimo organizador de 3 numeros em ordem crescente

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    
    int n1, n2, n3;

    printf("\nEscreva o primeiro numero:");
    scanf("%i", &n1);

    printf("\nEscreva o segundo numero:");
    scanf("%i", &n2);

    printf("\nEscreva o terceiro numero:");
    scanf("%i", &n3);

    if (n1 == n2 || n2 == n3)
    {
        printf("\n Dois valores ou mais sao iguais! \n\n");
    }

    else
    {
        printf("\nOs valores digitados foram %i,%i e %i.\n\nE esses sao os valores em ordem crescente:", n1, n2, n3);

        if (n1 < n2 && n2 < n3)
        {
            printf("%i,%i e %i\n", n1, n2, n3);
        }
        if (n1 < n3 && n3 < n2)
        {
            printf("%i,%i e %i\n", n1, n3, n2);
        }
        if (n2 < n1 && n1 < n3)
        {
            printf("%i,%i e %i\n", n2, n1, n3);
        }
        if (n2 < n3 && n3 < n1)
        {
            printf("%i,%i e %i\n", n2, n3, n1);
        }
        if (n3 < n1 && n1 < n2)
        {
            printf("%i,%i e %i\n", n3, n1, n2);
        }
        if (n3 < n2 && n2 < n1)
        {
            printf("%i,%i e %i\n", n3, n2, n1);
        }
    }

    printf("\n\n");

    return 0;
}
