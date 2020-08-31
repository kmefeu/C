#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    system("cls");

    int cont, cont_maxima, n_cont;

    float temp, media_temp = 0, maior_temp = -273.16, menor_temp = 99999999, total_temp;

    printf("\n\nBem vindo ao programa do departamento estadual de meteorologia!\n\n");

    printf("\n\nPor favor digite o numero de quantas temperaturas voce deseja calcular a media:");
    scanf("%i", &cont_maxima);

    printf("\n\n Por favor coloque os valores em celcios!\n\n");

    for (cont = 0; cont < cont_maxima; cont++)
    {
        n_cont = cont + 1;

        printf("\n\nPor favor insira a %i temperatura:", n_cont);
        scanf("%f", &temp);

        if (temp < menor_temp)
        {
            menor_temp = temp;
        }

        if (temp > maior_temp)
        {
            maior_temp = temp;
        }

        total_temp = total_temp + temp;
    }

    media_temp = total_temp / cont;

    printf("\n\nA media das temperatura eh de:%0.2f C", media_temp);

    printf("\n\nA maior temperatura eh de:%0.2f C", maior_temp);

    printf("\n\nA menor temperatura eh de:%0.2f C", menor_temp);

    printf("\n\nOBS: O valor maximo para a menor temperatura eh de  9.999.998 C");

    printf("\n\nOBS: O valor minimo para a maior temperatura eh de  -273.15 C");

    printf("\n\n");

    return 0;
}