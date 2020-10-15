#include <stdio.h>

int main()
{
    system("cls");

    int *ponteiro;
    int **ponteiroDoPonteiro;
    int valor = 50;

    ponteiro = &valor;

    ponteiroDoPonteiro = &ponteiro;

    printf("\nValor de ponteiroDoPonteiro: %p", ponteiroDoPonteiro);
    printf("\nEndereco de memoria de ponteiro: %p", &ponteiro);
    printf("\nValor de ponteiro: %p", ponteiro);
    printf("\nEndereco de memoria de valor: %p", &valor);
    printf("\nvalor: %d", valor);
    printf("\n*ponteiro: %d", *ponteiro);
    printf("\n**ponteiroDoPonteiro: %d", **ponteiroDoPonteiro);


    printf("\n\n");

    return (0);
}
