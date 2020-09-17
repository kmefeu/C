// 18. Make a program that manages the stock of a market and:
// Create and read a vector of 5 products, with the data: code (integer), name (maximum 15 letters), price and quantity.
// Read an order, consisting of a product code and quantity. Locate this code in the vector and, if there is enough quantity to fulfill the order in full, update the stock and inform the user. Repeat this process until you read a code equal to zero.
// If for some reason it is not possible to fulfill the request, display a message stating which error occurred.

// 18. Fac¸a um programa que gerencie o estoque de um mercado e:
// Crie e leia um vetor de 5 produtos, com os dados: co´digo (inteiro), nome (ma´ximo 15 letras), prec¸o e quantidade.
// Leia um pedido, composto por um co´digo de produto e a quantidade. Localize este co´digo no vetor e, se houver quantidade suficiente para atender ao pedido integralmente, atualize o estoque e informe o usua´rio. Repita este processo ate´ ler um co´digo igual a zero.
// Se por algum motivo na˜o for poss´ıvel atender ao pedido, mostre uma mensagem infor- mando qual erro ocorreu.

#include <stdio.h>
#define n 2

struct produts
{
    int id; // código

    float price; // preço

    int quantity; // quantidade
} pd[n];

int main()
{

    system("cls");

    int i, sId, sQt;

    for (i = 0; i < n; i++)
    {
        pd[i].id = i;

        printf("\nInsert:Id:%d Price Quantity:", pd[i].id);
        scanf("%f %d", &pd[i].price, &pd[i].quantity);
    }

    do
    {
        printf("\n\nId Quantity:");
        scanf("%d %d", &sId, &sQt);

        if (pd[sId].id == sId)
        {

            if (pd[sId].quantity >= sQt)
            {
                printf("\nId:%d R$:%0.2f x %d = %0.2f", pd[sId].id, pd[sId].price, sQt, sQt * pd[sId].price);
                pd[sId].quantity = pd[sId].quantity - sQt;
            }
            else
            {
                printf("\nNot enough stock"); // Estoque insuficiente
            }
        }
        else
        {
            printf("\nItem not found"); // Item não achado
        }

    } while (sQt != 0);

    return 0;
}