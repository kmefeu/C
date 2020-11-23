#include <stdio.h>
#include <stdlib.h>

void cadastrarClientes();
void listarClientes();
void excluirClientes();
void listarClientesPorCodigo();

typedef struct estruturaClientes
{
    int codigo;
    char nome[26];
    char endereco[31];
    char cpf[15];
    int flag;
} Clientes;

int main()
{
    int opcao;

    do
    {
        printf("Menu Principal\n");
        printf("1 - Incluir Clientes\n");
        printf("2 - Listar  Clientes\n");
        printf("3 - Excluir Clientes\n");
        printf("4 - Listar  Clientes por codigo\n");
        printf("5 - Encerrar aplicativo\n");
        printf("Opcao:");
        scanf("%d", &opcao);

        if (opcao == 1)
        {

            cadastrarClientes();
        }
        if (opcao == 2)
        {

            listarClientes();
        }
        if (opcao == 3)
        {
            excluirClientes();
        }
        if (opcao == 4)
        {
            listarClientesPorCodigo();
        }

    } while (opcao != 5);
    return 0;
}

void cadastrarClientes()
{

    int resp;
    Clientes TBClientes;

    printf("Cadatrar Dados de Clientes\n\n");
    printf("Codigo:");
    scanf("%d", &TBClientes.codigo)

        printf("Nome:");
    fgets(TBClientes.nome, 26, stdin);

    printf("Endereco:");
    fgets(TBClientes.endereco, 31, stdin);

    printf("CPF:");
    fgets(TBClientes.cpf, 15, stdin);

    TBClientes.flag = 1;

    FILE *fp = fopen("clientes.txt", "a+b");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    resp = fwrite(&TBClientes, sizeof(Clientes), 1, fp);
    if (resp != 1)
    {
        printf("ERRO: Não foi possivel cadastrar o cliente.");
    }
    fclose(fp);
}

void listarClientes()
{

    Clientes TBClientes;
    FILE *fp = fopen("clientes.txt", "r+b");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    while (!feof(fp))
    {
        fread(&TBClientes, sizeof(TBClientes), 1, fp);
        if (feof(fp))
        {
            break;
        }
        if (TBClientes.flag == 1)
        {
            printf("\n\n");
            printf("\nCodigo:%d\nNome:%sEndereco:%sCPF:%sFlag:%d", TBClientes.codigo, TBClientes.nome, TBClientes.endereco, TBClientes.cpf, TBClientes.flag);
        }
    }

    fclose(fp);
}

void excluirClientes()
{

    Clientes TBClientes;
    FILE *arquivo = fopen("clientes.txt", "r+b");
    FILE *arquivonovo = fopen("clientesnovo.txt", "wb");
    char file[] = "clientes.txt";
    char filenovo[] = "clientesnovo.txt";
    int resp, codigo, verifica = 0;

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    printf("Digite o codigo de quem deseja excluir: ");
    scanf("%d", &codigo);

    while (!feof(arquivo))
    {
        fread(&TBClientes, sizeof(TBClientes), 1, arquivo);
        if (feof(arquivo))
        {
            break;
        }
        if (TBClientes.codigo == codigo)
        {
            verifica = 1;
            TBClientes.flag = 0;
        }

        if (TBClientes.flag == 1)
        {
            resp = fwrite(&TBClientes, sizeof(Clientes), 1, arquivonovo);
            if (resp != 1)
            {
                printf("Nao foi possivel excluir o cliente.");
            }
        }
    }

    fclose(arquivo);
    fclose(arquivonovo);
    remove(file);
    rename(filenovo, file);

    if (verifica == 0)
    {
        printf("Cliente nao encontrado\n");
    }

    else
    {
        printf("Cliente:%s excluido\n", TBClientes.nome);
    }
}

void listarClientesPorCodigo()
{
    int cod, contador = 0, i, j, aux;
    int *cods = NULL;

    Clientes TBClientes;
    FILE *fp = fopen("clientes.txt", "r+b");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    while (!feof(fp))
    {
        if (feof(fp))
        {
            break;
        }
        fread(&TBClientes, sizeof(TBClientes), 1, fp);
        contador++;
    }
    cods = (int *)malloc(contador * sizeof(int));
    rewind(fp);
    for (i = 0; i < contador; i++)
    {
        fseek(fp, i * sizeof(Clientes), SEEK_SET);
        fread(&TBClientes, sizeof(Clientes), 1, fp);
        if (feof(fp))
        {
            break;
        }
        cods[i] = TBClientes.codigo;
    }
    for (i = 0; i < contador; i++)
    {
        for (j = 0; j < contador; j++)
        {
            if (cods[i] < cods[j])
            {
                aux = cods[i];
                cods[i] = cods[j];
                cods[j] = aux;
            }
        }
    }

    rewind(fp);

    for (i = 0; i <= contador; i++)
    {
        while (!feof(fp))
        {
            fread(&TBClientes, sizeof(TBClientes), 1, fp);
            if (feof(fp))
            {
                rewind(fp);
                break;
            }
            if (TBClientes.codigo == cods[i])
            {
                printf("Codigo:%d\nNome:%sEndereco:%sCPF:%s\n", TBClientes.codigo, TBClientes.nome, TBClientes.endereco, TBClientes.cpf);
            }
        }
    }
    fclose(fp);
}