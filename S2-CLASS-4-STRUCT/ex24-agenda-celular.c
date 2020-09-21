#include <stdio.h>
#include <string.h>

struct info
{
    char name[30]; // nome

    char email[30]; //email

    char tel[15]; //telefone

    char obs[100]; // observação

    struct birth
    {
        int day; // day

        int month; //mes

        int year; //ano
    };

    struct addres
    {
        char street[30]; // rua

        int number; // numero

        char comp[30]; //complemento

        char nei[30]; //bairro

        char cep[15]; //CEP

        char city[30]; //cidade

        char state[30]; // estado

        char country[30]; // pais
    };
} ag[100];

void add()
{

    int i = strlen(ag) + 1;

    fflush(stdin);
    printf("\nName:");
    fgets(ag[i].name, 30, stdin);

    fflush(stdin);
    printf("\nE-mail:");
    fgets(ag[i].email, 30, stdin);

    fflush(stdin);
    printf("\nTelephone:");
    fgets(ag[i].tel, 15, stdin);

    fflush(stdin);
    printf("\nObs:");
    fgets(ag[i].obs, 100, stdin);

    fflush(stdin);
    printf("\nBirth Day:");
    scanf("%d", &ag[i].day);

    fflush(stdin);
    printf("\nBirth Month:");
    scanf("%d", ag[i].month);

    fflush(stdin);
    printf("\nBirth Year:");
    scanf("%d", &ag[i].year);

    fflush(stdin);
    printf("\nStreet:");
    fgets(ag[i].street, 30, stdin);

    fflush(stdin);
    printf("\nNumber:");
    scanf("%d", &ag[i].number);

    fflush(stdin);
    printf("\nComplement:");
    fgets(ag[i].com, 30, stdin);

    fflush(stdin);
    printf("\nNeighborhood:");
    fgets(ag[i].nei, 30, stdin);

    fflush(stdin);
    printf("\nCEP:");
    fgets(ag[i].cep, 15, stdin);

    fflush(stdin);
    printf("\nCity:");
    fgets(ag[i].city, 30, stdin);

    fflush(stdin);
    printf("\nState:");
    fgets(ag[i].state, 30, stdin);

    fflush(stdin);
    printf("\nCountry:");
    fgets(ag[i].state, 30, stdin);
}

void print(i)
{
    printf("\nUSER FOUND");

    printf("\nName:%s", ag[i].name);

    printf("\nE-mail:%s", ag[i].email);

    printf("\nTelephone:%s", ag[i].tel);

    printf("\nObs:%s", ag[i].obs);

    printf("\nBirth Day:%d", ag[i].day);

    printf("\nBirth Month:%d", ag[i].month);

    printf("\nBirth Year:%d", ag[i].year);

    printf("\nStreet:%s", ag[i].street);

    printf("\nNumber:%D", ag[i].number);

    printf("\nComplement:%s", ag[i].comp);

    printf("\nNeighborhood:%s", ag[i].nei);

    printf("\nCEP:%s", ag[i].cep);

    printf("\nCity:%s", ag[i].city);

    printf("\nState:", ag[i].state);

    printf("\nCountry:%s", ag[i].state);
}

void sName(n)
{

    for (int i = 0; i < strlen(ag); i++)
    {

        if (strcmp(n, ag[i].name) == 0)
        {
            print(i);
        }
    }
}

void sMonth(m)
{

    for (int i = 0; i < strlen(ag); i++)
    {

        if (strcmp(m, ag[i].month) == 0)
        {
            print(i);
        }
    }
}
void sBirth(d, m)
{

    for (int i = 0; i < strlen(ag); i++)
    {

        if (strcmp(d, ag[i].day) == 0 && strcmp(m, ag[i].month) == 0)
        {
            print(i);
        }
    }
}

void delet()
{
}

void alfa()
{
    add();

    for (int i = 0; i < strlen(ag); i++)
    {
        if (i > 0)
        {

            if (strcmp(ag[i - 1].name, ag[i].name) < 0)
            {

                char name[30];
                char email[30];
                char tel[15];
                char obs[100];
                int day;
                int month;
                int year;
                char street[30];
                int number;
                char comp[30];
                char nei[30];
                char cep[15];
                char city[30];
                char state[30];
                char country[30];

                strcpy(name, ag[i].name);
                strcpy(email, ag[i].email);
                strcpy(tel, ag[i].tel);
                strcpy(obs, ag[i].obs);
                strcpy(day, ag[i].day);
                strcpy(month, ag[i].month);
                strcpy(year, ag[i].year);
                strcpy(street, ag[i].street);
                strcpy(number, ag[i].number);
                strcpy(comp, ag[i].comp);
                strcpy(nei, ag[i].nei);
                strcpy(cep, ag[i].cep);
                strcpy(state, ag[i].state);
                strcpy(country, ag[i].country);

                strcpy(ag[i].name, ag[i-1].name);
                strcpy(ag[i].email, ag[i-1].email);
                strcpy(ag[i].tel, ag[i-1].tel);
                strcpy(ag[i].obs, ag[i-1].obs);
                strcpy(ag[i].day, ag[i-1].day);
                strcpy(ag[i].month, ag[i-1].month);
                strcpy(ag[i].year, ag[i-1].year);
                strcpy(ag[i].street, ag[i-1].street);
                strcpy(ag[i].number, ag[i-1].number);
                strcpy(ag[i].comp, ag[i-1].comp);
                strcpy(ag[i].nei, ag[i-1].nei);
                strcpy(ag[i].cep, ag[i-1].cep);
                strcpy(ag[i].state, ag[i-1].state);
                strcpy(ag[i].country, ag[i-1].country);

            }
        }
    }
}

int main()
{

    system("cls");

    printf("\n\n");

    return 0;
}