//Cofre dos segredos milhonarios

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    int n1 = 1234, n2;

    printf("SENHA:");
    scanf("%i", &n2);

    if (n1 == n2)
    {

        printf("\nACESSO PERMITIDO!\n\nO segredo dos milhonarios eh o trabalho\n\n");
    }
    else
    {
        printf("\nACESSO NEGADO!\n\n");
    }

    printf("\n\n");

    return 0;
}
