// Faça um programa que leia números positivos e os converta em binário.
// Cada número binário deverá ser salvo em uma linha de um arquivo texto.
// O program termina quando o usuário digitar um número negativo.

#include <stdio.h>

int main()
{

    system("cls");

    FILE *file;
    int numbers;
    char flag = 'x';

    file = fopen("BinareNumbers.txt", "wb");

    if (file == NULL)
    {
        printf("Error to open archive\n");
        system("pause");
        exit(1);
    }
    else
    {
        do
        {
            setbuf(stdin, NULL);
            printf("\nType y to quit\n\n");
            scanf("%c", &flag);

            if (flag == 'y')
            {
                printf("\nQuited\n\n");
                system("pause");
                exit(1);
            }
            else
            {
                printf("\nNumber:");
                scanf("%d", &numbers);

                fwrite(&numbers, sizeof(int), 1, file);
            }

        } while (numbers >= 0);
    }

    printf("\n\n");

    getchar();
    fclose(file);

    return 0;
}