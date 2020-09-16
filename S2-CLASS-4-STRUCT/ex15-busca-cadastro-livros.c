// Make a program that reads a vector with data from 5 books: title (maximum 30 letters), author (maximum 15 letters) and year. Search for a book by title, asking the user which title to search for. Show data for all books found.

// Fac¸a um programa que leia um vetor com dados de 5 livros: t´ıtulo (ma´ximo 30 letras), autor (ma´ximo 15 letras) e ano. Procure um livro por t´ıtulo, perguntando ao usua´rio qual t´ıtulo deseja buscar. Mostre os dados de todos os livros encontrados.

#include <stdio.h>
#include <string.h>
#define n 5

struct book //livro
{
    char title[30]; // titulo

    char author[15]; // autor

    int year; // ano

} books[n];

int main()
{

    char st[30]; // titulo de busca

    system("cls");

    for (int i = 0; i < n; i++)
    {
        printf("\n\nInsert: Title Author Year\n");
        scanf("%s%s%d", &books[i].title, &books[i].author, &books[i].year);
    }

    printf("\nSearch Title:");
    scanf("%s", &st);

    for (int i = 0; i < n; i++)
    {
        int v = 0;

        for (int ii = 0; ii < strlen(st); ii++)
        {

            if (st[ii] == books[i].title[ii])
            {
                v = v + 1;
            }
            else
            {
                break;
            }
            if (v == strlen(st))
            {

                printf("\nTitle:%s Author: %s Year:%d", books[i].title, books[i].author, books[i].year);
            }
        }
    }

    printf("\n\n");

    return 0;
}