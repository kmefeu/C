#include <stdio.h>
#include <stdlib.h>

void cadastrarPacientes();
void listarPacientes();
void excluirPacientes();
void pesquisarPacientesPorCodigo();

typedef struct estruturaPacientes
{
    int codigo;
    char nome[26];
    char telefone[31];
    char sexo[15];
    struct
    {
        int dia;
        int mes;
        int ano;
    } nas;
    int flag;
} Pacientes;

int main()
{
    int opcao;

    system("cls");
    do
    {
        printf("Menu Principal\n");
        printf("1 - Incluir    Pacientes\n");
        printf("2 - Listar     Pacientes\n");
        printf("3 - Excluir    Pacientes\n");
        printf("4 - Pesquisar  Paciente por codigo\n");
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
            pesquisarPacientesPorCodigo();
        }

    } while (opcao != 5);
    return 0;
}

void cadastrarPacientes()
{

    int resp;
    Pacientes TBPacientes; 
    printf("\nCadatrar Dados de Pacientes\n\n");
    printf("\nCodigo:");
    scanf("%d", &TBPacientes.codigo);
    getchar();
    printf("\nNome:");
    fgets(TBPacientes.nome, 26, stdin);
    printf("\nTelefone:");
    fgets(TBPacientes.telefone, 31, stdin);
    printf("\nSexo (Masculino - Feminino):");
    fgets(TBPacientes.sexo, 15, stdin);
    printf("\n\nData de Nascimento\n");
    printf("\nDia:");
    scanf("%d", &TBPacientes.nas.dia);
    printf("\nMes:");
    scanf("%d", &TBPacientes.nas.mes);
    printf("\nAno:");
    scanf("%d", &TBPacientes.nas.ano);

    TBPacientes.flag = 1; //pacientes        ativo
    FILE *fp = fopen("pacientes.txt", "a+b");
    if (fp == NULL)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo.");
        exit(1);
        getchar();
    }

    resp = fwrite(&TBPacientes, sizeof(Pacientes), 1, fp);
    if (resp != 1)
    {
        printf("\nERRO: Nao foi possivel cadastrar o paciente.");
    }
    fclose(fp);
    system("cls");
    printf("\nPressione qualquer tecla para continuar");
    getchar();
    system("cls");
}

void listarPacientes()
{

    Pacientes TBPacientes;
    FILE *fp = fopen("pacientes.txt", "r+b");
    if (fp == NULL)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo.");
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
            printf("\nCodigo:%d\nNome:%sTelefone:%sSexo:%sData de Nascimento:%d/%d/%d\nFlag:%d\n", TBPacientes.codigo, TBPacientes.nome, TBPacientes.telefone, TBPacientes.sexo, TBPacientes.nas.dia, TBPacientes.nas.mes, TBPacientes.nas.ano, TBPacientes.flag);
        }
    }
    fclose(fp);
    printf("\nPressione qualquer tecla para continuar");
    getchar();
    getchar();
    
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
        printf("\nERRO: Nao foi possivel abrir o arquivo.");
        exit(1);
        getchar();
    }

    printf("\nDigite o codigo de quem deseja excluir: ");
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
                printf("\nNao foi possivel excluir o paciente.");
            }
        }
    }

    fclose(arquivo);
    fclose(arquivonovo);
    remove(file);
    rename(filenovo, file);
    if (verifica == 0)
        printf("\nPaciente nao encontrado\n");
    else
        printf("\nPaciente:%s Excluido\n", TBPacientes.nome);
    printf("\nPressione qualquer tecla para continuar");
    getchar();
    getchar();
    system("cls");
}

void pesquisarPacientesPorCodigo()
{
    int cod, contador = 0, i, j, aux;

    Pacientes TBPacientes;
    FILE *fp = fopen("pacientes.txt", "r+b");
    if (fp == NULL)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo.");
        exit(1);
        getchar();
    }

    printf("\nDigite o codigo para pesquisa:");
    scanf("%d", &cod);

    while (!feof(fp))
    {
        fread(&TBPacientes, sizeof(TBPacientes), 1, fp);
        if (TBPacientes.codigo == cod)
        {
            printf("\nCodigo:%d\nNome:%sTelefone:%sSexo:%sData de Nascimento:%d/%d/%d\n", TBPacientes.codigo, TBPacientes.nome, TBPacientes.telefone, TBPacientes.sexo, TBPacientes.nas.dia, TBPacientes.nas.mes, TBPacientes.nas.ano);
            break;
        }
        if (feof(fp))
        {
            printf("\nCodigo nao encontrado.\n");
            break;
        }
    }
    getchar();
    fclose(fp);
    printf("\nPressione qualquer tecla para continuar");
    getchar();
    getchar();
    system("cls");
}