// Faça um programa que permita que o usuário entre com diversos nomes e telefone para cadastro. Crie um arquivo com essas informações, uma por linha. O usuário finaliza a entrada com o valor 0 para o telefone.

#include <stdio.h>

int main()
{

    system("cls");

    struct info
    {
        char name[100];
        char telnum[100];

        struct birth
        {
            int day;
            int month;
            int year;
        } datebirth;

    } contact;
    int result, compare;

    FILE *archive = fopen("contactList.txt", "a+b");

    if (archive == NULL)
    {
        printf("it happened a probllem to open archive.\n");
        system("pause");
        exit(1);
    }

    printf("Register to contact\n\n");

    do
    {

        printf("\n\nEnter 0 in telephone number to finish.");

        setbuf(stdin, NULL);
        printf("\nEnter contact telephone number:");
        fgets(contact.telnum, 99, stdin);

        compare = strncmp(contact.telnum, "0", 1);

        if (compare == 0)
        {
            printf("\nEnd of Code");
            break;
        }

        setbuf(stdin, NULL);
        printf("\nEnter contact name:");
        fgets(contact.name, 99, stdin);

        setbuf(stdin, NULL);
        printf("\nEnter day of birth:");
        scanf("%d", &contact.datebirth.day);

        setbuf(stdin, NULL);
        printf("\nEnter month of birth:");
        scanf("%d", &contact.datebirth.month);

        setbuf(stdin, NULL);
        printf("\nEnter year of birth:");
        scanf("%d", &contact.datebirth.year);

        result = fwrite(&contact, sizeof(contact), 1, archive);
        if (result == EOF)
        {

            printf("\nReading file Error");
            printf("\nEnd of File");
            continue;
        }

        printf("\n\nNext!");

    } while (contact.telnum != 0);

    fclose(archive);

    printf("\n\n");

    return 0;
}