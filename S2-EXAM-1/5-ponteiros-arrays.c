#include <stdio.h>

int main()
{
    system("cls");

    int v[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90}; //vetor

    int i; // contador

    int n; // edereço alvo

    int *ptr; // ponteiro

    ptr = &v[0]; //atribui o endereço do vetor no ponteiro

    printf("\nn:");
    scanf("%i", &n);

    printf("V[%i] = %i\n", n, *(ptr + n));  //*(pt + i) é igual a V[i]. // (pt + i) é igual a &V[i].

    printf("\n\n");

    for (i = 0; i < 10; i++)
    {
        printf("V[%i] = %i\n", i,*(ptr + i));
    }

    printf("\n\n");

    return (0);
}
