//Algoritimo que le varios numeros reais positivos e calcula a media aritimetica.

#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");
    
    float valor, total = 0, media;

    int n, contagem = 0;

    printf("\n\nPara Quantos numeros voce quer calcular a media:");
    scanf("%i", &n);

    for (contagem = 0; contagem < n; contagem++)
    {

        printf("\n\nPor favor digite o %i valor:", contagem);
        scanf("%f", &valor);

        total = total + valor;
    }

    media = total / n;

    printf("\n\n O valor da media aritimetica para os %i numeros digitados eh:%0.2f\n\n", n, media);

    return 0;
}