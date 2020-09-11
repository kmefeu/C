//10. Using one struct, make a program that allows inputing a name, address and telephone number of five people and them print in alfabetical order.

// 10. Utilizando uma estrutura, fac¸a um programa que permita a entrada de nome, enderec¸o e telefone de 5 pessoas e os imprima em ordem alfabe´tica.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define n 3

struct info
{
    char name[50]; // nome

    int nameId[50]; //id do nome (a = 0, b = 1, c = 2)

    char address[100]; // endereço

    char telephone[20]; // telefone

} users[n]; // usuários

int main()
{
    system("cls");

    char alf[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'w', 'y', 'z'};

    int i, ii, iii, order[n];

    for (i = 0; i < n; i++) // Grava os dados
    {

        printf("\n\nInsert: Name Address Telephone\n");
        scanf("%s%s%s", &users[i].name, &users[i].address, &users[i].telephone);
    }

    for (i = 0; i < n; i++) // Para cada Usuário
    {
        for (ii = 0; ii < strlen(users[i].name); ii++) // Para cada letra
        {
            users[i].name[ii] = tolower(users[i].name[ii]);

            for (iii = 0; iii < strlen(alf); iii++) // Compara com cada letra do alfabeto e gera um nome id string
            {

                if (users[i].name[ii] == alf[iii])
                {
                    // printf("%c", users[i].name[ii]);
                    // printf("%c", alf[iii]);
                    // printf("%d", iii);

                    users[i].nameId[ii] = iii;
                    break;
                }
            }
        }
    }

    for (i = 0; i < n; i++) // Para cada usuário
    {

        for (ii = i + 1; ii < n; ii++) // compara usuário com usuário
        {
            int smallest = (strlen(users[i].name) <= strlen(users[ii].name)) ? users[i].name : users[ii].name; // pega o comprimento do menor nome

            for (iii = 0; iii < smallest; iii++) // Compara número a número do nome id
            {
                if (users[i].nameId[iii] < users[ii].nameId[iii]) // Quando o numero atual é menor que o anterio ele sobe o nome 1 posição
                {
                    printf("\n\nuser[%d].name[%d] = %c < nuser[%d].name[%d] = %c", i, iii, users[i].name[iii], ii, iii, users[ii].name[iii]);

                    order[i] = i;

                    printf("\norder[i] = %d \n\n", i);
                    
                    break;
                }

                if (users[i].nameId[iii] > users[ii].nameId[iii])
                {
                    printf("\n\nuser[%d].name[%d] = %c > nuser[%d].name[%d] = %c", i, iii, users[i].name[iii], ii, iii, users[ii].name[iii]);

                    order[i] = ii;

                    printf("\norder[ii] = %d \n\n", ii);

                    break;
                }
            }
        }
    }

    printf("\n\nAlphabetical order\n"); // Ordem Alfabética

    for (i = 0; i < n; i++)
    {
        printf("\n\nName:%s\nAddress:%s\nTelephone:%s\n\n", users[order[i]].name, users[order[i]].address, users[order[i]].telephone);
    }

    printf("\nInsert Order\n");

    for (i = 0; i < n; i++)
    {
        printf("\n\nName:%s\nAddress:%s\nTelephone:%s\n", users[i].name, users[i].address, users[i].telephone);
        printf("NameId:");

        for (ii = 0; ii < 10; ii++)
        {

            printf("%i ", users[i].nameId[ii]);
        }

        printf("\n\n");
    }

    printf("\n\n");

    return 0;
}