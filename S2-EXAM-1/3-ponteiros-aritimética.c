#include <stdio.h>

int main()
{
    system("cls");

    //variável de valor
    int valor = 27;

    //variável de ponteiro
    int *ptr;

    //atribuindo o endereço da variável de valor a variável de ponteiro
    ptr = &valor;

    *ptr = *ptr + 17; //( valor = valor - 17) => (valor = 27 -17) => (valor = 10)

    // também é válido usar qualquer outro operador (Soma, multiplicação, divisão, incremento ++, decremento -- ...)

    printf("Utilizando ponteiros:\n\n");
    printf("\nConteudo da variavel valor: %d", valor);
    printf("\nEndereco da variavel valor: %p ", &valor);
    printf("\nConteudo da variavel ponteiro ptr: %p", ptr);
    printf("\nReferencia da variavel ponteiro ptr: %d", *ptr);

    printf("\n\n");

    return (0);
}
