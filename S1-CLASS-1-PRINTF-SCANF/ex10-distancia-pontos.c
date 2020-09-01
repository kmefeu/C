//Algoritimo de calculo de distancia entre pontos

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");

    int n1, n2, m1, m2, w1, w2;

    printf("Digite respectivamente os valores de x e y do primeiro ponto\n\n");
    
    printf("P1 X:");
    scanf("%i", &n1);
    
    printf("\nP1 Y:");
    scanf("%i", &n2);

    printf("\n\nDigite respectivamente os valores de x e y do segundo ponto\n\n");

    printf("P2 X:");
    scanf("%i", &m1);
   
    printf("\nP2 Y:");
    scanf("%i", &m2);

    w1 = m1 - n1;

    w2 = m2 - n2;

    printf("\nA distancia entre os pontos x e y1 eh de :(%i,%i)\n", w1, w2);

    printf("\n\n");

    return 0;
}
