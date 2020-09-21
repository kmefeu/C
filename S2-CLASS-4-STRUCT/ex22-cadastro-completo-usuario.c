// 22. Define the structure whose graphical representation is given below, define the fields with the necessary basic types.

// (a) Create a master vector with 5 elements.
// (b) Allow the user to enter data to complete these 5 entries.
// (c) Find the oldest person among those registered
// (d) Find male people
// (e) Find people with a salary greater than 1000.
// (f) Print the data of the person whose identity is equal to a value provided by the user

// 22. Definir a estrutura cuja representação gráfica é dada a seguir, definir os campos com os tipos ba´sicos necessários.

// (a) Crie um vetor Cadastro com 5 elementos.
// (b) Permita ao usuário entrar com dados para preencher esse 5 cadastros.
// (c) Encontre a pessoa com maior idade entre os cadastrados
// (d) Encontre as pessoas do sexo masculino
// (e) Encontre as pessoas com salário maior que 1000.
// (f) Imprima os dados da pessoa cuja identidade seja igual a um valor fornecido pelo usuário


#include <stdio.h>
#define n 5

struct info
{
    char name[21]; // nome

    float salary; // salario

    int rg; //RG

    char cpf[15]; // CPF

    char civil; // civil state

    char telephone[20]; // telefone

    int age; // idade

    char sex; // sexo

    struct addres
    {
        char street[31]; // rua

        char neighborhood[31]; // bairro

        char city[31]; // cidade

        char state[31]; // estado

        char cep[14]; // CEP
    };

} inf[n];

int main()
{

    system("cls");

    int i, rgs = 1;

    for (i = 0; i < n; i++)
    {

        fflush(stdin);
        printf("\nName:");
        fgets(inf[i].name, 21, stdin);

        fflush(stdin);
        printf("\nSalary:");
        scanf("%f", &inf[i].salary);

        fflush(stdin);
        printf("\nRG:");
        scanf("%d", &inf[i].rg);

        fflush(stdin);
        printf("\nCPF:");
        fgets(inf[i].cpf, 15, stdin);

        fflush(stdin);
        printf("\nMaritalStatus(s, m, d):");
        scanf("%c", &inf[i].civil);

        fflush(stdin);
        printf("\nTelephone:");
        fgets(inf[i].telephone, 20, stdin);

        fflush(stdin);
        printf("\nAge:");
        scanf("%d", &inf[i].age);

        fflush(stdin);
        printf("\nSex (m or f):");
        scanf("%c", &inf[i].sex);

        fflush(stdin);
        printf("\nStreet:");
        fgets(inf[i].street, 31, stdin);

        fflush(stdin);
        printf("\nNeighborhood:");
        fgets(inf[i].neighborhood, 31, stdin);

        fflush(stdin);
        printf("\nCity:");
        fgets(inf[i].city, 31, stdin);

        fflush(stdin);
        printf("\nState:");
        fgets(inf[i].state, 31, stdin);

        fflush(stdin);
        printf("\nCEP:");
        fgets(inf[i].cep, 31, stdin);
    }

    for (i = 0; i < n; i++)
    {

        if (inf[i].sex == 'm')
        {
            printf("\n\n--MALE-DETECTED--");

            printf("\nName:%sSalary:%0.2f\nRG:%d\nCPf:%sMaritalStatus:%c", inf[i].name, inf[i].salary, inf[i].rg, inf[i].cpf, inf[i].civil);
            printf("\nTelephone:%sAge:%d\nSex:%c", inf[i].telephone, inf[i].age, inf[i].sex);
            printf("\nStreet:%sNeighborhood:%sCity:%sState:%sCEP:%s", inf[i].street, inf[i].neighborhood, inf[i].city, inf[i].state, inf[i].cep);
        }

        if (inf[i].salary > 1000)
        {
            printf("\n\n--SALARY-OVER-1000--");

            printf("\nName:%sSalary:%0.2f\nRG:%d\nCPf:%sMaritalStatus:%c", inf[i].name, inf[i].salary, inf[i].rg, inf[i].cpf, inf[i].civil);
            printf("\nTelephone:%sAge:%d\nSex:%c", inf[i].telephone, inf[i].age, inf[i].sex);
            printf("\nStreet:%sNeighborhood:%sCity:%sState:%sCEP:%s", inf[i].street, inf[i].neighborhood, inf[i].city, inf[i].state, inf[i].cep);
        }
    }

    do
    {

        fflush(stdin);
        printf("\nSearch by RG:");
        scanf("%d", &rgs);

        for (i = 0; i <= n; i++)
        {
            if (rgs == inf[i].rg && rgs != 0)
            {

                printf("\n\n--USER-FOUND--\n");
               
               printf("\nName:%sSalary:%0.2f\nRG:%d\nCPf:%sMaritalStatus:%c", inf[i].name, inf[i].salary, inf[i].rg, inf[i].cpf, inf[i].civil);
            printf("\nTelephone:%sAge:%d\nSex:%c", inf[i].telephone, inf[i].age, inf[i].sex);
            printf("\nStreet:%sNeighborhood:%sCity:%sState:%sCEP:%s", inf[i].street, inf[i].neighborhood, inf[i].city, inf[i].state, inf[i].cep);
            }
        }

    } while (rgs != 0);

    printf("\n\n");

    return 0;
}