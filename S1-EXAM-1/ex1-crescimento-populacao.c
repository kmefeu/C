#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    system("cls");
    
    float populacao_Maior, populacao_Menor, taxa_Maior, taxa_Menor;

    int anos = 0, sair = 0;

    do
    {

        printf("\n\nAlgoritimo que calcula o numero de anos  para que a populacao de um pais MENOR (a) ultrapasse de um pais MAIOR (b).\n\n");

        printf("\n\nPor favor, siga as instrucoes a seguir.\n\n");

        printf("\n\nNumero de habitantes do pais (a) com a MENOR populacao:");
        scanf("%f", &populacao_Menor);

        printf("\n\nTaxa de crescimento do pais (a) com a MENOR populacao:");
        scanf("%f", &taxa_Menor);

        printf("\n\nNumero de habitantes do pais (b) com a MAIOR populacao:");
        scanf("%f", &populacao_Maior);

        printf("\n\nTaxa de crescimento do pais (b) com a MAIOR populacao:");
        scanf("%f", &taxa_Maior);

        if (populacao_Menor >= populacao_Maior || taxa_Menor <= taxa_Maior || populacao_Menor <= 0 || populacao_Maior <= 0 || taxa_Menor == 0)
        {
            printf("\n\n\t\t\t---VALORES INVALIDOS---");
            printf("\n\nPor favor verique os numeros inseridos!\n");
            printf("\nApenas a populacao MAIOR pode ter crescimento zero ou negativo.\n");
            printf("\nNenhuma populacao pode ser igual a zero.\n");
            printf("\nA populacao menor (a) nao pode ser inicialmente maior do que a populacao maior (b).\n");
            printf("\nA taxa de crescimento da populacao (a) nao pode ser maior do que a populacao maior (b).\n\n\n");
        }

        else
        {
            for (anos = 0; populacao_Maior >= populacao_Menor; anos++)
            {

                populacao_Maior = populacao_Maior * taxa_Maior + populacao_Maior;
                populacao_Menor = populacao_Menor * taxa_Menor + populacao_Menor;
            }

            printf(" \n\n Levaram %i anos para a populacao MENOR ultrapassar ou igualar a populacao MAIOR \n\n", anos);

            printf("\n\n Para sair digite 1 e para continuar digite 2:");
            scanf("%i", &sair);
            printf("\n\n");
        }

    } while (sair == 2);

    return 0;
}