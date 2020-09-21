// Write a program that receives two dma-type structs, each representing a valid date, and calculate the number of days that have elapsed between the two dates.

// Escreva um programa que receba dois structs do tipo dma, cada um representando uma data válida, e calcule o número de dias que decorreram entre as duas datas.

#include <stdio.h>

struct date // data
{
    int day; // dia

    int month; // mês

    int year; // ano

} date[3];

int main()
{

    system("cls");

    int i;

    for (i = 0; i < 2; i++)
    {
        printf("DATE %d\n",i);

        printf("Day:");
        scanf("%d", &date[i].day);

        printf("Month:");
        scanf("%d", &date[i].month);

        printf("Year:");
        scanf("%d", &date[i].year);

        printf("\n\n");
    }

    date[3].day = date[1].day - date[0].day;
    date[3].month = date[1].month - date[0].month;
    date[3].year = date[1].year - date[0].year;

    printf("%d days %d months %d years", date[3].day, date[3].month, date[3].year);

    printf("\n\n");

    return 0;
}