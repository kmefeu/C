/*----------------------------------------------------
|               IMPORTAÇÃO DAS BIBLIOTECAS            |
-----------------------------------------------------*/
//Matheus Corrêa 202010270 ENG COMP

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define true 1
#define false 0

/*----------------------------------------------------
|               CRIAÇÃO DAS ESTRUTURAS                |
-----------------------------------------------------*/

typedef struct L
{
    int numero;
    char letra;
    struct L *prox;
} noListaSimples;

struct dadosDeOcorrencia
{
    int maisFrequente;
    int maiorFrequencia;
    int menosFrequente;
    int menorFrequencia;
    int flag;
} ocorrencia;

/*----------------------------------------------------
|               PROTOTIPOS DAS FUNÇÕES                |
-----------------------------------------------------*/
int inicializar(noListaSimples **lista);
int adicionar(noListaSimples **lista);
int imprimeLista(noListaSimples *lista);
int inverterLista(noListaSimples **lista, noListaSimples **listaInvertida);
int capturarOcorrencia(noListaSimples *lista);
int imprimeOcorrencia();
int analiseRecursiva(noListaSimples *lista, int *contagem);
int tamanhoLista(noListaSimples *lista, int *tamanho);

/*----------------------------------------------------
|               FUNÇÃO PRINCIPAL                      |
-----------------------------------------------------*/

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opcao, contagem = 0;
    noListaSimples *ini, *listaInvertida;
    ocorrencia.flag = false;

    inicializar(&ini);
    inicializar(&listaInvertida);

    do
    {
        system("cls");
        printf("1  -> (A) Criar Lista (20 Elementos)\n");
        printf("2  -> (B) Capturar Maior Menor\n");
        printf("3  -> (C) Imprimir Maior Menor\n");
        printf("4  -> (D) Inverter Lista\n");
        printf("5  -> (E) Analise Recursiva\n");
        printf("6  ->     Imprimir Lista\n");
        printf("7  ->     Fechar\n");
        printf("\n\nOpção: ");

        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            adicionar(&ini);
            break;

        case 2:
            capturarOcorrencia(ini);
            printf("\n\nOcorrências registradas com sucesso!");
            break;

        case 3:
            imprimeOcorrencia();
            break;

        case 4:
            inverterLista(&ini, &listaInvertida);
            break;

        case 5:
            contagem = 0;
            analiseRecursiva(ini, &contagem);
            printf("Resultado: %d", contagem);
            break;

        case 6:
            imprimeLista(ini);
            break;

        case 7:
            printf("\n\nFechando programa");
            break;
        default:
            printf("\n\nOpção invalida");
        }
        printf("\n\n");
        system("pause");
        system("cls");

    } while ((opcao != 7));

    return 0;
}

/*----------------------------------------------------
|               FUNÇÃO INICIALIZAR                   |
-----------------------------------------------------*/

int inicializar(noListaSimples **lista)
{
    *lista = NULL;

    return 0;
}

/*----------------------------------------------------
|               FUNÇÃO DE ADICIONAR                   |
-----------------------------------------------------*/

int adicionar(noListaSimples **lista)
{

    for (int i = 1; i < 5; i++)
    {
        int numero;
        char letra;
        printf("\nNumero: ");
        scanf("%d", &numero);
        printf("Letra: ");
        fflush(stdin);
        scanf("%c", &letra);

        noListaSimples *novoNo;
        novoNo = (noListaSimples *)malloc(sizeof(noListaSimples));
        novoNo->numero = numero;
        novoNo->letra = letra;

        if (*lista == NULL)
        {

            novoNo->prox = NULL;
            *lista = novoNo;
        }
        else
        {
            noListaSimples *noAtual = *lista;
            noListaSimples *noAnterior = *lista;
            while (noAtual != NULL && noAtual->numero < novoNo->numero)
            {

                noAnterior = noAtual;
                noAtual = noAtual->prox;
            }

            if (noAtual == *lista)
            {

                novoNo->prox = *lista;
                *lista = novoNo;
            }
            else
            {
                novoNo->prox = noAnterior->prox;
                noAnterior->prox = novoNo;
            }
        }
    }

    return 0;
}

/*----------------------------------------------------
| FUNÇÃO DE CAPTURAR NUMEROS MAIS E MENOS FREQUENTES  |
-----------------------------------------------------*/

