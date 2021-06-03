#include <stdio.h>
#include <stdlib.h>
#define size 4

/* ----------------------------
------------FUNÇÕES------------
-----------------------------*/

int addData(int nPessoas, int matriz[][size])
{
    printf("\nDigite 1 para SIM e 0 para NAO\n\n");

    for (int linha = 0; linha < nPessoas; linha++)
    {
        printf("\n----- | PESSOA %d | -----\n", linha);
        for (int coluna = 0; coluna < nPessoas; coluna++)
        {
            if (linha != coluna)
            {
                printf("\nReconhece pessoa %d ? : ", coluna);
                scanf("%d", &matriz[linha][coluna]);
            }
            else
                matriz[linha][coluna] = 0;
        }
        printf("\n\n");
    }
}

int listData(int nPessoas, int matriz[][size])
{
    printf("\n\t  ----- | MATRIZ | -----\n\n");

    for (int linha = 0; linha < nPessoas; linha++)
    {
        for (int coluna = 0; coluna < nPessoas; coluna++)
        {
            printf("\t%d", matriz[linha][coluna]);
        }
        printf("\n\n");
    }
    system("pause");
}

int analyzeData(int nPessoas, int matriz[][size])
{
    int flag;

    for (int linha = 0; linha < nPessoas; linha++)
    {
        flag = 0;
        for (int coluna = 0; coluna < nPessoas; coluna++)
        {
            if (matriz[linha][coluna] != 0)
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            printf("\nProfessor = %d\n\n", linha);
            break;
        }
        if (linha == (nPessoas - 1) && flag != 0)
        {
            printf("\nProfessor = professor nao esta na sala");
        }
        printf("\n\n");
    }
    system("pause");
}

/* ----------------------------
-------------MAIN--------------
-----------------------------*/

int main(void)
{
    int q;
    int nPessoas = size;
    int matriz[size][size];

    do
    {
        system("cls");
        printf("1 -> Adicionar dados\n");
        printf("2 -> Listar dados\n");
        printf("3 -> Analisar dados\n");
        printf("\nOpcao: ");
        scanf("%d", &q);

        switch (q)
        {
        case 1:
            addData(nPessoas, matriz);
            break;

        case 2:

            listData(nPessoas, matriz);
            break;

        case 3:
            analyzeData(nPessoas, matriz);
            break;

        case 9:
            break;

        default:
            printf("\n\n Opcao invalida\n");
            break;
        }
        getchar();
    } while ((q != 9));
    return 0;
}
