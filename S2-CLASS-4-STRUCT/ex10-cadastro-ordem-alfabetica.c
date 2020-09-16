//10. Using one struct, make a program that allows inputing a name, address and telephone number of five people and them print in alfabetical order.

// 10. Utilizando uma estrutura, fac¸a um programa que permita a entrada de nome, enderec¸o e telefone de 5 pessoas e os imprima em ordem alfabe´tica.

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define n 5

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

    char alf[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'w', 'y', 'z'}; // String alfabeto para comparar com o nome // Alphabetic string to compare with the name

    int i, ii, iii, alfaOrder[n];

    for (i = 0; i < n; i++) // Entrada de dados // Input of data
    {

        printf("\n\nInsert: Name Address Telephone\n");
        scanf("%s%s%s", &users[i].name, &users[i].address, &users[i].telephone);

        alfaOrder[i] = i; // Para que o vetor em ordem alfabética fique igual a original facilitando as operações de troca de posição // Creat a copy from the original vector making easy to change places latter
    }

    for (i = 0; i < n; i++) // Para cada Usuário // For each user
    {
        for (ii = 0; ii < strlen(users[i].name); ii++) // Para cada letra // For each letter
        {
            users[i].name[ii] = tolower(users[i].name[ii]);

            for (iii = 0; iii < strlen(alf); iii++) // Compara cada letra do nome com cada letra do alfabeto e gera uma string com numeros equivalente a letras // Compare each letter of the name with each letter on the alphabet and them generate a string with id numbers
            {

                if (users[i].name[ii] == alf[iii])
                {

                    // Tire o comentário caso queira ver o algoritimo // Remove the coment to check the algorithm
                    // printf("%c", users[i].name[ii]);
                    // printf("%c", alf[iii]);
                    // printf("%d", iii);

                    users[i].nameId[ii] = iii;
                    break;
                }
            }
        }
    }

    for (i = 0; i < n; i++) // Para cada usuário // For each user
    {

        for (ii = i + 1; ii < n; ii++) // Compara usuário com usuário // Compare to another user
        {
            int shortest = (strlen(users[alfaOrder[i]].name) < strlen(users[alfaOrder[ii]].name)) ? users[alfaOrder[i]].name : users[alfaOrder[ii]].name; // Pega o comprimento do menor nome para evitar comparação vazia// Use the shortest name length to avoide comparing null values

            for (iii = 0; iii < shortest; iii++) // Compara número a número de cada nomeId // For each number/letter in the name/nameId
            {

                // Tire o comentário caso queira ver o algoritimo // Remove the coment to check the algorithm

                if (users[alfaOrder[i]].nameId[iii] < users[alfaOrder[ii]].nameId[iii]) // Quando o numero do nome i é menor que o ii não tem troca de lugar // When the number in name i is smaller than the number in the name ii nothing happens
                {
                    printf("\n\n%s[%d][%d] = %c < %s[%d][%d] = %c", users[alfaOrder[i]].name, i, iii, users[alfaOrder[i]].name[iii], users[alfaOrder[ii]].name, ii, iii, users[alfaOrder[ii]].name[iii]);
                    break;
                }

                if (users[alfaOrder[i]].nameId[iii] > users[alfaOrder[ii]].nameId[iii]) // Quando o numero do nome i é maior que o numero de ii eles trocam de lugar // When i is bigger than ii they switch places
                {
                    printf("\n\n%s[%d][%d] = %c > %s[%d][%d] = %c", users[alfaOrder[i]].name, i, iii, users[alfaOrder[i]].name[iii], users[alfaOrder[ii]].name, ii, iii, users[alfaOrder[ii]].name[iii]);

                    printf("\nAlfaOrder[%d ] = %s", i, users[alfaOrder[ii]].name);
                    printf("\nAlfaOrder[%d] = %s \n\n", ii, users[alfaOrder[i]].name);

                    int placeholder = alfaOrder[i]; // guarda provisoriamente o conteudo da posição i // holds the content of i for a moment

                    alfaOrder[i] = alfaOrder[ii];
                    alfaOrder[ii] = placeholder;

                    break;
                }
            }
        }
    }

    printf("\n\nAlphabetical order\n"); // Ordem Alfabética

    for (i = 0; i < n; i++)
    {
        printf("\n\nName:%s\nAddress:%s\nTelephone:%s\n\n", users[alfaOrder[i]].name, users[alfaOrder[i]].address, users[alfaOrder[i]].telephone);
    }

    // Tire o comentário caso queira confirmar a ordem de entrada // Remove the coment to check the insert order

    // printf("\nInsert Order\n"); // Ordem de entrada

    // for (i = 0; i < n; i++)
    // {
    //     printf("\n\nName:%s\nAddress:%s\nTelephone:%s\n", users[i].name, users[i].address, users[i].telephone);
    //     printf("NameId:");

    //     for (ii = 0; ii < 10; ii++) // Para confirmar os valores do nomeId // To confirm the values of nameId
    //     {

    //         printf("%i ", users[i].nameId[ii]);
    //     }

    //     printf("\n\n");
    // }

    printf("\n\n");

    return 0;
}