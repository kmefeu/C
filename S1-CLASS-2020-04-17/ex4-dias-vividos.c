//Algoritimo de calculo de dias ja vividos

#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");

    char n1[30];

    int n2, n3;

    printf("Digite o seu nome:");

    scanf("%s", &n1);

    printf("\n Digite a sua ideade:");

    scanf("%i", &n2);

    n3 = (n2 * 365);

    printf("\n %s! voce ja viveu %i dias\n\n", n1, n3);

    return 0;
}
