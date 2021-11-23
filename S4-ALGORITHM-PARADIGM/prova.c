int floyd()
{
    int n = 10;
    int A[10][10];
    int D[10][10];
    int R[10][10];
    // contar a partir daqui
    for (int i = 1; i < n; i++) // 1+(1*n) +(2*(n-1))
    {
        for (int j = 1; j < n; j++) // 1+(1*n) +(2*(n-1))
        {
            A[i, j] = D[i, j]; // 5*n*n
            R[i, j] = 0;       //3*n*n
        }
    }
    for (int i; i < n; i++) // 1+(1*n) +(2*(n-1))
    {
        A[i, i] = 0; // 3*n
    }
    for (int k = 1; k < n; k++) // 1+(1*n) +(2*(n-1))
    {
        for (int i = 1; i < n; i++) // 1+(1*n) +(2*(n-1))
        {
            for (int j = 1; j < n; j++) // 1+(1*n) +(2*(n-1))
            {

                if ((A[i, k] + A[k, j]) < A[i, j]) // 9*n*n*n
                {
                    A[i, j] = A[i, k] + A[k, j]; // 8*n*n*n
                    R[i, j] = k;                 // 3*n*n*n
                }
            }
        }
    }
}

// 6*(1+(1*n) +(2*(n-1)))+ 5*n*n + 3*n*n +  3*n + 9*n*n*n + 8*n*n*n + 3*n*n*n
// 6*(1+(1*n) +(2*(n-1)))+ 5n^2 +3n^2 +3n + 9n^3 + 8n^3 + 3n^3
// 6*(1+n+2n-2) + 8n^2 + 3n + 20n^3
// 6*(3n-1) + 8n^2 + 3n + 20n^3
// 18n-6 + 8n^2 + 3n + 20n^3
//20n^3+8n^2+21n-6