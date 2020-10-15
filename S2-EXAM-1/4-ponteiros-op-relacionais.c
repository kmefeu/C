#include <stdio.h>

int main()
{
    system("cls");

    //variável de valor
    int valor = 27;

    int valor2 = 17;

    //variável de ponteiro
    int *ptr;

    int *ptr2;

    //atribuindo o endereço da variável de valor a variável de ponteiro
    ptr = &valor;

    ptr2 = &valor2;

    if (*ptr == valor)
    {

        printf("VERDADEIRO: *ptr == valor \n\n");
    }
    else
    {
        printf("FALSO: *ptr == valor \n\n");
    }
    if (ptr < ptr2) //para saber qual ponteiro ocupa a posição mais alta na memória
    {

        printf("RESULTADO: ptr < ptr2 \n\n");
    }
    else
    {
        printf("RESULTADO: ptr > ptr2 \n\n");
    }

    printf("\n\n");

    return (0);
}
