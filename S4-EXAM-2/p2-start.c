/**************************************************************************************
*** Programa que calcula o determinante de uma matriz, recebendo-a atraves de arquivo
*** Código produzido por José Luís Zem
**************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int matriz[20], indice = 0, diagonais_principais = 0, diagonais_secundarias = 0, determinante = 0;
    FILE *arquivo;

    system("clear");

    arquivo = fopen("matriz.txt", "r");

    if (arquivo == NULL)
    {

        printf("------------------------------------------------------------------\n");
        printf("Nao foi possivel abrir o arquivo matriz.txt\n");
        printf("------------------------------------------------------------------\n");
    }
    else
    {

        fscanf(arquivo, "%d %d %d %d %d %d %d %d %d", &matriz[1], &matriz[2], &matriz[3], &matriz[4], &matriz[5], &matriz[6], &matriz[7], &matriz[8], &matriz[9]);
        fclose(arquivo);

        // Na versão paralela, essa parte deverá ser executada pelo Filho 1.
        diagonais_principais = (matriz[1] * matriz[5] * matriz[9]) + (matriz[2] * matriz[6] * matriz[7]) + (matriz[3] * matriz[4] * matriz[8]);

        // Na versão paralela, essa parte deverá ser executada pelo Filho 2.
        diagonais_secundarias = -(matriz[3] * matriz[5] * matriz[7]) - (matriz[1] * matriz[6] * matriz[8]) - (matriz[2] * matriz[4] * matriz[9]);

        // Na versão paralela, essa parte deverá ser executada pelo Pai.
        determinante = diagonais_principais + diagonais_secundarias;

        printf("------------------------------------------------------------------\n");
        printf("O resultado das diagonais principais e = %d \n", diagonais_principais);
        printf("O resultado das diagonais secundarias e = %d \n", diagonais_secundarias);
        printf("O Determinante e = %d \n", determinante);
        printf("------------------------------------------------------------------\n");
    }

    return 0;
}
