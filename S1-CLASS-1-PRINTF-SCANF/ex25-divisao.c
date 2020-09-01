//Faça um algoritmo que receba dois números, calcule e mostre a divisão do primeiro número pelo segundo. Sabe-se que o segundo número não pode ser zero, portanto não é necessário se preocupar com validações.


#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    
    int n1, n2, r;

    printf("Divisao\n");
    
    printf("\nInsira o dividendo:");
    scanf("%i", &n1);

    printf("\nInsira o divisor:");
    scanf("%i", &n2);

    r = n1 / n2;

    printf("\no valor da divisao eh:%i\n", r);

    printf("\n\n");

    return 0;
}
