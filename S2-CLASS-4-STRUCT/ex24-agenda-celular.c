// 24.Make a program to simulate a phonebook. For each person, the following data should be kept:
// • Name
// • The e-mail
// Address (containing fields for Rua, number, complement, neighborhood, zip code, city, state, country).
// • Telephone (containing field for area code and number)
// • Birthday date (containing field for day, month, year).
// • Observations: A line (string) for some special observation.
// (a) Define a structure above.
// (b) Declare a variable agenda (vector) with the capacity to schedule up to 100 names.
// (c) Define a block of instructions search by first name: Print the data of the person with that name (if you have more than one person, print for all).
// (d) Define an instruction block search for birthday month: Print the data of all people who have birthday in that month.
// (e) Define a search instruction block by day and birthday month: Print the data of all people who have birthday on that day and month.
// (f) Define a block of instructions within the person: Insert in alphabetical order of name.
// (g) Defining a block of instructions removes person: Removes all data from that person and moves all the following elements of the vector to the previous position.
// (h) Defining an instruction block prints a schedule with the options:
// • Prints name, phone and email.
// • Print all data.
// (i) The main programmer menu offered according to the options above.

// 24.Fazer um programa para simular uma agenda de telefones. Para cada pessoa devem-se ter os seguintes dados:
// • Nome
// • E-mail
// Enderec¸o (contendo campos para Rua, nu´mero, complemento, bairro, cep, cidade, estado, pa´ıs).
// • Telefone (contendo campo para DDD e nu´mero)
// • Data de aniversa´rio (contendo campo para dia, meˆs, ano).
// • Observac¸o˜es: Uma linha (string) para alguma observac¸a˜o especial.
// (a) Definir a estrutura acima.
// (b) Declarar a varia´vel agenda (vetor) com capacidade de agendar ate´ 100 nomes.
// (c) Definir um bloco de instruc¸o˜es busca por primeiro nome: Imprime os dados da pessoa com esse nome (se tiver mais de uma pessoa, imprime para todas).
// (d) Definir um bloco de instruc¸o˜es busca por meˆs de aniversa´rio: Imprime os dados de todas as pessoas que fazem aniversa´rio nesse meˆs.
// (e) Definir um bloco de instruc¸o˜es busca por dia e meˆs de aniversa´rio: Imprime os dados de todas as pessoas que fazem aniversa´rio nesse dia e meˆs.
// (f) Definir um bloco de instruc¸o˜es insere pessoa: Insere por ordem alfabe´tica de nome.
// (g) Definir um bloco de instruc¸o˜es retira pessoa: Retira todos os dados dessa pessoa e desloca todos os elementos seguintes do vetor para a posic¸a˜o anterior.
// (h) Definir um bloco de instruc¸o˜es imprime agenda com as opc¸o˜es:
// • Imprime nome, telefone e e-mail.
// • Imprime todos os dados.
// (i) O programa deve ter um menu principal oferecendo as opc¸o˜es acima.

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

