#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int codigo[5], operacao, contador, consulta, alteracao, nCadastros = 5;

char especie[5][11], raca[5][11], nome[5][11], entrada[11];

//    CADASTRO

int cadastro()
{

    printf("\nPor favor cadastre as seguintes informacoes sobre o 'PET'");

    for (contador = 0; contador < nCadastros; contador++)
    {

        codigo[contador] = contador;

        printf("\n\nCODIGO PET:%d\n", codigo[contador]);

        printf("ESPECIE:");
        scanf("%s", entrada);
        strcpy(especie[contador], entrada);

        printf("RACA:");
        scanf("%s", entrada);
        strcpy(raca[contador], entrada);

        printf("NOME:");
        scanf("%s", entrada);
        strcpy(nome[contador], entrada);
    }

    return start();
}

// EXCLUIR

int excluir()
{

    printf("\nCODIGO:");
    scanf("%d", &consulta);

    strcpy(especie[consulta], "EXCLUIDO");
    strcpy(raca[consulta], "EXCLUIDO");
    strcpy(nome[consulta], "EXCLUIDO");

    printf("\n\nINFORMACOES DO PET %d FORAM EXCLUIDAS\n\n", consulta);

    return start();
}

// ALTERAR
int alterar()
{

    printf("CODIGO:");
    scanf("%d", &consulta);

    printf("DIGITE O QUE VOCE DESEJA ALTERAR\n1-PARA MUDAR A ESPECIE\n2-PARA MUDAR A RACA\n3-PARA MUDAR O NOME");
    printf("\n\nOPERACAO:");
    scanf("%d", &alteracao);

    if (alteracao == 1)
    {

        printf("INSIRA A NOVA ESPECIE: ");
        scanf("%s", entrada);
        strcpy(especie[consulta], entrada);
    }

    else if (alteracao == 2)
    {

        printf("INSIRA A NOVA RACA: ");
        scanf("%s", entrada);
        strcpy(raca[consulta], entrada);
    }

    else if (alteracao == 3)
    {

        printf("INSIRA O NOVO NOME: ");
        scanf("%s", entrada);
        strcpy(nome[consulta], entrada);
    }

    else
    {

        printf("\n\n\n\t\t\t---O VALOR INVALIDO---\n\n\n");
    }

    return start();
}

// LISTAGEM

int listar()
{

    for (contador = 0; contador < nCadastros; contador++)
    {

        printf("\n\n\t---------\n");
        printf("\nCODIGO:%d\nESPECIE:%s\nRACA:%s\nNOME:%s", codigo[contador], especie[contador], raca[contador], nome[contador]);
    }

    return start();
}

// CHECAGEM LETRA A LETRA

int validacao(char s1[], char s2[], int id)
{

    int rodada = 0;
    int t1 = strlen(s1);
    int t2 = strlen(s2);
    int igual = 0;
    int verificador = 0;

    if (t1 == t2)
    {

        for (rodada = 0; rodada < t1; rodada++)
        {
            if (s1[rodada] == s2[rodada])
            {
                igual = igual + 1;
            }
        }

        if (t1 == igual)
        {

            printf("\n\t-----CADASTRO ENCONTRADO----\n");
            printf("\n\nCODIGO:%d\nESPECIE:%s\nRACA:%s\nNOME:%s", codigo[id], especie[id], raca[id], nome[id]);
            printf("\n\n\t---------\n");
            verificador = 0;
        }

        else
        {
            verificador = 1;
        }
    }

    else
    {
        verificador = 1;
    }

    return verificador;
}

// PESQUISAR PELO NOME - CHECAGEM ITEM A ITEM

int pesquisa()
{

    int verificador = 0;

    printf("\nNOME:");
    scanf("%s", entrada);

    for (contador = 0; contador < nCadastros; contador++)
    {
        verificador = validacao(entrada, nome[contador], contador);
    }

    if (verificador == 1)
    {
        printf("\n\t-----CADASTRO NAO ENCONTRADO----\n");
    }

    return start();
}

int start()
{

    printf("\n\n\n\t\t\t--- CADASTRO DE ANIMAIS---\n\n\n");
    printf("\n1-CADASTRAR\n2-ALTERAR\n3-EXCLUIR\n4-LISTAR\n5-CONSULTAR POR NOME\n6-SAIR\n\n");

    printf("\nOPERACAO:");
    scanf("%d", &operacao);

    switch (operacao)

    {
    case 1:
        printf("\n\n\n\t\t\t---CADASTRAR---\n\n\n");
        cadastro();
        break;

    case 2:
        printf("\n\n\n\t\t\t---ALTERAR---\n\n\n");
        alterar();
        break;

    case 3:
        printf("\n\n\n\t\t\t---EXCLUIR---\n\n\n");
        excluir();
        break;

    case 4:
        printf("\n\n\n\t\t\t---LISTAR---\n\n\n");
        listar();
        break;

    case 5:
        printf("\n\n\n\t\t\t---PESQUISA POR NOME---\n\n\n");
        pesquisa();
        break;
    case 6:

        printf("\n\n\n\t\t\t---SAIR---\n\n\n");
        break;

    default:
        printf("\n\n\n\t\t\t---O VALOR INVALIDO---\n\n\n");
        start();
    }

    return 0;
}

int main()
{
    system("cls");

    start();

    return 0;
}