int capturarOcorrencia(noListaSimples *lista)
{
    int i = 0, numeroEmComparacao, contador = 0, maiorFrequencia = 0, menorFrequencia = 1000, maisFrequente, menosFrequente;
    noListaSimples *noAtual, *inicioLista;

    inicioLista = lista;

    if (lista == NULL)
    {
        printf("\n\nLista Vazia");
        return 1;
    }

    while (lista != NULL)
    {

        numeroEmComparacao = lista->numero;

        noAtual = inicioLista;

        while (noAtual != NULL)
        {
            if (noAtual->numero == numeroEmComparacao)
            {
                contador++;
            }
            if (noAtual->prox == NULL)
            {
                if (contador > maiorFrequencia)
                {
                    maisFrequente = numeroEmComparacao;
                    maiorFrequencia = contador;
                }

                if (menorFrequencia >= contador && contador != 0)
                {
                    menosFrequente = numeroEmComparacao;
                    menorFrequencia = contador;
                }
            }

            noAtual = noAtual->prox;
        }
        contador = 0;
        lista = lista->prox;
    }

    ocorrencia.maisFrequente = maisFrequente;
    ocorrencia.maiorFrequencia = maiorFrequencia;
    ocorrencia.menosFrequente = menosFrequente;
    ocorrencia.menorFrequencia = menorFrequencia;
    ocorrencia.flag = true;

    return 0;
}

/*----------------------------------------------------
|                  IMRPIME LISTA                      |
-----------------------------------------------------*/

int imprimeLista(noListaSimples *lista)
{
    int i;
    if (lista == NULL)
    {
        printf("\n\nLista Vazia");
        return 1;
    }

    printf("\n\n");

    while (lista != NULL)
    {
        printf("%d", lista->numero);
        printf("-%c ", lista->letra);
        lista = lista->prox;
    }

    printf("\n\n");
    return 0;
}

/*----------------------------------------------------
|               IMRPIME OCORRENCIAS                   |
-----------------------------------------------------*/

int imprimeOcorrencia()
{
    if (ocorrencia.flag == false)
    {
        printf("\n\nAcionar primeiro a opção 2");
        return 1;
    }

    printf("\nElemento mais frequete da lista: %d, ", ocorrencia.maisFrequente);
    printf("Com uma frequencia de  %d vezes.\n", ocorrencia.maiorFrequencia);

    printf("\nElemento menos frequente da lista: %d, ", ocorrencia.menosFrequente);
    printf("Com uma frequencia de  %d vezes.\n", ocorrencia.menorFrequencia);

    printf("\n");

    return 0;
}

/*----------------------------------------------------
|               CRIA LISTA INVERTIDA                  |
-----------------------------------------------------*/

int inverterLista(noListaSimples **lista, noListaSimples **listaInvertida)
{

    int i, count = 1, tam = 0;
    noListaSimples *inversor, *novoNo, *percorre, *percorre2;

    inversor = *lista;
    percorre = *lista;

    while (inversor != NULL)
    {
        tam++;
        if (inversor->prox == NULL)
        {
            break;
        }
        inversor = inversor->prox;
    }

    while (percorre != NULL)
    {
        inversor = *lista;
        novoNo = (noListaSimples *)malloc(sizeof(noListaSimples));

        for (i = 0; i < tam - count; i++)
        {
            inversor = inversor->prox;
        }
        count++;
        novoNo->numero = inversor->numero;
        novoNo->letra = inversor->letra;
        if (*listaInvertida == NULL)
        {
            novoNo->prox = NULL;
            *listaInvertida = novoNo;
        }
        else
        {
            percorre2 = *listaInvertida;
            while (percorre2->prox != NULL)
            {
                percorre2 = percorre2->prox;
            }
            percorre2->prox = novoNo;
            novoNo->prox = NULL;
        }
        percorre = percorre->prox;
    }
    imprimeLista(*listaInvertida);

    return 0;
}

/*----------------------------------------------------
|                 ANALISE RECURSIVA                   |
-----------------------------------------------------*/

int analiseRecursiva(noListaSimples *lista, int *contagem)
{
    char vogais[11] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
    int size = 10, i;

    if (lista == NULL)
    {
        return 1;
    }

    for (i = 0; i < size; i++)
    {

        if ((lista->numero) % 10 == 0)
        {
            if (lista->letra == vogais[i])
            {

                *contagem = *contagem + 1;
            }
        }
    }
    if (lista->prox == NULL)
    {
        return 0;
    }
    return analiseRecursiva((lista->prox), contagem);
}

/*----------------------------------------------------
|                OBTER TAMANHO DA LISA                |
-----------------------------------------------------*/

int tamanhoLista(noListaSimples *lista, int *tamanho)
{
    noListaSimples *percorre;
    *tamanho = 0;
    if (lista != NULL)
    {
        percorre = lista;
        while (percorre != NULL)
        {
            (*tamanho)++;
            percorre = percorre->prox;
        }
    }
    else
    {
        *tamanho = 0;
    }
}
