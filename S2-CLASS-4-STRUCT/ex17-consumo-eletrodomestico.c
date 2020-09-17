// 17. Make a program that controls the energy consumption of home appliances and:
// Create and read 5 electrical appliances that contain name (maximum 15 letters), power (real, in kW) and active time per day (real, in hours).
// Read a time t (in days), calculate and show the total consumption in the house and the relative consumption of each electrode (total consumption / consumption) in that period of time. Present this last data as a percentage.

// 17. Fac¸a um programa que controla o consumo de energia dos eletrodome´sticos de uma casa e:
// Crie e leia 5 eletrodome´sticos que conte´m nome (ma´ximo 15 letras), poteˆncia (real, em kW) e tempo ativo por dia (real, em horas).
// Leia um tempo t (em dias), calcule e mostre o consumo total na casa e o consumo relativo de cada eletrodome´stico (consumo/consumo total) nesse per´ıodo de tempo. Apresente este u´ltimo dado em porcentagem.

#include <stdio.h>
#define n 5

struct divices // aparelhos ou dispositivos
{
    char name[15]; // nome

    float power; // potencia

    float use; // uso

    float consume; // consumo
} dv[n];

int main()
{
    system("cls");

    int days, i; // dias

    for (i = 0; i < n; i++)
    {
        printf("\nInsert: Divice Power(kw) Use(h):");
        scanf("%s %f %f", &dv[i].name, &dv[i].power, &dv[i].use);
    }

    printf("\nDays:");
    scanf("%d", &days);

    for (i = 0; i < n; i++)
    {
        dv[i].consume = dv[i].power * dv[i].use * days;
    }

    for (i = 0; i < n; i++)
    {

        printf("\n\n%s %0.2fkw \nUse:%0.2fh\nConsume:%0.2fkw", dv[i].name, dv[i].power, dv[i].use, dv[i].consume);
    }

    printf("\n\n");

    return 0;
}