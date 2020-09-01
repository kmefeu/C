//Faça um algoritmo que receba três números, calcule e mostre a multiplicação desses números.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    
    int n1, n2, n3, multiplicador;

    printf("Multiplicacao\n");
    
    printf("\nInsira o primeiro numero:");
    scanf("%i", &n1);

    printf("\nInsira o primeiro multiplicador:");
    scanf("%i", &n2);

    printf("\nInsira o segundo multiplicador:");
    scanf("%i", &n3);

    multiplicador = n1 * n2 * n3;

    printf("\nA multiplicacao eh:%i\n", multiplicador);

    printf("\n\n");

    return 0;
}
