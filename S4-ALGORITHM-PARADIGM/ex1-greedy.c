int valores_moedas[TAM];
int quant_moedas[TAM];

void main()
{
    int v_desejado, m, resto, i, moeda_selecionada;

    printf("Valor de troco:");
    scanf("%d", &v_desejado);

    printf("Quantidade de tipos de moedas:");
    scanf("%d", &m);

    Inicializar(m); //zeraro vetor

    for (i = 1; i <= m; i++)
    {
        printf("Valordemoeda:");
        scanf("%d", &valores_moedas[i]);
    }
    //Ordenar os valores dos tipos de moedas
    ordem(m);

    resto = v_desejado;
    moeda_selecionada = m;

    //começa pela moeda de maior valor

    while ((resto != 0) && (moeda_selecionada != 0))
    {
        if (resto >= valores_moedas[moeda_selecionada])
        {
            quant_moedas[moeda_selecionada]++;
            resto = resto - valores_moedas[moeda_selecionada];
        }
        else
        {
            moeda_selecionada--;
        }
    }