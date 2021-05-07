/*----------------------------------------------------
|               IMPORTAÇÃO DAS BIBLIOTECAS            |
-----------------------------------------------------*/

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

typedef struct LI
{
    int numero;
    char letra;
    struct LI *prox;
} Reverse;

struct Ex
{
    int Mais;
    int Mais_qnt;
    int Menos;
    int Menos_qnt;
    int flag;
} c;

/*----------------------------------------------------
|               PROTOTIPOS DAS FUNÇÕES                |
-----------------------------------------------------*/
int inicializar(noListaSimples **lista);
int adicionar(noListaSimples **lista);
int imprimeLista(noListaSimples *lista);
int inverterLista(noListaSimples **lista, Reverse **reverse_ini);
int capturarOcorrencia(noListaSimples *lista);
int imprimeOcorrencia();
int analiseRecursiva(noListaSimples *lista, int *quant);
int tamanhoLista(noListaSimples *lista, int *tam);

/*----------------------------------------------------
|               FUNÇÃO PRINCIPAL                      |
-----------------------------------------------------*/

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int feedback, opcao, quant = 0;
    noListaSimples *ini;
    Reverse *reverse_ini;
    c.flag = false;
    feedback = inicializar(&ini);
    feedback = inicializar(&reverse_ini);

    printf("P1 LABORATÓRIO DE ESTRUTURA DE numeroS");
    printf("MATHEUS CORRÊA RA:202010270");

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
            feedback = adicionar(&ini);
            if (feedback == 0)
            {
                printf("\nInserção realizada com sucesso!\n");
            }
            else
            {

                printf("\nFalha na incerção!\n");
            }
            break;
        case 2:
            feedback = capturarOcorrencia(ini);
            if (feedback == 1)
                printf("Lista vazia!\n");
            break;
        case 3:
            feedback = imprimeOcorrencia();
            if (feedback == 1)
                printf("Execute a opcao 2 antes!\n");
            break;
        case 4:
            feedback = inverterLista(&ini, &reverse_ini);
            if (feedback == 1)
                printf("Lista vazia!\n");
            break;

        case 5:
            feedback = analiseRecursiva(ini, &quant);
            if (feedback == 1)
                printf("Lista vazia!\n");
            else
                printf("Existem %d nos com vogais e numeros divisiveis por 10!", quant);
            break;
        case 6:
            feedback = imprimeLista(ini);
            if (feedback == 1)
            {
                printf("\nLista vazia. Impossivel listar");
            }
            break;
        case 7:
            printf("\n\n Fechando programa");
            break;
        default:
            printf("\n\n Opcao nao valida");
        }
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
    noListaSimples *aux1, *aux2;
    int numero;
    char letra;

    for (int i = 1; i < 5; i++)
    {
        noListaSimples *novoNo;
        printf("\nNumero: ");
        scanf("%d", &numero);
        printf("Letra: ");
        fflush(stdin);
        scanf("%c", &letra);
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
            noListaSimples *atual = *lista;
            noListaSimples *ant = *lista;
            while (atual != NULL && atual->numero < novoNo->numero)
            {

                ant = atual;
                atual = atual->prox;
            }

            if (atual == *lista)
            {

                novoNo->prox = *lista;
                *lista = novoNo;
            }
            else
            {
                novoNo->prox = ant->prox;
                ant->prox = novoNo;
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
    int i = 0, aux1, cont = 0, cont_Mais = 0, cont_Menos = 1000, Mais, Menos, len;
    noListaSimples *percorre;
    noListaSimples *aux2;
    aux2 = lista;

    if (lista == NULL)
    {
        return 1;
    }

    while (lista != NULL)
    {

        aux1 = lista->numero;
        percorre = aux2;
        while (percorre != NULL)
        {
            if (percorre->numero == aux1)
            {
                cont++;
            }
            if (percorre->prox == NULL)
            {
                if (cont > cont_Mais)
                {
                    Mais = aux1;
                    cont_Mais = cont;
                }

                if (cont_Menos >= cont && cont != 0)
                {
                    Menos = aux1;
                    cont_Menos = cont;
                }
            }

            percorre = percorre->prox;
        }
        cont = 0;
        lista = lista->prox;
    }
    //Salvando em outra struct
    c.Mais = Mais;
    c.Mais_qnt = cont_Mais;
    c.Menos = Menos;
    c.Menos_qnt = cont_Menos;
    c.flag = true;

    printf("\nElementos definidos com sucesso!\n");
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
        return 1; /* lista vazia */
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
    if (c.flag == false)
    {
        return 1;
    }
    else

        printf("\nElemento que mais aparece na lista: %d\n", c.Mais);
    printf(" %d vezes!\n", c.Mais_qnt);
    printf("\nElemento que menos aparece na lista: %d\n", c.Menos);
    printf(" %d vezes!\n", c.Menos_qnt);
    return 0;
}

/*----------------------------------------------------
|               CRIA LISTA INVERTIDA                  |
-----------------------------------------------------*/

int inverterLista(noListaSimples **lista, Reverse **reverse_ini)
{
    int i, len, count = 1;
    noListaSimples *percorre, *aux_1, *aux_2, *aux_3;
    percorre = *lista;
    Reverse *no_invertido, *percorre2;
    tamanhoLista(*lista, &len);
    aux_1 = *lista;

    if (*lista == NULL)
    {
        return 1;
    }

    else
        while (percorre != NULL)
        {
            aux_1 = *lista;
            no_invertido = (Reverse *)malloc(sizeof(Reverse));

            for (i = 0; i < len - count; i++)
            {

                aux_1 = aux_1->prox;
            }

            count++;

            no_invertido->numero = aux_1->numero;
            no_invertido->letra = aux_1->letra;

            if (*reverse_ini == NULL)
            {

                no_invertido->prox = NULL;
                *reverse_ini = no_invertido;
            }
            else
            {
                percorre2 = *reverse_ini;

                while (percorre2->prox != NULL)
                {
                    percorre2 = percorre2->prox;
                }

                percorre2->prox = no_invertido;
                no_invertido->prox = NULL;
            }
            percorre = percorre->prox;
        }

    printf("\n\nLISTA INVERTIDA::\n");
    while (*reverse_ini != NULL)
    {
        printf("\n %d", (*reverse_ini)->numero);
        printf(" %c", (*reverse_ini)->letra);
        *reverse_ini = (*reverse_ini)->prox;
    }
    printf("\n");
    return 0;
}

/*----------------------------------------------------
|                 ANALISE RECURSIVA                   |
-----------------------------------------------------*/

int analiseRecursiva(noListaSimples *lista, int *quant)
{
    char vogais[11] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'}; // size = 10 das vogais
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

                *quant = *quant + 1;
            }
        }
    }
    if (lista->prox == NULL)
    {
        return 0;
    }
    else

        return analiseRecursiva((lista->prox), quant);
}

/*----------------------------------------------------
|                OBTER TAMANHO DA LISA                |
-----------------------------------------------------*/

int tamanhoLista(noListaSimples *lista, int *tam)
{
    noListaSimples *percorre;
    *tam = 0;
    if (lista != NULL)
    {
        percorre = lista;
        while (percorre != NULL)
        {
            (*tam)++;
            percorre = percorre->prox;
        }
    }
    else
    {
        *tam = 0;
    }
}
