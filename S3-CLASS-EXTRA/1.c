#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <string.h>

int main(void)
{

    int i = 0, j = 0, k = 0;
    int size = 0;
    char L;
    printf("Elementos conjunto");
    scanf("%d", &size);
    char vetor[size];
    char matriz[size][size];
    char auxiliar1;
    int a, b, c;

    //Inserindo os elementos do conjunto no vetor

    for (i = 0; i < size; i++)
    {
        printf("Insira o elemento");
        fflush(stdin);
        scanf("%c", &vetor[i]);
    }
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("%i %iinsira o valor de %c x %c", i, j, vetor[i], vetor[j]);
            fflush(stdin);
            scanf("%c", &matriz[i][j]);
            // printf("Valor: %c\n", vetor[0]);
        }
    }

    // imprime os indices das colunas
    printf("%4c |", ' ');
    for (i = 0; i < size; i++)
    {
        printf("%4c", vetor[i]);
    }
    printf("\n");

    for (i = 0; i < size; i++)
    {
        printf("%4c |", vetor[i]); // imprime os indices das linhas
        for (j = 0; j < size; j++)
        {
            printf("%4c", matriz[i][j]); // imprime o conteudo da tabela
            printf("\n");
        }

        for (a = 0; a < size; a++)
        {
            for (b = 0; b < size; b++)
            {
                for (c = 0; c < size; c++)
                {
                    if (matriz[a][b] == vetor[c])
                    {
                        for (int p = 0; p < size; p++)
                        {
                            printf("a=%c,b=%c,c=%c -> Lado A %c\n", vetor[a], vetor[b], vetor[c], matriz[c][p]);
                        }
                    }
                }

                // ate aqui coluna azul

                for (c = 0; c < size; c++)
                {
                    for (int teste = 0; teste < size; teste++)
                    {
                        if (matriz[b][c] == vetor[teste])
                        {
                            auxiliar1 = teste;
                        }
                    }

                    if (matriz[b][c] == vetor[j])
                    {
                        for (int p = 0; p < size; p++)
                        {
                            //printf("i=%c,j=%c,k=%c -> Correto %c\n", vetor[j], vetor[f], vetor[p], matriz[k][p]);
                        }
                    }
                }
            }
        }
    }
