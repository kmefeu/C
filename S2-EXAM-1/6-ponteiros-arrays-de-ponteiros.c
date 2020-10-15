#include <stdio.h>


int main()
{
    system("cls");

    int v[] = {10, 20, 30}; //vetor

    int v2[] = {40, 50, 60}; //vetor

    int v3[] = {70, 80, 90}; //vetor

    int *ptr[] = {&v[0], &v2[0], &v3[0]}; // ponteiro

    for (int i = 0; i < 3; i++)
    {
        printf("V[%i] = %i\n", i, *(*(ptr + i))); // *(*(pt+0)) é o valor  10;
    }

    printf("\n\n");

    return (0);
}
