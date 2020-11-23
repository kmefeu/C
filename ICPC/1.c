#include <stdio.h>

int main()
{

    float n, a, b, r, rt, rmin, rmax;

    printf("\n\nTotal(N).Minimo(A).Maximo(B).\n\n");

    scanf("%f %f %f", &n, &a, &b);

    rmin = n / a;

    rmax = n / b;

    for (int i = 0; i < n; i++)
    {  
        r = n / (n - i);
        rt = rt + r;
    }

    printf("\n\nN Esperado |%f", rt);

    printf("\n\nTotal(N) = |%f\n\nMinimo(A) = |%f\n\nMaximo(B) = |%f \n\n rmin = %f\n\n rmax = %f", n, a, b, rmin, rmax);

    return 0;
}