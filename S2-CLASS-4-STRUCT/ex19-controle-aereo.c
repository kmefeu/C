// 19. Make a program that controls the flow of flights at the airports of a country. With V = 5
// (flights) and A = 5 (airports) and:
// Create and read a vector of flights, with each flight containing an airport code of origin and one of destination.
// Create a vector of airports, with each airport containing its code, number of flights departing and number of flights arriving.
// Note: Each airport is identified by an integer code between 0 and (A-1). Do not accept
// airports with no code.

// 19. Fac¸a um programa que controle o fluxo de voˆos nos aeroportos de um pa´ıs. Com V = 5
// (voˆos) e A = 5 (aeroportos) e:
// Crie e leia um vetor de voos, sendo que cada voo conte´m um co´digo de aeroporto de origem e um de destino.
// Crie um vetor de aeroportos, sendo que cada aeroporto conte´m seu co´digo, quanti- dade de voos que saem e quantidade de voos que chegam.
// Nota: Cada aeroporto e´ identificado por um co´digo inteiro entre 0 e (A-1). Na˜o aceite
// aeroportos de co´digo inexistente.

#include <stdio.h>
#define n 5

struct flight //vôo
{
    int o; // origem // origin
    int d; // destino // destiny
} f[n];

struct airport // aeroporto
{
    int ft; // decolando // flights taking off
    int fl; //  pousando // flights landing

} a[n];

int main()
{

    system("cls");

    int i;

    for (i = 0; i < n; i++)
    {

        f[i].o = i;      // Origem do vôo i
        a[i].ft = i;     // Aeroporto de decolagem i do vôo i
        f[i].d = i + 1;  // Destino i+1
        a[i+1].fl = i; // Aeroporto de pouso i+1

        if (i == n-1) // Ultimo voo pousa no primeiro aeroporto
        {
            f[i].d = 0;
            a[0].fl = i;
        }
    }
    printf("\n\n\t\t-----------FLIGHT CONTROL-----------\n\n");

    for (i = 0; i < n; i++)
    {
        printf("\nFlight:F-%d\nOrigin:A-%d\nDestiny:A-%d\n\n", i, f[i].o, f[i].d);
    }

    printf("\n_____________________________________\n\n");

    for (i = 0; i < n; i++)
    {
        printf("\nAirport:A-%d\nTake-Off:F-%d\nLanding:F-%d\n\n", i, a[i].ft, a[i].fl);
    }

    printf("\n\n");
    return 0;
}
