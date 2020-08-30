//Alguns países medem temperaturas em graus Celsius, e outros em graus Fahrenheit. Faça um algoritmo para ler uma temperatura Celsius e imprimi-Ia em Fahrenheit (pesquise como fazer este tipo de conversão).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    float c, f;

    printf("Conversor de temperatura celsius/fahrenheit\n");

    printf("\nInsira a temperatura em celsius:");
    scanf("%f", &c);

    f = (c * 1.8) + 32;

    printf("A temperatura em fahrenheit eh de: %0.2f graus\n\n", f);

    printf("\n\n");

    return 0;
}
