// A granja Frangotech possui um controle automatizado de cada frango da sua produção. No pé direito do frango há um anel com um chip de identificação; no pé esquerdo são dois anéis para indicar o tipo de alimento que ele deve consumir. Sabendo que o anel com chip custa R$4,00 e o anel de alimento custa R$3,50. faça um algoritmo para calcular o gasto total da granja para marcar todos os seus frangos.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    int f, r;

    printf("Custo chip granja\n");

    printf("\nInsira o numero de frangos: ");
    scanf("%i", &f);

    r = (f * 7) + (f * 4);

    printf("\nO valor a ser gasto eh de R$ %i,00 reais \n\n", r);

    printf("\n\n");

    return 0;
}
