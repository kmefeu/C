//Pedrinho tem um cofrinho com muitas moedas, e deseja saber quantos reais conseguiu poupar. Faça um algoritmo para ler a quantidade de cada tipo de moeda, e imprimir o valor total economizado, em reais. Considere que existam moedas de 1, 5, 10, 25 e 50 centavos, e ainda moedas de 1 real. Não havendo moeda de um tipo, a quantidade respectiva é zero.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    float m1, m5, m10, m25, m50, r1, t;

    printf("Calculadora de cofrinho\n");

    printf("\nInsira o numero de moedas de 1 centavo:");
    scanf("%f", &m1);

    printf("\nInsira o numero de moedas de 5 centavo:");
    scanf("%f", &m5);

    printf("\nInsira o numero de moedas de 10 centavo:");
    scanf("%f", &m10);

    printf("\nInsira o numero de moedas de 25 centavo:");
    scanf("%f", &m25);

    printf("\nInsira o numero de moedas de 50 centavo:");
    scanf("%f", &m50);

    printf("\nInsira o numero de moedas de 1 real:");
    scanf("%f", &r1);

    t = ((m1 * 1) + (m5 * 5) + (m10 * 10) + (m25 * 25) + (m50 * 50) + (r1 * 100)) / 100;

    printf("\nVoce tem R$%0.2f\n\n", t);

    printf("\n\n");

    return 0;
}
