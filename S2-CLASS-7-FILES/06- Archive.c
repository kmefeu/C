// Faça um programa que leia um arquivo texto contendo uma lista de compras.
// Cada linha do arquivo possui o nome, quantidade e valor unitário do produto.
// O programa então exibe o total da compra.

#include <stdio.h>
#include <stdlib.h>
void main()
{

    system("cls");

    typedef struct stcGoods
    {
        char name[100];
        int amount;
        float price;

    } goods;

    FILE *file = fopen("list.txt", "a+b");

    int result;

    if (file == NULL)
    {
        printf("Error opening file. System Pause.\n");
        system("pause");
        exit(1);
    }
    goods item;

    printf("--Shopping list--\n");
    printf("\nitem Name:");
    fgets(item.name, 99, stdin);

    printf("\nAmount:");
    scanf("%d", &item.amount);

    printf("\nPrice:");
    scanf("%f", &item.price);

    result = fwrite(&item, sizeof(goods), 1, file);

    if (result == EOF)
    {
        printf("Error registering item\n");
    }

    fclose(file);

   file = fopen("list.txt", "r+b");

    if (file == NULL)
    {
        printf("Error opening file. System Pause.\n");
        system("pause");
        exit(1);
    }

    printf("\n\n");

    while (!feof(file))
    {
        fread(&item, sizeof(item), 1, file);

        if (feof(file))
        {
            break;
        }

        printf("\nItem:%sAmount:%d\nPrice:%.2f\n\n", item.name, item.amount, item.price);
    }

    fclose(file);
    return 0;
}