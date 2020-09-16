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

    char alf[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'w', 'y', 'z'}; 

    int i, ii, iii, alfaOrder[n];

    for (i = 0; i < n; i++) 
    {

        printf("\n\nInsert: Name Address Telephone\n");
        scanf("%s%s%s", &users[i].name, &users[i].address, &users[i].telephone);

        alfaOrder[i] = i; 
    }
    
    for (i = 0; i < n; i++)
    {
        for (ii = 0; ii < strlen(users[i].name); ii++)
        {
            users[i].name[ii] = tolower(users[i].name[ii]);

            for (iii = 0; iii < strlen(alf); iii++)
            {

                if (users[i].name[ii] == alf[iii])
                {

                    users[i].nameId[ii] = iii;
                    break;
                }
            }
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (ii = i + 1; ii < n; ii++)
        {
            int shortest = (strlen(users[alfaOrder[i]].name) < strlen(users[alfaOrder[ii]].name)) ? users[alfaOrder[i]].name : users[alfaOrder[ii]].name;

            for (iii = 0; iii < shortest; iii++) 
            {

                if (users[alfaOrder[i]].nameId[iii] > users[alfaOrder[ii]].nameId[iii]) 
                {

                    int placeholder = alfaOrder[i];
                    alfaOrder[i] = alfaOrder[ii];
                    alfaOrder[ii] = placeholder;

                    break;
                }
            }
        }
    }
   
    printf("\n\nAlphabetical order\n"); 
   
    for (i = 0; i < n; i++)
    {
        printf("\n\nName:%s\nAddress:%s\nTelephone:%s\n\n", users[alfaOrder[i]].name, users[alfaOrder[i]].address, users[alfaOrder[i]].telephone);
    }

    printf("\n\n");

    return 0;
}