#include <stdio.h>
#include <string.h>

void main()
{

    system("cls");

    char frase[150];

    int ind, cont_a = 0, cont_e = 0, cont_i = 0, cont_o = 0, cont_u = 0;

    printf("Algoritimo de contagem de vogais\n\n");

    printf("Pro favor insira a sua Frase:");

    fgets(frase, 150, stdin);

    for (ind = 0; ind < strlen(frase) - 1; ind++)
    {

        if (frase[ind] == 'a' || frase[ind] == 'A')
        {
            cont_a++;
        }
        if (frase[ind] == 'e' || frase[ind] == 'E')
        {
            cont_e++;
        }
        if (frase[ind] == 'i' || frase[ind] == 'I')
        {
            cont_i++;
        }
        if (frase[ind] == 'o' || frase[ind] == 'O')
        {
            cont_o++;
        }
        if (frase[ind] == 'u' || frase[ind] == 'U')
        {
            cont_u++;
        }
    }
    printf("\n Sua frase contem %i letras A", cont_a);
    printf("\n Sua frase contem %i letras E", cont_e);
    printf("\n Sua frase contem %i letras I", cont_i);
    printf("\n Sua frase contem %i letras O", cont_o);
    printf("\n Sua frase contem %i letras U", cont_u);

    return 0;
}