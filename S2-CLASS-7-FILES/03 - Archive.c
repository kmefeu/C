// Escreva um programa para conveter o conteúdo de arquivo texto
// em caracteres maiúsculo. O programa deverá ler do usuário o nome do arquivo a ser convertido
// e o nome do arquivo a ser salvo.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void concatenar ( FILE *base, FILE *copiado);
void limpa_linha();

int main ()
{
    FILE *archive1;
    FILE *archive2;

    char leitor [1000];
    char nome1 [300], nome2 [300];

    printf ("Digite o nome do arquivo origem:\n");
    scanf ("%s", nome1);
    printf ("Digite o nome do destino:\n");
    scanf ("%s", nome2);

    archive1 = fopen (nome1, "r");
    archive2 = fopen(nome2, "w+");

    if (!archive1) {
        printf("Nao foi possivel abrir o de origem!\n");
    }
    while (fgets (leitor, sizeof leitor, archive1) != NULL)
    {
        fputs (strupr(leitor), archive2);
    }
    
    fclose (archive1);
    fclose (archive2);
    return 0;
}
