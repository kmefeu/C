#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    float Q, G;

    printf("Kg:\n");
    scanf("%f", &Q);

    G = Q * 1000;

    printf("g:%0.2f", G);

    printf("\n\n");

    return 0;
}
