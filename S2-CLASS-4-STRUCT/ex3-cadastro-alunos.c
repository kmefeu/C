// 3. Build a student structure with a name, registration number and course. Read the information of 5 students from the user, store this structure in vector and print the data on the screen.

// 3. Construa uma estrutura aluno com nome, nu´mero de matr´ıcula e curso. Leia do usua´rio a informac¸a˜o de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na tela.

#include <stdio.h>

struct student // estudante
{
    char name[50]; // nome

    int id; // numero de matrícula

    char course[20]; // curso

} students[5];

int main()
{

    system("cls");

    int i = 0;

    for (i = 0; i < 5; i++)
    {
        printf("\n\nStudent %d --> Please insert: Name Id Course\n\n", i); // Por favor insira: Nome Id Curso
        scanf("%s%d%s", &students[i].name, &students[i].id, &students[i].course);
    }

    for (i = 0; i < 5; i++)
    {
        printf("\n\nName:%s Id:%d Course:%s", students[i].name, students[i].id, students[i].course);
    }

    printf("\n\n");

    return 0;
}
