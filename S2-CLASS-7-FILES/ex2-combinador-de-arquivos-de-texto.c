// Escreva um programa que leia do usuário os nomes de dois arquivos texto.
// Crie um terceiro arquivo texto com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido do segundo).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    
    system("cls");
    
    FILE *file1, *file2, *file3;
    char fileName1[100], fileName2[100];
    
    printf("\nFile - 1:");
    scanf("%s", &fileName1);
    strcat(fileName1, ".txt");

    printf("\nFile -2:");
    scanf("%s", &fileName2);
    strcat(fileName2, ".txt");
    
    file1 = fopen(fileName2, "r");
    file2 = fopen(fileName1, "r");
    file3 = fopen("BindedFiles.txt", "w");
    
    if (file1 == NULL || file2 == NULL || file3 == NULL)
    {
        printf("Error to open archive\n");
        system("pause");
        exit(1);
    }
    char letter;
    
    while ((letter = fgetc(file1)) != EOF)
    {
        fprintf(file3, "%c", letter);
    }
    
    while ((letter = fgetc(file2)) != EOF)
    {
        fprintf(file3, "%c", letter);
    }
   
    fclose(file1);
    fclose(file2);
    fclose(file3);
    
    return 0;
}