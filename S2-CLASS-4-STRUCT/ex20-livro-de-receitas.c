// 20. Make a program to store a cookbook and:
// Create a vector of 5 recipes, which must have a name (maximum 25 letters), number of ingredients and ingredients.
// For each recipe, read its name and the amount of ingredients. Then create and read the ingredient vector, each ingredient containing a name and quantity.
// Search for recipe by name, showing your ingredients if you find. If not, inform the user. Repeat the process until you type an empty string.

// 20. Fac¸a um programa para armazenar um livro de receitas e:
// Crie um vetor de 5 receitas, que deve ter nome (ma´ximo 25 letras), quantidade de ingredientes e ingredientes.
// Para cada receita, leia seu nome e a quantidade de ingredientes. Enta˜o crie e leia o vetor de ingredientes, sendo que cada ingrediente conte´m nome e quantidade.
// Procure receita por nome, mostrando seus ingredientes se encontrar. Se na˜o en- contrar, informe ao usua´rio. Repita o processo ate´ digitar uma string vazia.

#include <stdio.h>
#include <string.h>
#define n 5

struct cookbook // cookbook //livro de receita
{
    char name[25];

    int ni; // número de ingredientes // number of ingredients

    struct ingredients // ingredientes info
    {
        char name[25]; // nome

        char amount[10]; // quantidade

    } ing[50];

} recepi[n];

int main()
{

    system("cls");

    int i, ii, b = 0;

    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Insert: Recepi Ingredients(n): ");
        scanf("%s %d", &recepi[i].name, &recepi[i].ni);
    }

    for (i = 0; i < n; i++)
    {
        printf("\nRecepi:%s", recepi[i].name);

        for (ii = 0; ii < recepi[i].ni; ii++)
        {
            fflush(stdin);
            printf("\nIngredient[%d]: Name Amount: ", ii);
            scanf("%s %s", recepi[i].ing[ii].name, recepi[i].ing[ii].amount);
        }
    }

    printf("\n\n\t\t-----COOKBOOK-----");

    for (i = 0; i < n; i++)
    {
        printf("\n\nRecepi:%s", recepi[i].name);

        for (ii = 0; ii < recepi[i].ni; ii++)
        {
            printf("\nIngredient[%d]: %s %s", ii, recepi[i].ing[ii].name, recepi[i].ing[ii].amount);
        }

        printf("\n\n");
    }

    printf("\n\n");

    return 0;
}