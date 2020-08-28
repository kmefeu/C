//Leia um vetor de 5 posições contendo os caracteres de um numero. Em seguida escreva esse numero por extenso.

#include <stdio.h>
#include <string.h>

int main()
{

    system("cls");

    int i,v[5];

    for(i = 0; i < 5 ; i++){
    
    printf("\n\nEscreva um numero V[%i] = ",i);
    scanf("%d", &v[i]);

    }

    printf("\n\n%s", v);

    for (i = 0; i < 5; i++)
    {

        if (v[i] == 0 ){printf("zero,");}
        if (v[i] == 1 ){printf("um,");}
        if (v[i] == 2 ){printf("dois,");}
        if (v[i] == 3 ){printf("tres,");}
        if (v[i] == 4 ){printf("quatro,");}
        if (v[i] == 5 ){printf("cinco,");}
        if (v[i] == 6 ){printf("seis,");}
        if (v[i] == 7 ){printf("sete,");}
        if (v[i] == 8 ){printf("oito,");}
        if (v[i] == 9 ){printf("nove,");}
        
    
    }

    
    printf("\n\n");
}