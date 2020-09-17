//16. Make a program that is an agenda of commitments and:
// Create and read a vector of 5 data structures with: commitment (maximum 60 letters) and date. The date must be another data structure containing day, month and year.
// Read two integers M and A and show all commitments of month M of year A. Repeat the procedure until you read M = 0.

// 16. Fac¸a um programa que seja uma agenda de compromissos e:
// Crie e leia um vetor de 5 estruturas de dados com: compromisso (ma´ximo 60 letras) e data. A data deve ser outra estrutura de dados contendo dia, meˆs e ano.
// Leia dois inteiros M e A e mostre todos os compromissos do meˆs M do ano A. Repita o procedimento ate´ ler M = 0.

#include <stdio.h>
#include <string.h>
#define n 3

struct date // data
{
    int month, year; // mes, ano
};

struct commitment
{
    char des[60]; // descrição

    struct date dt;

} cmt[n];

int main()
{

    system("cls");

    int ms = 0, ys = 0, i;

    for (i = 0; i < n; i++)
    {
        printf("\nInsert: Commitments Month Year\n");
        scanf("%s %d %d", &cmt[i].des, &cmt[i].dt.month, &cmt[i].dt.year);
    }
    do
    {
        fflush(stdin);
        printf("\n\nSearch Date: MM YYYY: ");
        scanf("%d %d", &ms, &ys);

        for (i = 0; i < n; i++)
        {
            if (cmt[i].dt.year == ys)
            {
                if (cmt[i].dt.month == ms)
                {
                    printf("\n%s %d %d", cmt[i].des, cmt[i].dt.month, cmt[i].dt.year);
                }
            }
        }

    } while (ms != 0);

    printf("\n\n");

    return 0;
}
