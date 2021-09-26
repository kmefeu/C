//Partição de Númerointeiros positivos
main()
{
    int number, maxSlices, slice;

    printf("Inteiro a particionar:");
    // number = 4
    scanf("%d", &number);

    // maxSlices = 4
    maxSlices = number;

    // slice = 5
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

// 1*Chamada
// split(4,4) => return (split((4 - 4), 4) + split(4, (4 - 1)));
// 2*Chamada
// split(0,4) => return 1;
// split(4,3) => return (split((4 - 3), 3) + split(4, (3 - 1)));
// 3*Chamada
// split(1,3) => return (split((1 - 3), 3) + split(1, (3 - 1)));
// split(4,2) => return (split((4 - 2), 2) + split(4, (2 - 1)));
// 4*Chamada
// split(-2,3)=> return 0;
// split(1,2) => return (split((1 - 2), 2) + split(1, (2 - 1)));
// split(2,2) => return (split((2 - 2), 2) + split(2, (2 - 1)));
// 5*Chamada
// split(-1,2)=> return 0;
// split(1,1) => return (split((1 - 1), 1) + split(1, (1 - 1)));
// split(0,2) => return 1;
// split(2,1) => return (split((2 - 1), 1) + split(2, (1 - 1)));
// 6*Chamada
// split(0,1) => return 1;
// split(1,0) => return 0;
// split(1,1) => return (split((1 - 1), 1) + split(1, (1 - 1)));
// split(2,0) => return 0;
// 7*Chamada
// split(0,1) => return 1;
// split(1,0) => return 0;