// Dado um arquivo contendo um conjunto de nomes e datas de nmascimento (dia, mês e ano, isto é, trés inteiros seguidos), escrever um programa que leia esse arquivo e a data atual e gere outro arquivo contendo o nome e idade.

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>

int main()
{
    system("cls");

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    struct
    {
        char name[100];
        char telnum[100];

        struct
        {
            int day;
            int month;
            int year;

        } datebirth;

    } contact;
    int result, age;

    struct
    {
        char name[100];
        int age;
    } contactAge;

    FILE *file1 = fopen("contactList.txt", "r+b");
    FILE *file2 = fopen("contactAge.txt", "a+b");

    if (file1 == NULL)
    {
        printf("Error opening file. System Pause.\n");
        system("pause");
        exit(1);
    }

    while (!feof(file1))
    {
        age = 0;

        fread(&contact, sizeof(contact), 1, file1);

        if (feof(file1))
        {
            break;
        }

        printf("Name: %sTelephone: %sirth: %d/%d/%d\n\n", contact.name, contact.telnum, contact.datebirth.day, contact.datebirth.month, contact.datebirth.year);

        strcpy(contactAge.name, contact.name);

        age = tm.tm_year - contact.datebirth.year;

        if (tm.tm_mon < contact.datebirth.month)
        {
            age -= 1;
        }

        else if (tm.tm_mon == contact.datebirth.month)
        {
            if (tm.tm_mday < contact.datebirth.day)
            {
                age -= 1;
            }
        }
        contactAge.age = age + 1900;
        result = fwrite(&contactAge, sizeof(contactAge), 1, file2);

        if (result == EOF)
        {
            printf("\nReading file Error");
            printf("\nEnd of File");
            continue;
        }
    }

    fclose(file1);
    fclose(file2);
}