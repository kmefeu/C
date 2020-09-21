// 21. Make a program that stores films produced by several directors and:
// • Create and read a vector of 5 directors, each containing a name (maximum 20 letters),
// number of films and films. The member films is a vector, which must be created
// after having read a number of films. Each film is composed by name, year and duration. Look for a director by name, showing all the films he has produced. Repeat the process until you type an empty string.

// 21. Faça um programa que armazena filmes produzidos por vários diretores e:
// • Crie e leia um vetor de 5 diretores, cada um contendo nome (máximo 20 letras),
// quantidade de filmes e filmes. O membro filmes é um vetor, que deve ser criado
// após ter lido quantidade de filmes. Cada filme é composto por nome, ano e duração. Procure um diretor por nome, mostrando todos os filmes que ele já produziu. Repita o processo até digitar uma string vazia.

#include <stdio.h>
#include <string.h>
#define n 1

struct directors
{

    char name[21]; // nome

    int nf; // numero de filmes

    struct // filmes
    {
        char namef[21]; // nome

        int year; // ano

        char time[6]; //tempo

    } movies[100];

} d[n];

int main()
{
    system("cls");

    int i, ii;

    char ns[21];

    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("\nDirector %d name:", i);
        fgets(d[i].name, 21, stdin);

        fflush(stdin);
        printf("\nDirector %d Number Movies:", i);
        scanf("%d", &d[i].nf);

        for (ii = 0; ii < d[i].nf; ii++)
        {
            fflush(stdin);
            printf("\nMovie %d Name:", ii);
            fgets(d[i].movies[ii].namef, 21, stdin);

            fflush(stdin);
            printf("\nMovie %d Year:", ii);
            scanf("%d", &d[i].movies[ii].year);

            fflush(stdin);
            printf("\nMovie %d Duration:", ii);
            fgets(d[i].movies[ii].time, 6, stdin);
        }
    }

    do
    {
        printf("\nSearch director by name:");
        fgets(ns, 21, stdin);

        for (i = 0; i < n; i++)
        {

            if (strcmp(ns, d[i].name) == 0)
            {
                printf("\nDirector:%s", d[i].name);

                for (ii = 0; ii < d[i].nf; ii++)
                {
                    printf("\nMovie:%s", d[i].movies[ii].namef);

                    printf("Year:%d", d[i].movies[ii].year);

                    printf("\nDuration:%s", d[i].movies[ii].time);
                }
            }
        }
    } while (strlen(ns) > 1);

    printf("\n\n");

    return 0;
}