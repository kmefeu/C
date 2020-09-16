// 11. Make a program that reads the data of 10 students (Name, registration, Final Average), storing in a vector. Once the data has been read, divide this data into 2 new vectors, the vector of the approved and the vector of the disapproved, considering the minimum mean for the approval to be 5.0. Display on the screen the data of the approved vector, followed by the data of the failed vector.

// 11. Fac¸a um programa que leia os dados de 10 alunos (Nome, matricula, Me´dia Final), arma- zenando em um vetor. Uma vez lidos os dados, divida estes dados em 2 novos vetores, o vetor dos aprovados e o vetor dos reprovados, considerando a me´dia m´ınima para a aprovac¸a˜o como sendo 5.0. Exibir na tela os dados do vetor de aprovados, seguido dos dados do vetor de reprovados.

#include <stdio.h>
#define n 2

struct student
{
    char name[20]; // nome

    char enrollment[20]; // matricula

    float finalGrade; // média final

} students[n], pass[n], fail[n];

int main()
{
    int i = 0;

    for (i = 0; i < n; i++) // Entrada de dados // Input of data
    {

        printf("\n\nInsert: Name Enrollment FinalGrade\n");
        scanf("%s%s%f", &students[i].name, &students[i].enrollment, &students[i].finalGrade);

        if (students[i].finalGrade < 5)
        {
            fail[i] = students[i];
        }
        else
        {
            pass[i] = students[i];
        }
    }

    printf("\n\nInsert: Name Enrollment FinalGrade\n");

    for (i = 0; i < n; i++) // Entrada de dados // Input of data
    {

        if (students[i].finalGrade < 5)
        {
            printf("\n\nResult: FAIL Name:%s\nEnrrolment:%s \nFinalGrade:%0.2f", fail[i].name, fail[i].enrollment, fail[i].finalGrade);
        }
        else
        {
            printf("\n\nResult: PASS Name:%s\nEnrrolment:%s \nFinalGrade:%0.2f", pass[i].name, pass[i].enrollment, pass[i].finalGrade);
        }
    }

    printf("\n\n");

    return 0;
}