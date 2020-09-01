//Num dia de sol, você deseja medir a altura de um prédio, porém, a trena não é suficientemente longa. Assumindo que seja possível medir sua sombra e a do prédio no chão, e que você lembre da sua altura faça um algoritmo para ler os dados necessários e calcular a altura do prédio.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    
    float ae, ap, sp, se;

    printf("Altura do predio\n");

    printf("\nInsira a sua altura:");
    scanf("%f", &ap);

    printf("\nInsira a sua sombra:");
    scanf("%f", &sp);

    printf("\nInsira a sombra do edificio:");
    scanf("%f", &se);

    ae = (ap / sp) * se;

    printf("\nA altura do predio eh de:%0.2f m\n", ae);

    printf("\n\n");

    return 0;
}
