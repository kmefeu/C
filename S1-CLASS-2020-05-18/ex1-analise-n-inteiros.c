#include <stdio.h>
#include <string.h>
#include <locale.h>
#define total_n 8

int main()
{

    system("cls");

    setlocale(LC_ALL, "portuguese");

    int ind, total_v = 0, numero[total_n], par[total_n] = {0}, impar[total_n] = {0}, maior = 0, menor = 0, conte_impar = 0, conte_par = 0;
    float pct_impar, media;

    printf("\n\nAlgoritimo de análise de %i números inteiros\n\n", total_n);

    for (ind = 0; ind < total_n; ind++)

    {

        printf("N%i:", ind);
        scanf("%i", &numero[ind]);
    }

    maior = numero[0];
    menor = numero[0];

    for (ind = 0; ind < total_n; ind++)

    {

        if (numero[ind] % 2 != 0)
        {
            conte_impar = conte_impar + 1;
            impar[ind] = numero[ind];
        }
        else
        {
            conte_par = conte_par + 1;
            par[ind] = numero[ind];
        }

        if (ind > 0 && numero[ind] > numero[ind - 1])
        {
            maior = numero[ind];
        }
        if (ind > 0 && numero[ind] < numero[ind - 1])
        {
            menor = numero[ind];
        }

        total_v = total_v + numero[ind];
    }

    media = (float)total_v / (float)total_n;

    pct_impar = ((float)conte_impar / (float)total_n) * 100;

    printf("\n\nTotal de números pares:%i", conte_par);

    printf("\n\nNúmeros pares:");
    for (ind = 0; ind < total_n; ind++)
    {
        if (par[ind] != 0)
        {
            printf("%i ", par[ind]);
        }
    }

    printf("\n\nTotal de números impares:%i", conte_impar);

    printf("\n\nNúmeros impares:");
    for (ind = 0; ind < total_n; ind++)
    {
        if (impar[ind] != 0)
        {
            printf("%i ", impar[ind]);
        }
    }

    printf("\n\nMaior número:%i", maior);
    printf("\n\nMenor número:%i", menor);
    printf("\n\nMédia da somatoria dos números:%0.2f", media);
    printf("\n\nTotal de números impares:%0.2f%%", pct_impar);

    printf("\n\n");

    return 0;
}