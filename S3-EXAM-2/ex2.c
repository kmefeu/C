// Matheus Corrêa - 202010270
// Leonardo Rossi Vinagre - 202010277

#include <stdio.h>
#include <stdlib.h>

typedef int dataType;

typedef struct bloc
{
    dataType data;
    struct bloc *left, *right;
    struct bloc *dad;
} node;

FILE *output;

int initBinTree(node **AB)
{
    *AB = NULL;
    return 0;
}

void printNode(int d, int p, int b)
{
    int i;

    for (i = 1; i < b; i++)
        printf("|------");
    printf("%d(%d)\n", d, p);

    for (i = 1; i < b; i++)
        fprintf(output, "|------");
    fprintf(output, "%d(%d)\n", d, p);
}

void printTree(node *dad, node *AB, int b)
{
    if (AB == NULL)
    {
        return;
    }
    printTree(AB, AB->right, b + 1);
    if ((AB->dad) != NULL)
        printNode(AB->data, (AB->dad)->data, b);
    else
        printNode(AB->data, 0, b);
    printTree(AB, AB->left, b + 1);
}

int insertBinTree(node **AB, dataType data)
{

    node *newNode, *aux, *temp;

    newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
        return 1;

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    aux = *AB;

    while (aux != NULL)
    {

        temp = aux;
        if (data == (aux->data))
            return 1;
        if (data > (aux->data))
            aux = aux->right;
        else
            aux = aux->left;
    }

    if (aux == *AB)
    {
        newNode->dad = NULL;
        *AB = newNode;
    }
    else
    {
        newNode->dad = temp;
        if (data > temp->data)
            temp->right = newNode;
        else
            temp->left = newNode;
    }

    return 0;
}

void leftAux(node *Tree, int layer, int *MaxLayer)
{
    if (Tree == NULL)
        return;

    if (*MaxLayer < layer)
    {
        printf("%d-", Tree->data);
        *MaxLayer = layer;
    }

    leftAux(Tree->left, layer + 1, MaxLayer);
    leftAux(Tree->right, layer + 1, MaxLayer);
}

void printLeft(node *Tree)
{
    int MaxLayer = 0;
    leftAux(Tree, 1, &MaxLayer);
}

int main()
{
    int i, option, data, erro;
    node *Tree;

    initBinTree(&Tree);
    do
    {
        system("cls");
        printf("\nBinari Tree");
        printf("\n\n1 -> Add data");
        printf("\n2 -> Print Tree");
        printf("\n3 -> Print left Tree");
        printf("\n0 -> Close");
        printf("\n\nOptions:");
        scanf("%d", &option);
        switch (option)
        {

        case 1:
            system("cls");
            printf("\nData: ");
            scanf("%d", &data);
            erro = insertBinTree(&Tree, data);
            if (erro == 1)
                printf("\nNumber already exist!\n");
            break;

        case 2:
            system("cls");
            printTree(NULL, Tree, 1);
            system("pause");
            break;

        case 3:
            system("cls");
            printLeft(Tree);
            system("pause");
            break;

        case 0:
            break;
        default:
            printf("\n\n Invalid Option");
        }
        getchar();
    } while ((option != 0));
    system("pause");
}
