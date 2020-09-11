// Make a program that stores in a data record (compound structure) the data of a company employee, composed of: Name, Age, Sex (M / F), CPF, Date of Birth, Co Code of the Sector where he works (0-99), Position he occupies (string of up to 30 characters) and Room. The data must be entered by the user, stored in the structure and displayed on the screen.

// Fac¸a um programa que armazene em um registro de dados (estrutura composta) os da- dos de um funciona´rio de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF, Data de Nascimento, Co´digo do Setor onde trabalha (0-99), Cargo que ocupa (string de ate´ 30 caracteres) e Sala´rio. Os dados devem ser digitados pelo usua´rio, armazenados na estrutura e exibidos na tela.

#include <stdio.h>

struct employee
{

    char name[50]; // nome

    int age; // idade

    char sex; // sexo

    char cpf[11]; // CPF

    float salary; // salario

    char birth[10]; // data de nascimento

    int sector; // Setor

    char role[30]; // cargo

} emp;

int main()
{

    system("cls");

    printf("\n\nInsert: Name Age Sex(M or F) CPF Salary Birth (DD/MM/YYYY) Sector (00-99) Role \n\n"); // Insira: Dados

    scanf("%s %d %c %s %f %s %d %s", &emp.name, &emp.age, &emp.sex, &emp.cpf, &emp.salary, &emp.birth, &emp.sector, &emp.role);

    printf("\n\nName:%s\nAge:%d\nSex:%c\nCPF:%s\nSalary:%0.2f\nBirth:%s\nSector:%d\nRole:%s", emp.name, emp.age, emp.sex, emp.cpf, emp.salary, emp.birth, emp.sector, emp.role);

    printf("\n\n");

    return 0;
}