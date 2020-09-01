//Leia um vetor contendo letras de uma frase inclusive os espaços em branco. Retirar os espaços em branco do vetor e depois escreve-los.

#include <stdio.h>
#include <string.h>

int main()
{

    system("cls");

    int i,n;

    char v[20];

    printf("\n\nEscreva uma frase:");
    fgets(v, 20, stdin);

    printf("\n\n%s", v);


    for (i = 0, n = 0; i < strlen(v); i++, n++)
    {

        if (v[n] == ' '){n++;}
        v[i] = v[n];

        printf("\n\nDentro do for dps do if ----->%s", v);
    
    }

    printf("\n\n%s", v);
    printf("\n\n");
}