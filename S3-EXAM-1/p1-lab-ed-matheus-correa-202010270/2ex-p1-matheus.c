//Matheus Corrêa 202010270 ENG COMP

#include <stdio.h>
#include <stdlib.h>

double Media(double vetor[], int n, int *i)
{
    int f;
    double media = 0, maisPerto = 0;

    for (f = 0; f < n; f++)
    {
        printf("Escreva o Elemento:");
        scanf("%lf", &vetor[f]);
    }

    for (f = 0; f < n; f++)
    {
        media += vetor[f];
    }

    media = media / n;

    for (f = 0; f < n; f++)
    {
        if (media - vetor[f] < maisPerto && media - vetor[f] >= 0 || f == 0)
        {
            maisPerto = media - vetor[f];
            *i = f;
        }
    }

    return media;
}

int main()
{
    int tamanho, posicao;
    double result, *vetor;

    printf("Escreva o Tamanho do Vetor:");
    scanf("%d", &tamanho);

    vetor = malloc(tamanho * sizeof(double));
    result = Media(vetor, tamanho, &posicao);

    printf("\n\n");
    printf("A media dos valores eh %0.2lf\n", result);
    printf("A posicao do numero mais proximo a media e %d\n", posicao);
    printf("\n\n");

    system("pause");
}