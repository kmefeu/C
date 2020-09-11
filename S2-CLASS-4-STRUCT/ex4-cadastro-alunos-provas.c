// 4. Create a structure representing the students of a given course. The structure must contain the student's registration, name, grade of the first exam, grade of the second exam and grade of the third exam.
// (a) Allow the user to enter data for 5 students.
// (b) Find the student with the highest score in the first test.
// (c) Find the student with the highest overall score.
// (d) Find the student with the lowest overall average
// (e) For each student, say whether he passed or failed, considering the value 6 for approval.

// 4. Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matricula do aluno, nome, nota da primeira prova, nota da segunda prova e nota da terceira prova.
// (a) Permita ao usua´rio entrar com os dados de 5 alunos.
// (b) Encontre o aluno com maior nota da primeira prova.
// (c) Encontre o aluno com maior me´dia geral.
// (d) Encontre o aluno com menor me´dia geral
// (e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovac¸a˜o.

#include <stdio.h>

struct student // estudante
{
    char name[50]; // nome

    int id; // numero de matrícula

    float ex1; // prova 1

    float ex2; // prova 2

    float ex3; // prova 3

    float finalGrade; // média final

} students[5];

int main()
{

    system("cls");

    int i = 0; // Contador

    float bestGrade, worstGrade, bestEx1; // Melhor nota, Pior nota

    for (i = 0; i < 5; i++)
    {
        printf("\n\nStudent %d --> Please insert: Name Id Ex1 Ex2 Ex3\n\n", i); // Por favor insira: Nome Id P1 P2 P3

        scanf("%s %d %f %f %f", &students[i].name, &students[i].id, &students[i].ex1, &students[i].ex2, &students[i].ex3);

        students[i].finalGrade = (students[i].ex1 + students[i].ex2 + students[i].ex3)/3;

        if (i == 0)
        {
            bestGrade = students[i].finalGrade;
            worstGrade = students[i].finalGrade;
            bestEx1 = students[i].ex1;
        }

        if (i != 0 && students[i].finalGrade > bestGrade)
        {
            bestGrade = students[i].finalGrade;
        }

        if (i != 0 && students[i].finalGrade < worstGrade)
        {
            worstGrade = students[i].finalGrade;
        }

        if (i != 0 && students[i].ex1 >bestEx1)
        {
            bestEx1 = students[i].ex1;
        }
    }

    for (i = 0; i < 5; i++)
    {
        printf("\n\n\nName:%s Id:%d \nEx1:%0.2f Ex2:%0.2f Ex3:%0.2f \nFinal Grade:%0.2f", students[i].name, students[i].id, students[i].ex1, students[i].ex2, students[i].ex3, students[i].finalGrade);

        if (students[i].finalGrade < 6)
        {

            printf("\n%s Result: Not Pass", students[i].name); // Não Passou
        }

        else
        {

            printf("\n%s Result: Pass", students[i].name); // Passou
        }
    }

    printf("\n\nBest Final Grade: %0.2f", bestGrade); // Melhor média Final

    printf("\n\nWorst Final Grade: %0.2f", worstGrade); // Pior média Final

    printf("\n\nBest Ex1 Grade: %0.2f", bestEx1); // Melhor Nota P1

    printf("\n\n");

    return 0;
}
