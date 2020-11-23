void excludeCustomer()
{

    Clientes TBClientes;
    FILE *fp = fopen("clientes.txt", "r+b");
    FILE *fp2 = fopen("clientes2.txt", "wb");
    char caminho[] = "clientes.txt";
    char caminho_novo[] = "clientes2.txt";
    int cod, resp, enc = 0;

    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
        getchar();
    }

    printf("Digite o código de quem deseja excluir: ");
    scanf("%d", &cod);

    while (!feof(fp))
    {
        fread(&TBClientes, sizeof(TBClientes), 1, fp);
        if (feof(fp))
        {
            break;
        }
        if (TBClientes.codigo == cod)
        {
            ;
            TBClientes.flag = 0;
            enc = 1;
        }

        if (TBClientes.flag == 1)
        {
            resp = fwrite(&TBClientes, sizeof(Clientes), 1, fp2);
            if (resp != 1)
            {
                printf("ERRO: Não foi possivel excluir o cliente.");
            }
        }
    }

    fclose(fp);
    fclose(fp2);
    remove(caminho);
    rename(caminho_novo, caminho);
    if (enc == 0)
        printf("Cliente não encontrado\n");
    else
        printf("Cliente excluido com sucesso\n");
    printf("Pressione qualquer tecla para continuar");
    getchar();
    getchar();
    system("cls");
}

void listarClientesPorCodigo()
{

    Clientes TBClientes;
    FILE *fp = fopen("clientes.txt", "r+b");
    int cod, enc = 0;
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
        getchar();
    }

    printf("Digite o código de quem deseja procurar: ");
    scanf("%d", &cod);

    while (!feof(fp))
    {
        fread(&TBClientes, sizeof(TBClientes), 1, fp);
        if (feof(fp))
        {
            break;
        }
        if (TBClientes.flag == 1)
        {
            if (TBClientes.codigo == cod)
            {
                printf("Codigo:%d\nNome:%sEndereço:%sCPF:%s\n", TBClientes.codigo, TBClientes.nome, TBClientes.endereco, TBClientes.cpf);
                getchar();
                enc = 1;
            }
        }
    }
    fclose(fp);
    if (enc == 0)
        printf("Cliente não encontrado\n");
    printf("Pressione qualquer tecla para continuar");
    getchar();
    getchar();
    system("cls");
}