void add(int c)
{
    int i = c;

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
    scanf("%d", &ag[i].month);

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
    fgets(ag[i].comp, 30, stdin);

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

void print(int i, int p)
{
    printf("\n\nName:%s", ag[i].name);

    printf("E-mail:%s", ag[i].email);

    printf("Telephone:%s", ag[i].tel);

    if (p == 0)
    {

        printf("Obs:%s", ag[i].obs);

        printf("Birth Day:%d", ag[i].day);

        printf("\nBirth Month:%d", ag[i].month);

        printf("\nBirth Year:%d", ag[i].year);

        printf("\nStreet:%s", ag[i].street);

        printf("Number:%d", ag[i].number);

        printf("\nComplement:%s", ag[i].comp);

        printf("Neighborhood:%s", ag[i].nei);

        printf("CEP:%s", ag[i].cep);

        printf("City:%s", ag[i].city);

        printf("State:%s", ag[i].state);

        printf("Country:%s", ag[i].state);
    }
}

void delete (int d, int c)
{
    for (int i = d; i < c; i++)
    {
        strcpy(ag[i].name, ag[i + 1].name);
        strcpy(ag[i].email, ag[i + 1].email);
        strcpy(ag[i].tel, ag[i + 1].tel);
        strcpy(ag[i].obs, ag[i + 1].obs);
        ag[i].day = ag[i + 1].day;
        ag[i].month = ag[i + 1].month;
        ag[i].year = ag[i + 1].year;
        strcpy(ag[i].street, ag[i + 1].street);
        ag[i].number = ag[i + 1].number;
        strcpy(ag[i].comp, ag[i + 1].comp);
        strcpy(ag[i].nei, ag[i + 1].nei);
        strcpy(ag[i].cep, ag[i + 1].cep);
        strcpy(ag[i].city, ag[i + 1].city);
        strcpy(ag[i].state, ag[i + 1].state);
        strcpy(ag[i].country, ag[i + 1].country);
    }
}

void alfa(int c)
{
    int i;

    for (i = 0; i < c; i++)
    {
        if (i > 0)
        {

            printf("%d", strcmp(ag[i - 1].name, ag[i].name));

            if (strcmp(ag[i - 1].name, ag[i].name) > 0)
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
                day = ag[i].day;
                month = ag[i].month;
                year = ag[i].year;
                strcpy(street, ag[i].street);
                number = ag[i].number;
                strcpy(comp, ag[i].comp);
                strcpy(nei, ag[i].nei);
                strcpy(cep, ag[i].cep);
                strcpy(city, ag[i].city);
                strcpy(state, ag[i].state);
                strcpy(country, ag[i].country);

                strcpy(ag[i].name, ag[i - 1].name);
                strcpy(ag[i].email, ag[i - 1].email);
                strcpy(ag[i].tel, ag[i - 1].tel);
                strcpy(ag[i].obs, ag[i - 1].obs);
                ag[i].day = ag[i - 1].day;
                ag[i].month = ag[i - 1].month;
                ag[i].year = ag[i - 1].year;
                strcpy(ag[i].street, ag[i - 1].street);
                ag[i].number = ag[i - 1].number;
                strcpy(ag[i].comp, ag[i - 1].comp);
                strcpy(ag[i].nei, ag[i - 1].nei);
                strcpy(ag[i].cep, ag[i - 1].cep);
                strcpy(ag[i].city, ag[i - 1].city);
                strcpy(ag[i].state, ag[i - 1].state);
                strcpy(ag[i].country, ag[i - 1].country);

                strcpy(ag[i - 1].name, name);
                strcpy(ag[i - 1].email, email);
                strcpy(ag[i - 1].tel, tel);
                strcpy(ag[i - 1].obs, obs);
                ag[i - 1].day = day;
                ag[i - 1].month = month;
                ag[i - 1].year = year;
                strcpy(ag[i - 1].street, street);
                ag[i - 1].number = number;
                strcpy(ag[i - 1].comp, comp);
                strcpy(ag[i - 1].nei, nei);
                strcpy(ag[i - 1].cep, cep);
                strcpy(ag[i - 1].city, city);
                strcpy(ag[i - 1].state, state);
                strcpy(ag[i - 1].country, country);
            }
        }
    }
}

int main()
{

    system("cls");

    int op, i, d, m, c = 0;

    char n[30];

    do
    {
        printf("\n\nSearch by Name:1\nSearch by Month:2\nSearch by Birth:3\nDelete Person:4\nPrint Short:5\nPrint All:6\nAdd Person:7\nAdd Alfa:8");

        fflush(stdin);
        printf("\n\nOperation:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:

            fflush(stdin);
            printf("\nName:");
            fgets(n, 30, stdin);

            for (int i = 0; i < c; i++)
            {

                if (strcmp(n, ag[i].name) == 0)
                {
                    print(i, 0);
                }
            }

            break;

        case 2:

            fflush(stdin);
            printf("\nMonth:");
            scanf("%d", &m);

            for (int i = 0; i < c; i++)
            {

                if (m == ag[i].month)
                {
                    print(i, 0);
                }
            }

            break;

        case 3:

            fflush(stdin);
            printf("\nDay:");
            scanf("%d", &d);

            fflush(stdin);
            printf("\nMonth:");
            scanf("%d", &m);

            for (int i = 0; i < c; i++)
            {

                if (d == ag[i].day && m == ag[i].month)
                {
                    print(i, 0);
                }
            }
            break;

        case 4:

            fflush(stdin);
            printf("\nd:");
            scanf("%d", &d);

            delete (d, c);

            c = c - 1;

            break;

        case 5:

            for (i = 0; i < c; i++)
            {

                print(i, 1);
            }

            break;

        case 6:

            for (i = 0; i < c; i++)
            {

                print(i, 0);
            }
            break;

        case 7:

            add(c);

            c = c + 1;

            break;

        case 8:

            add(c);

            c = c + 1;

            alfa(c);

            break;

        default:
            break;
        }

    } while (op != 0);

    printf("\n\n");

    return 0;
}