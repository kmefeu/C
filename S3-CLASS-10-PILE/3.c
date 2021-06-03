#include <stdio.h>
#include <stdlib.h>
#define size 4

typedef struct pile
{
    int top;
    int possibleTeacher[size];
} class;

int initPile(class *pile)
{
    (*pile).top = -1;
    return 0;
}

int check(class *pile)
{
    if ((*pile).top == -1)
        return 0; /* pilha vazia */
    else
    {
        if ((*pile).top == size - 1)
            return 1; /* pilha cheia */
        else
            return 2; /* pilha não vazia com capacidade de armazenamento */
    }
}

int push(class *pile, int possibleTeacher)
{
    int feedback = check(pile);
    if ((feedback == 0) || (feedback == 2))
    {
        (*pile).top++;
        (*pile).possibleTeacher[(*pile).top] = possibleTeacher;

        return 0;
    }
    else
        return feedback;
}

char pop(class *pile)
{
    int feedback = check(pile);
    if (feedback != 0)
    {
        int remove = pile->possibleTeacher[pile->top];
        pile->top--;
        return remove;
    }
    else
        return feedback;
}

int listPile(class pile)
{
    int feedback = check(&pile);
    if ((feedback == 1) || (feedback == 2))
    {
        printf("\n -----|TOPO|-----\n");
        for (int i = pile.top; i >= 0; i--)
        {
            printf("\t%d\n", (&pile)->possibleTeacher[i]);
        }
        printf(" -----|BASE|-----\n\n");
        system("pause");
        return 0;
    }
    else
        return feedback; /* nao possivel listar pois a pilha vazia */
}

/* ----------------------------
------------FUNÇÕES------------
-----------------------------*/

int addData(int nPessoas, int matriz[][size], class *pile)
{

    printf("\nDigite 1 para SIM e 0 para NAO\n\n");

    for (int linha = 0; linha < nPessoas; linha++)
    {
        push(pile, linha);
        printf("\n----- | PESSOA %d | -----\n", pile->possibleTeacher[linha]);
        for (int coluna = 0; coluna < nPessoas; coluna++)
        {
            if (linha != coluna)
            {
                printf("\nReconhece pessoa %d ? : ", pile->possibleTeacher[coluna]);
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
        printf("%d", linha);

        for (int coluna = 0; coluna < nPessoas; coluna++)
        {
            printf("\t%d", matriz[linha][coluna]);
        }
        printf("\n\n");
    }
    system("pause");
}

int analyzeData(int nPessoas, int matriz[][size], class *pile)
{

    while (pile->top != 1 || pile->top != -1)
    {

        char peopleToCompare[2];

        for (int i = 0; i < 2; i++)
        {
            peopleToCompare[i] = pop(pile);
        }

        int flag;

        for (int linha = 0; linha < nPessoas; linha++)
        {
            if (matriz[linha][0] != 3)
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
                    int flag2 = 0;

                    for (int linha2 = 0; linha2 < nPessoas; linha2++)
                    {
                        if (linha2 != linha && matriz[linha2][linha] != 1)
                        {
                            flag2 = 1;
                        }
                    }

                    if (flag2 == 0)
                        printf("\nProfessor = %d\n\n", linha);
                    break;
                }
                else
                {
                    matriz[linha][0] = 3;
                }
                // da pra fazer um for passando pra ver se ta tudo 3 na primeira linha
                if (linha == (nPessoas - 1) && flag != 0)
                {
                    printf("\nProfessor = professor nao esta na sala");
                }
                printf("\n\n");
            }
        }
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
    class pile;
    initPile(&pile);

    do
    {
        system("cls");
        printf("1 -> Adicionar dados\n");
        printf("2 -> Listar dados\n");
        printf("3 -> Analisar dados\n");
        printf("4 -> Listar pilha\n");
        printf("\nOpcao: ");
        scanf("%d", &q);

        switch (q)
        {
        case 1:
            addData(nPessoas, matriz, &pile);
            break;

        case 2:

            listData(nPessoas, matriz);
            break;

        case 3:
            analyzeData(nPessoas, matriz, &pile);
            break;
        case 4:
            listPile(pile);
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
