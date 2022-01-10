
/**************************************************************************************
*** Programa que calcula o determinante de uma matriz, recebendo-a atraves de arquivo
**************************************************************************************/

// Matheus Corrêa Cleber Augusto

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *filho(int matriz[])
{
    int diagonais_principais;
    printf("Processo-Filho1: Iniciando Execucao.\n");
    diagonais_principais = (matriz[1] * matriz[5] * matriz[9]) + (matriz[2] * matriz[6] * matriz[7]) + (matriz[3] * matriz[4] * matriz[8]);
    printf("beco diagonal %d\n", diagonais_principais);
    sleep(1);
    printf("Processo-Filho1: Encerrando Execucao.\n");
}

void *filho2(int matriz[])
{
    int diagonais_secundarias;
    printf("Processo-Filho2: Iniciando Execucao.\n");
    diagonais_secundarias = (matriz[1] * matriz[5] * matriz[9]) + (matriz[2] * matriz[6] * matriz[7]) + (matriz[3] * matriz[4] * matriz[8]);
    sleep(1);
    printf("Processo-Filho2: Encerrando Execucao.\n");
}

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

        pthread_t thread_id;
        pthread_t thread_id2;
        system("clear");
        pthread_create(&thread_id, NULL, filho(matriz), NULL);

        pthread_join(thread_id, NULL);
        printf("passssssouuuuuuuuu delicia aiiin 222222 \n");
        pthread_create(&thread_id2, NULL, filho2(matriz), NULL);
        pthread_join(thread_id2, NULL);

        determinante = diagonais_principais + diagonais_secundarias;

        printf("------------------------------------------------------------------\n");
        printf("O resultado das diagonais principais e = %d \n", diagonais_principais);
        printf("O resultado das diagonais secundarias e = %d \n", diagonais_secundarias);
        printf("O Determinante e = %d \n", determinante);
        printf("------------------------------------------------------------------\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    pid_t filho1, filho2;
    int estado, valor = 10;
    system("clear");
    printf("Processo-Pai: Iniciando a execucao.\n");

    filho1 = fork();
    if (filho1 == 0)
    {
        printf("Processo-Filho 1: Iniciando a execucao.\n");
        valor = valor + 5;
        printf("Processo-Filho 1: O valor de VALOR e %d.\n", valor);
        sleep(5);
        printf("Processo-Filho 1: Encerrando a execucao.\n");
        exit(0);
    }

    filho2 = fork();
    if (filho2 == 0)
    {
        printf("Processo-Filho 2: Iniciando a execucao.\n");
        valor = valor - 2;
        printf("Processo-Filho 2: O valor de VALOR e %d.\n", valor);
        sleep(5);
        printf("Processo-Filho 2: Encerrando a execucao.\n");
        exit(0);
    }

    waitpid(filho1, estado, 0);
    waitpid(filho2, estado, 0);

    printf("Processo-Pai: O valor de VALOR e %d.\n", valor);
    printf("Processo-Pai: Encerrando a execucao.\n");
    return 0;
}
