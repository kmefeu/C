//Matheus Corrêa 202010270 ENG COMP

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char car;
    int peso;
} Cell;

void iniVet(Cell *vet, int elementos);
void Contar(Cell *vet, int elementos);

int main()
{
    int elementos;
    Cell *vet;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &elementos);
    printf("\n");

    vet = malloc(elementos * sizeof(double));
    setbuf(stdin, NULL);

    int i = 0, j = 0;

    for (i = 0; i < elementos; i++)
    {

        printf("\n\n");

        printf("Caractere:");
        scanf("%c", &vet[i].car);

        setbuf(stdin, NULL);

        printf("Peso:");
        scanf("%i", &vet[i].peso);

        setbuf(stdin, NULL);
    }

    printf("\n\n");

    Contar(vet, elementos);

    return 0;
}

void Contar(Cell *vet, int elementos)
{
    int i, l, soma = 0, menos = 0, total = 0;

    for (i = 0; i < elementos; i++)
    {
        soma = vet[i].peso + soma;
    }

    for (i = 0; i < elementos; i++)
    {
        if (i == 0)
        {
            if (vet[i].car != vet[i + 1].car)
            {
                menos += vet[i].peso;
            }
            continue;
        }
        if (vet[i].car != vet[i + 1].car && vet[i].car != vet[i - 1].car)
        {
            menos += vet[i].peso;
        }
    }

    total = soma - menos;
    printf("\nTotal = %d", total);
}