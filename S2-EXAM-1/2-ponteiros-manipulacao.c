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

    printf("Utilizando ponteiros:\n\n");
    printf("\nConteudo da variavel valor: %d", valor);
    printf("\nEndereco da variavel valor: %p ", &valor);
    printf("\nConteudo da variavel ponteiro ptr: %p", ptr);
    printf("\nReferencia da variavel ponteiro ptr: %d", *ptr);

    printf("\n\n");

    return (0);
}
