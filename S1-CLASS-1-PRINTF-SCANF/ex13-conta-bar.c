//Três amigos, Carlos, André e Felipe. decidiram rachar igualmente a conta de um bar. Faça um algoritmo para ler o valor total da conta e imprimir quanto cada um deve pagar, mas faça com que Carlos e André não paguem centavos. Ex: uma conta de R$101,53 resulta em R$33,00 para Carlos R$33,00 para André e R$35,53 para Felipe.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    system("cls");

    int c, a;
    float f, t;

    printf("Divisao de conta\n");

    printf("\nInsira valor da conta:");
    scanf("%f", &t);

    c = t / 3;
    a = t / 3;
    f = t - (c + a);

    printf("\nCarlos e Andre jah pagaram %i.00 e Felipe pagara:%0.2f\n", a, f);

    printf("\n\n");

    return 0;
}
