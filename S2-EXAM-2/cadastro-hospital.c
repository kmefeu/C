#include <stdio.h>
#include <stdlib.h>

void cadastrarPacientes();
void listarPacientes();
void excluirPacientes();
void listarPacientesPorCodigo();

typedef struct estruturaPacientes
{
    int codigo;
    char nome[26];
    char endereco[31];
    char cpf[15];
    int flag;
} Pacientes;

int main()
{
    int opcao;

    system("cls");
    do
    {
        printf("Menu Principal\n");
        printf("1 - Incluir Pacientes\n");
        printf("2 - Listar  Pacientes\n");
        printf("3 - Excluir Pacientes\n");
        printf("4 - Listar  Pacientes por codigo\n");
        printf("5 - Encerrar aplicativo\n");
        printf("Opcao:");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            system("cls"); //system("cls");
            cadastrarPacientes();
        }
        if (opcao == 2)
        {
            system("cls");
            listarPacientes();
        }
        if (opcao == 3)
        {
            excluirPacientes();
        }
        if (opcao == 4)
        {
            listarPacientesPorCodigo();
        }

    } while (opcao != 5);
    return 0;
}

void cadastrarPacientes()
{

    int resp;
    Pacientes TBPacientes; //Declara variavel TBClientes  do tipo Clientes
    printf("Cadatrar Dados de Pacientes\n\n");
    printf("Codigo:");
    scanf("%d", &TBPacientes.codigo);
    getchar(); //fflush(stdin); getch();
    printf("Nome:");
    fgets(TBPacientes.nome, 26, stdin);
    printf("Endereco:");
    fgets(TBPacientes.endereco, 31, stdin);
    printf("CPF:");
    fgets(TBPacientes.cpf, 15, stdin);
    TBPacientes.flag = 1; //cliente ativo
    FILE *fp = fopen("pacientes.txt", "a+b");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
        getchar();
    }

    resp = fwrite(&TBPacientes, sizeof(Pacientes), 1, fp);
    if (resp != 1)
    {
        printf("ERRO: Nao foi possivel cadastrar o paciente.");
    }
    fclose(fp);
    system("cls");
    printf("Pressione qualquer tecla para continuar");
    getchar();
    system("cls");
}

void listarPacientes()
{

    Pacientes TBPacientes;
    FILE *fp = fopen("pacientes.txt", "r+b");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
        getchar();
    }

    while (!feof(fp))
    {
        fread(&TBPacientes, sizeof(TBPacientes), 1, fp);
        if (feof(fp))
        {
            break;
        }
        if (TBPacientes.flag == 1)
        {
            printf("\n\n");
            printf("\nCodigo:%d\nNome:%sEndereco:%sCPF:%sFlag:%d", TBPacientes.codigo, TBPacientes.nome, TBPacientes.endereco, TBPacientes.cpf, TBPacientes.flag);
        }
    }
    fclose(fp);
    printf("Pressione qualquer tecla para continuar");
    getchar();
    getchar();
    system("cls");
}

void excluirPacientes()
{

    Pacientes TBPacientes;
    FILE *arquivo = fopen("pacientes.txt", "r+b");
    FILE *arquivonovo = fopen("pacientesnovo.txt", "wb");
    char file[] = "pacientes.txt";
    char filenovo[] = "pacientesnovo.txt";
    int resp, codigo, verifica = 0;

    if (arquivo == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
        getchar();
    }

    printf("Digite o codigo de quem deseja excluir: ");
    scanf("%d", &codigo);

    while (!feof(arquivo))
    {
        fread(&TBPacientes, sizeof(TBPacientes), 1, arquivo);
        if (feof(arquivo))
        {
            break;
        }
        if (TBPacientes.codigo == codigo)
        {
            verifica = 1;
            TBPacientes.flag = 0;
        }

        if (TBPacientes.flag == 1)
        {
            resp = fwrite(&TBPacientes, sizeof(Pacientes), 1, arquivonovo);
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
        printf("Paciente nao encontrado\n");
    else
        printf("Paciente:%s excluido\n", TBPacientes.nome);
    printf("Pressione qualquer tecla para continuar");
    getchar();
    getchar();
    system("cls");
}

void listarPacientesPorCodigo()
{
    int cod, contador = 0, i, j, aux;
    int *cods = NULL;

    Pacientes TBPacientes;
    FILE *fp = fopen("pacientes.txt", "r+b");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo.");
        exit(1);
        getchar();
    }

    while (!feof(fp))
    {
        if (feof(fp))
        {
            break;
        }
        fread(&TBPacientes, sizeof(TBPacientes), 1, fp);
        contador++;
    }
    cods = (int *)malloc(contador * sizeof(int));
    rewind(fp);
    for (i = 0; i < contador; i++)
    {
        fseek(fp, i * sizeof(Pacientes), SEEK_SET);
        fread(&TBPacientes, sizeof(Pacientes), 1, fp);
        if (feof(fp))
        {
            break;
        }
        cods[i] = TBPacientes.codigo;
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
            fread(&TBPacientes, sizeof(TBPacientes), 1, fp);
            if (feof(fp))
            {
                rewind(fp);
                break;
            }
            if (TBPacientes.codigo == cods[i])
            {
                printf("Codigo:%d\nNome:%sEndereco:%sCPF:%s\n", TBPacientes.codigo, TBPacientes.nome, TBPacientes.endereco, TBPacientes.cpf);
                getchar();
            }
        }
    }
    fclose(fp);
    printf("Pressione qualquer tecla para continuar");
    getchar();
    getchar();
    system("cls");
}