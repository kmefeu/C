#include <stdio.h>
#include <stdlib.h>
#define size 4

//MATHEUS CORRÊA RA 202010270
//MARCIO BASSI   RA 202010274
//CLEBER SILVA   RA 202010136
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
        //printf("\nPOP %d", remove);
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
    {
        printf("\nPilha Vazia\n");
        system("pause");
        return feedback; /* nao possivel listar pois a pilha vazia */
    }
}

/* ----------------------------
------------FUNÇÕES------------
-----------------------------*/

int addData(int numberOfPeople, int matriz[][size], class *pile)
{

    printf("\nDigite 1 para SIM e 0 para NAO\n\n");

    for (int line = 0; line < numberOfPeople; line++)
        push(pile, line);

    for (int line = 0; line < numberOfPeople; line++)
    {

        printf("\n----- | PESSOA %d | -----\n", pile->possibleTeacher[line]);
        for (int coloumn = 0; coloumn < numberOfPeople; coloumn++)
        {
            if (line != coloumn)
            {
                printf("\nReconhece pessoa %d ? : ", pile->possibleTeacher[coloumn]);
                scanf("%d", &matriz[line][coloumn]);
            }
            else
                matriz[line][coloumn] = 0;
        }
        printf("\n\n");
    }
}

int listData(int numberOfPeople, int matriz[][size])
{
    if (matriz[0][0] == 0 || matriz[0][0] == 1)
    {
        printf("\n\t  ----- | MATRIZ | -----\n\n");

        // printf("------");

        // for (int coloumn = 0; coloumn < numberOfPeople; coloumn++)
        // {
        //     printf("\t| %d |", coloumn);
        // }

        printf("\n");

        for (int line = 0; line < numberOfPeople; line++)
        {
            printf(" | %d |  ", line);

            for (int coloumn = 0; coloumn < numberOfPeople; coloumn++)
            {
                printf("\t%d", matriz[line][coloumn]);
            }
            printf("\n\n");
        }
        system("pause");
        return 0;
    }
    printf("\nPrimeiro Adicione os dados pela opcao 1\n");
    system("pause");
    return 1;
}

int analyzeData(int numberOfPeople, int matriz[][size], class *pile)
{
    while (pile->top != 0)
    {

        int peopleToCompare[2];

        peopleToCompare[0] = pop(pile);
        peopleToCompare[1] = pop(pile);
        // printf("\nPOP %d", peopleToCompare[0]);
        //printf("\nPOP %d", peopleToCompare[1]);

        //Se A reconhece B, então A não pode ser o professor e B volta para a pilha
        if (matriz[peopleToCompare[0]][peopleToCompare[1]] == 1)
        {
            // printf("\n%d nao pode ser professor, reconheceu %d ", peopleToCompare[0], peopleToCompare[1]);
            //printf("\nPUSH %d", peopleToCompare[1]);
            push(pile, peopleToCompare[1]);
        }
        //Se A não reconhece B, então B não pode o professor e A volta para a pilha.
        else
        {
            //printf("\n%d nao pode ser professor, nao foi reconhecido por %d ", peopleToCompare[1], peopleToCompare[0]);
            // printf("\nPUSH %d", peopleToCompare[0]);
            push(pile, peopleToCompare[0]);
        }
        printf("\n\n");
    }

    int flag = 1;

    int possibleTeacher = pop(pile);

    for (int i = 0; i < size; i++)
    {
        if (i != possibleTeacher && matriz[possibleTeacher][i] == 1)
        {
            flag = 0;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (i != possibleTeacher && matriz[i][possibleTeacher] == 0)
        {
            flag = 0;
        }
    }
    if (flag == 1)
    {
        printf("\nProfessor = %d\n\n", possibleTeacher);
    }
    else
    {

        printf("\nProfessor = professor nao esta na sala\n");
    }
    system("pause");
    return 0;
}

/* ----------------------------
-------------MAIN--------------
-----------------------------*/

int main(void)
{
    int q;
    int numberOfPeople = size;
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
        printf("9 -> Fechar Programa\n");
        printf("\nOpcao: ");
        scanf("%d", &q);

        switch (q)
        {
        case 1:
            addData(numberOfPeople, matriz, &pile);
            break;

        case 2:

            listData(numberOfPeople, matriz);
            break;

        case 3:
            analyzeData(numberOfPeople, matriz, &pile);
            break;
        case 4:
            listPile(pile);
            break;

        case 9:
            break;

        default:
            printf("\n\n Opcao invalida, use uma das opcoes do menu\n\n");
            system("pause");
            break;
        }
        getchar();
    } while ((q != 9));
    return 0;
}