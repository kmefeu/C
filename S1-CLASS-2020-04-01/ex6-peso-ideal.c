//Algoritimo de calculo de peso ideal!

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    float n1, n2, n3;

    printf("\n Digite o seu sexo 1:feminino 2:masculino:");
    scanf("%f", &n1);

    printf("\n Digite a sua altura em metros (use ponto nao virgula):");
    scanf("%f", &n2);

    if (n1 == 1)
    {

        n3 = (n2 * 62.1);
        printf("\n Seu peso ideal eh de:%0.2fKg\n\n", n3);
    }
    else if (n1 == 2)
    {

        n3 = (n2 * 72.7);
        printf("\nSeu peso ideal eh de de:%0.2fKg\n\n", n3);
    }
    else
    {
        printf("\nValor invalido!\n");
    }

    printf("\n\n");

    return 0;
}
