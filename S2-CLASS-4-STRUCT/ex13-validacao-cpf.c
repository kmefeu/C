// Ask the user to enter their personal data (Name, Address, Date of Birth, City, Zip Code, email), check if the Date of Birth, Zip code and email information make sense , and show the user the information, if it is all correct, or show that some information was wrong.

// Pec¸a ao usua´rio para digitar seus dados pessoais (Nome, Enderec¸o, Data de Nasci- mento, Cidade, CEP, email), verifique se as informac¸o˜es de Data de Nascimento, CEP e email fazem sentido, e mostre ao usua´rio as informac¸o˜es, se esta˜o todas corretas, ou mostre que alguma informac¸a˜o estava errada.

#include <stdio.h>
#include <string.h>

struct info
{
    char name[20]; // nome

    char address[50]; // endereço

    char birth[10]; // nascimento

    char city[20]; // Cidade

    char cep[8]; // CEP

    char cpf[8]; // CPF
} user;

int main()
{

    system("cls");

    printf("\n\nInsert: Name Address City\n\n"); 
    scanf("%s%s%s", &user.name, &user.address, &user.city);

    printf("\n\nInsert: Birth(DD/MM/YYYY) CEP CPF\n\n"); 
    scanf("%s%s%s",  &user.birth,  &user.cep, &user.cpf);

    printf("\n\nName:%s OK!", user.name);
    printf("\nAddress:%s OK!", user.address);
    printf("\nAddress:%s OK!", user.city);

    if (strlen(user.birth) < 10)
    {
        printf("\nBirth:%s ERROR!", user.birth);
    }
    else
    {
        printf("\nBirth:%s OK!", user.birth);
    }

    if (strlen(user.cep) < 8)
    {
        printf("\nCEP:%s ERROR!", user.cep);
    }
    else
    {
        printf("\nCEP:%s OK!", user.cep);
    }
    if (strlen(user.cpf) < 8)
    {
        printf("\nCPF:%s ERROR!", user.cpf);
    }
    else
    {
        printf("\nCPF:%s OK!", user.cpf);
    }

    printf("/n/n");

    return 0;
}