//Partição de Númerointeiros positivos
main()
{
    int number, maxSlices, slice;

    printf("Inteiro a particionar:");
    scanf("%d", &number);

    printf("Quant.max de particoes:");
    scanf("%d", &maxSlices);

    slice = split(number, maxSlices);
    printf("\n\nResultado:%d", slice);
}

split(int number, int maxSlices)
{
    // apenas para números positivos e também não é possivel fazer zero partições
    if ((number < 0) || (maxSlices == 0))
        return 0;

    // se o numero for zero existe apenas uma alternativa
    if (number == 0)
        return 1;

    return (split((number - maxSlices), maxSlices) + split(number, (maxSlices - 1)));
}