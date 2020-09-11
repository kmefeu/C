#include <stdio.h>

struct animal
{
    int id;
    char name[50];  // nome
    char owner[50]; // dono
    int age;        // idade
    float weight;   // peso
    char breed[50]; // raça
} animal;

int main()
{

    system("cls");

    printf("\nId:");
    scanf("%d", &animal.id);
    fflush(stdin);

    printf("Name:");
    fgets(animal.name, 50, stdin);
    fflush(stdin);

    printf("Owner:");
    fgets(animal.owner, 50, stdin);

    printf("Age:");
    scanf("%d", &animal.age);

    printf("Weight:");
    scanf("%f", &animal.weight);
    fflush(stdin);

    printf("Breed:");
    scanf("%s", &animal.breed);

    printf("\n\nId: %d", animal.id);
    printf("\nName: %s", animal.name);
    printf("Age: %d", animal.age);
    printf("\nWeight: %0.2f", animal.weight);
    printf("\nBreed: %s", animal.breed);

    printf("\n\n");

    return 0;
}