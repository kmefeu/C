//https: //www.geeksforgeeks.org/solve-dynamic-programming-problem/

// this function returns the number of
// arrangements to form 'n'

main()
{
    int number, slice;

    // initialize to -1
    int dp[99];

    for (int i = 0; i < 99; i++)
        dp[i] = -1;

    printf("Inteiro a particionar:");
    scanf("%d", &number);

    slice = solve(number);
    printf("\n\nResultado:%d", slice);

    // this function returns the number of
    // arrangements to form 'n'
    int solve(int n)
    {
        // base case
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;

        // checking if already calculated
        if (dp[n] != -1)
            return dp[n];

        // storing the result and returning
        return dp[n] = solve(n - 1) + solve(n - 3) + solve(n - 5);
    }
}