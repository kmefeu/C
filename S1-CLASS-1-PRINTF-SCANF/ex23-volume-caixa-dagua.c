//Calcule o volume de uma caixa d'água cilíndrica.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    
    float pi, r, h, v;
    
    printf("Volume caixa dagua\n");
    
    printf("\nInsira o raio da caixa d'agua:");
    scanf("%f", &r);

    printf("\nInsira a altura da caixa d'agua:");
    scanf("%f", &h);

    pi = 3.1515;
    v = pi * (pow(r, 2)) * h;


    printf("\nO volume eh de :%0.2f metros cubicos\n", v);

    printf("\n\n");

    return 0;
}
