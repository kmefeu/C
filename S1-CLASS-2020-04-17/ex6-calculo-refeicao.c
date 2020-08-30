//Algoritimo de calculo de self-servise

#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");

    float n1;

    float n2;

    printf("Digite o valor em gramas da sua refeicao:");

    scanf("%f", &n1);

    n2 = (n1 * 0.012);

    printf("\nVoce deve pagar %0.2f pos sua refeicao", n2);

    printf("\n\n");

    return 0;
}
