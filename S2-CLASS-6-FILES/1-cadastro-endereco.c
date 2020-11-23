#include <stdio.h>
#include <stdlib.h>

void registerCustomer();
void listCustomer();
void excludeCustomer();
void listCustomerByCode();

typedef struct strCustomers
{
    int id;
    char name[26];
    char address[31];
    char cpf[15];
    int flag;
} customers;

int main()
{

    int option;
    system("cls");
    do
    {

        printf("Main Menu\n");
        printf("1 - Include Customers\n");
        printf("2 - List  Customers\n");
        printf("3 - Exclude Customers\n");
        printf("4 - List  Customers by code\n");
        printf("5 - Close app\n");
        printf("Option:");
        scanf("%d", &option);

        if (option == 1)
        {
            system("cls");
            registerCustomer();
        }
        if (option == 2)
        {
            system("cls");
            listCustomer();
        }
        if (option == 3)
        {
            excludeCustomer();
        }
        if (option == 4)
        {
            listCustomerByCode();
        }

    } while (option != 5);
    return 0;
}

void registerCustomer()
{

    int resp;
    customers TBCustomers;
    printf("Register customer data\n\n");

    printf("Id:");
    scanf("%d", &TBCustomers.id);
    getchar();

    printf("Name:");
    fgets(TBCustomers.name, 26, stdin);

    printf("Address:");
    fgets(TBCustomers.address, 31, stdin);

    printf("CPF:");
    fgets(TBCustomers.cpf, 15, stdin);

    TBCustomers.flag = 1;
    FILE *fp = fopen("customers.txt", "a+b");
    if (fp == NULL)
    {
        printf("Error: opening the file");
        exit(1);
        getchar();
    }

    resp = fwrite(&TBCustomers, sizeof(customers), 1, fp);
    if (resp != 1)
    {
        printf("Error: It was not possible to register the client");
    }

    fclose(fp);
    system("cls");

    printf("Press any key to continue");
    getchar();

    system("cls");
}

void listCustomer()
{
    customers TBCustomers;
    FILE *fp = fopen("customers.txt", "r+b");
    if (fp == NULL)
    {
        printf("Error: opening the file");
        exit(1);
        getchar();
    }

    while (!feof(fp))
    {
        fread(&TBCustomers, sizeof(TBCustomers), 1, fp);
        if (feof(fp))
        {
            break;
        }
        if (TBCustomers.flag == 1)
        {
            printf("Id:%d\nName:%sAddress:%sCPF:%s\n", TBCustomers.id, TBCustomers.name, TBCustomers.address, TBCustomers.cpf);
            getchar();
        }
    }
    fclose(fp);
    printf("Error: opening the file");
    getchar();
    getchar();
    system("cls");
}

void excludeCustomer()
{

   customers TBCustomers;
    FILE *fp = fopen("customer.txt", "r+b");
    FILE *fp2 = fopen("customer2.txt", "wb");
    char path[] = "customer.txt";
    char newPath[] = "customer2.txt";
    int id, answer, end = 0;

    if (fp == NULL)
    {
        printf("Error: opening the file");
        exit(1);
        getchar();
    }

    printf("Type the id to exclude:");
    scanf("%d", &id);

    while (!feof(fp))
    {
        fread(&TBCustomers, sizeof(TBCustomers), 1, fp);
        if (feof(fp))
        {
            break;
        }
        if (TBCustomers.id == id)
        {
            ;
            TBCustomers.flag = 0;
            end = 1;
        }

        if (TBCustomers.flag == 1)
        {
            answer = fwrite(&TBCustomers, sizeof(customers), 1, fp2);
            if (answer != 1)
            {
                printf("Error: It was not possible to delete the customer");
            }
        }
    }

    void listCustomerByCode()
{

    customers TBCustomers;
    FILE *fp = fopen("customer.txt", "r+b");
    int id, end = 0;
    if (fp == NULL)
    {
        printf("Error: opening the file");
        exit(1);
        getchar();
    }

    printf("Type id to search:");
    scanf("%d", &id);

    while (!feof(fp))
    {
        fread(&TBCustomers, sizeof(TBCustomers), 1, fp);
        if (feof(fp))
        {
            break;
        }
        if (TBCustomers.flag == 1)
        {
            if (TBCustomers.id == id)
            {
                printf("Id:%d\nName:%sAddress:%sCPF:%s\n", TBCustomers.id, TBCustomers.name, TBCustomers.address, TBCustomers.cpf);
                getchar();
                end = 1;
            }
        }
    }
    fclose(fp);
    if (end == 0)
        printf("Costomer not found\n");
    printf("Press any key to continue");
    getchar();
    getchar();
    system("cls");
}}
