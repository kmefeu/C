//Algoritomo de identificacao do maior numero

#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");

    float n1, n2;

    printf("\nEscreva o primeiro valor:");
    scanf("%f", &n1);

    printf("\nEscreva o segundo valor:");
    scanf("%f", &n2);

    if (n1 > n2)
    {
        printf("\n O maior valor eh %0.2f\n\n", n1);
    }

    else if (n1 < n2)
    {
        printf("\n O maior valor eh %0.2f\n\n", n2);
    }

    else
    {
        printf("\nValores invalidos!\n\n");
    }

    printf("\n\n");

    return 0;
}
