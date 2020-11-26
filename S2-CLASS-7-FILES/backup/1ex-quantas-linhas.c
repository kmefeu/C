//1) Escreva um programa que leia do usuário o nome de um arquivo texto. Em seguida, mostre na tela quantas linhas esse arquivo possui.

#include <stdio.h>

int main()
{
    int *file;
    int i, ii = 0;
    char c, name[20];

    system("cls");

    printf("\nName of file:");
    scanf("%s", &name);

    // auto add txt in the end of the file
    
    file = fopen(name, "w");

        if (file == NULL)
    {
        printf("Error opening file. System Pause.\n");
        system("pause");
        exit(1);
    }

    for (c = getc(file); c != EOF; c = getc(file))
    {
        if (c == '\n')
        {
            ii++;
        }
    }
    printf("\nFile %s has %d lines.\n",name, ii + 1);
    return 0;
}