#include <stdio.h>
#include <string.h>

struct animal
{
    int id;
    char name[50];  // nome
    char owner[50]; // dono
    int age;        // idade
    float weight;   // peso
    char breed[50]; //raça
} animal[50];

void include(int n)
{
    animal[n].id = n;
    printf("\nId:%d", animal[n].id);
    fflush(stdin);

    printf("\nName:");
    fgets(animal[n].name, 50, stdin);
    fflush(stdin);

    printf("Owner:");
    fgets(animal[n].owner, 50, stdin);

    printf("Age:");
    scanf("%d", &animal[n].age);

    printf("Weight:");
    scanf("%f", &animal[n].weight);
    fflush(stdin);

    printf("Breed:");
    fgets(animal[n].breed, 50, stdin);

    printf("\n\n");
}

void print(int n)
{

    int c = 0;

    for (c = 0; c < n; c++)
    {

        printf("\n\nId: %d", animal[c].id);
        printf("\nName: %s", animal[c].name);
        printf("Age: %d", animal[c].age);
        printf("\nWeight: %0.2f", animal[c].weight);
        printf("\nBreed: %s", animal[c].breed);
    }

    printf("\n\n");
}

void search(int id)

{

    printf("\n\nId: %d", animal[id].id);
    printf("\nName: %s", animal[id].name);
    printf("Age: %d", animal[id].age);
    printf("\nWeight: %0.2f", animal[id].weight);
    printf("\nBreed: %s", animal[id].breed);
}

int main()
{
    system("cls");

    char menu, v = 'n';

    int n = 0;
    int id = 0;

    do
    {
        fflush(stdin);
        printf("/---/ List of Commands /---/\n i = include\n p = print\n s = search\n Max number of Pet's is 50\n\n Command:"); // Lista de comandos / Incluir / Imprimir / Procurar / Número máximo de cadastros pet's igual a 50
        scanf("%c", &menu);

        switch (menu)
        {
        case 'i':

            if (n < 50)
            {
                include(n);
                n = n + 1;
                break;
            }
            else
            {
                printf("You have already reached the largest number of records"); // Você já atingiu o maior númeor de registros
                break;
            }

        case 'p':
            print(n);
            break;

        case 's':

            printf("What is the Id of the animal you want to search\nA:"); // Id do animal que você deseja procurar
            scanf("%d", &id);
            search(id);
            break;

        default:
            break;
        }

        printf("Do you want to leave( y or n)\n A:"); // Você deseja sair (s ou n) ?
        scanf("%c", &v);

        printf("\n\n");

    } while (v != 'y');

    return 0;
}