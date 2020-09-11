// 2. Implemente um programa que leia o nome, a idade e o enderec¸o de uma pessoa e armazene os dados em uma estrutura.
// 2. Implement a program that reads a person's name, age and address and stores the data in a structure.

#include <stdio.h>

struct registrations // cadastros
{
    char name[50]; // nome

    int age; // idade

    char address[100]; // endereço

} person;

int main()
{

    system("cls");

    printf("\n\nInsert: Name Age Address\n\n");//insira: Nome Idade Endereço
    scanf("%s%d%s",&person.name, &person.age, &person.address);

    printf("\n\nName:%s \nAge:%d \nAddress:%s",person.name, person.age, person.address);

    printf("\n\n");

    return 0;
}   