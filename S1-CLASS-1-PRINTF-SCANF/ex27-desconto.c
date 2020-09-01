#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    
    float p, pd;
    
    printf("Calculo de desconto de 10%%: ");
    scanf("%f", &p);

    pd = (p - (p * 0.1));

    printf("Preco com desconto :%0.2f", pd);

    printf("\n\n");

    return 0;
}
