//Algoritomo de aptidao eleitoral

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    
    int n1, n2 = 2020, n3;

    printf("\n Escreva o ano de nascimento:");
    scanf("%i", &n1);

    n3 = n2 - n1;

    if (n3 >= 18)
    {
        printf("\nVoce deve votar na proxima eleicao obrigatoriamente\n\n", n1);
    }

    else if (n3 >= 16)
    {
        printf("\nSeu voto eh facultativo\n\n", n2);
    }
    else
    {
        printf("\nVoce ainda nao pode votar\n\n");
    }

    printf("\n\n");
    
    return 0;
}
