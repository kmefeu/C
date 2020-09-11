// 6.Make a program that performs the reading of the following data related to a set of students: Registration, Name, Discipline Code, Grade1 and Grade2. Consider a class of up to 10 students. After reading all the data entered, and after storing it in a structure vector, display on the screen the final list of students with their respective final means (use a weighted average: Note1 with weight = 1.0 and Note2 with weight = 2.0).

// 6. Fac¸a um programa que realize a leitura dos seguintes dados relativos a um conjunto de alunos: Matricula, Nome, Co´digo da Disciplina, Nota1 e Nota2. Considere uma turma de ate´ 10 alunos. Apo´s ler todos os dados digitados, e depois de armazena´-los em um vetor de estrutura, exibir na tela a listagem final dos alunos com as suas respectivas me´dias finais (use uma me´dia ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0).
#include <stdio.h>

struct student // estudante
{
    char name[50]; // nome

    int id; // numero de matrícula

    int class; // numero da disciplina

    float ex1; // prova 1

    float ex2; // prova 2

    float finalGrade; // média final

} students[10];

int main()
{

    system("cls");

    int i = 0; // Contador

    for (i = 0; i < 10; i++)
    {
        printf("\n\nStudent %d --> Please insert: Name Id ClassNumber Ex1 Ex2 \n\n", i); // Por favor insira: Nome Id P1 P2 P3

        scanf("%s %d %d %f %f", &students[i].name, &students[i].id, &students[i].class, &students[i].ex1, &students[i].ex2);

        students[i].finalGrade = (students[i].ex1 + (students[i].ex2 * 2)) / 3;
    }

    for (i = 0; i < 10; i++)
    {
        printf("\n\n\nName:%s Id:%d Class:%d \nEx1:%0.2f Ex2:%0.2f \nFinal Grade:%0.2f", students[i].name, students[i].id, students[i].class, students[i].ex1, students[i].ex2, students[i].finalGrade);
    }

    printf("\n\n");
   
    return 0;
}