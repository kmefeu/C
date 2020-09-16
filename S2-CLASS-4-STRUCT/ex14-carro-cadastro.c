// Make a program that reads a vector with the data of 5 cars: brand (maximum 15 letters), year and price. Read a p-value and show the information for all cars with a price less than p. Repeat this process until a p = 0 value is read.

// Fac¸a um programa que leia um vetor com os dados de 5 carros: marca (ma´ximo 15 letras), ano e prec¸o. Leia um valor p e mostre as informac¸o˜es de todos os carros com prec¸o menor que p. Repita este processo ate´ que seja lido um valor p = 0.

#include <stdio.h>
#define n 1

struct car // carro
{
    char brand[15]; // marca

    char year[4]; // ano

    float price; // preço
} cars[n];

int main()
{
    system("cls");

    float p;

    for (int i = 0; i < n; i++)
    {
        printf("\nInsert: Brand Year Price\n");
        scanf("%s%s%f", &cars[i].brand, &cars[i].year, &cars[i].price);
    }

    do
    {
        printf("\nSearch Price: "); // Preço de consulta
        scanf("%f", &p);

        for (int i = 0; i < n; i++)
        {
            if (cars[i].price < p)
            {
                printf("\nBrand:%s Year:%s R$%f", cars[i].brand, cars[i].year, cars[i].price);
            }
        }

    } while (p != 0);

    printf("\n\n");
    
    return 0;
}