// 21. Make a program that stores films produced by several directors and:
// • Create and read a vector of 5 directors, each containing a name (maximum 20 letters),
// number of films and films. The member films is a vector, which must be created
// after having read a number of films. Each film is composed by name, year and duration. Look for a director by name, showing all the films he has produced. Repeat the process until you type an empty string.

// 21. Fac¸a um programa que armazena filmes produzidos por va´rios diretores e:
// • Crie e leia um vetor de 5 diretores, cada um contendo nome (máximo 20 letras),
// quantidade de filmes e filmes. O membro filmes e´ um vetor, que deve ser criado
// apo´s ter lido quantidade de filmes. Cada filme e´ composto por nome, ano e duração. Procure um diretor por nome, mostrando todos os filmes que ele ja´ produziu. Repita o processo ate´ digitar uma string vazia.

#include <stdio.h>
#define n 5

struct directors
{
    char name[20]; // nome

    int nF; // numero de filmes

    struct films
    {
        char name[20];

        char year[4];

        char time[5];

    } films[100];

} d[n];

int main()
{
    system("cls");

    int i;

    d[n].f = &films;

    for (i = 0; i < n; i++)
    {
        printf("Insert: Director NumberOfFilms");
        scanf("%s %d", &d[i].name, &d[i].nFilms);
    }

    for (i = 0; i < n; i++)
    {
        nm[i] = d[i].nFilms;
    }

    struct films films[nm[i]];

    printf("\n\n");

    return 0;
}