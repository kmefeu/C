// Um tonel de refresco é feito com 8 partes de água mineral e 2 partes de suco de maracujá. Faça um algoritmo para calcular quantos litros de água e de suco são necessários para se fazer X litros de refresco (informados pelo usuário).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    system("cls");

    float a, s, r;
    
    printf("Tonel de refresco\n");
    
    printf("\nInsira a quantidade de refresco desejada:");
    scanf("%f", &r);

    a = r * 0.8;
    s = r * 0.2;

    printf("\nvoce vai precisar de %0.2f litros de agua e %0.2f litros de suco \n\n", a, s);

    printf("\n\n");

    return 0;
}
