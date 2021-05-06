#include <stdio.h>
#include <stdlib.h>

typedef struct L
{
    int numero;
    char letra;
    struct L *prox;
} lista;

typedef struct Lo
{
    int numero;
    int numeroDeOcorrencias;
    struct Lo *prox;
} listaDeOcorrencia;

int inicializar(lista **ponteiroParaLista);
int inicializarOcorrencia(listaDeOcorrencia **ponteiroParaLista);
int adicionar(int numero, char letra, lista **ponteiroParaLista);
int capturarMaiorOcorrencia(lista *ponteiroParaListaAnalisada, listaDeOcorrencia **ponteiroParaListaResposta);
int imprime(lista *ponteiroParaInicioDaLista);
int imprimeOcorrencia(listaDeOcorrencia *ponteiroParaInicioDaLista);
int inverterLista(lista *ponteiroParaListaOriginal, lista **ponteiroParaListaInvertida);
int analiseRecursiva(lista *ponteiroParaListaAnalisada);

int main(void)
{

    int numero, opcao, resultadoAnaliseRecursiva;
    char letra;
    lista *noInicialDaListaOriginal, *noInicialDaListaInvertida;
    listaDeOcorrencia *noInicialDaListaDeOcorrencia;

    // inicia todas as listas zeradas
    inicializar(&noInicialDaListaOriginal);
    inicializarOcorrencia(&noInicialDaListaDeOcorrencia);
    inicializar(&noInicialDaListaInvertida);

    do
    {
        system("cls");
        printf("\n\nOpcoes: \n\n");
        printf("1 -> Adicionar Elementos (20 Elementos)\n");
        printf("2 -> Imprimir Maiores e Menores Ocorencias\n");
        printf("3 -> Gerar e Imprimir Lista inversa\n");
        printf("4 -> Encontrar nós com vogáis e simultaneamente números divisíveis por 10\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            for (int i; i < 2; i++)
            {
                printf("\nNumero para inserir na lista: ");
                scanf("%d", &numero);
                printf("\nLetra para inserir na lista: ");
                scanf("%c", &letra);
                adicionar(numero, letra, &noInicialDaListaOriginal);
            }
            break;
        case 2:
            printf("\n-> Buscando maiores e menores ocorrencias");
            capturarMaiorOcorrencia(noInicialDaListaOriginal, &noInicialDaListaDeOcorrencia);
            imprimeOcorrencia(noInicialDaListaDeOcorrencia);
            break;
        case 3:
            printf("\n-> Invertendo lista");
            inverterLista(noInicialDaListaOriginal, &noInicialDaListaInvertida);
            imprime(noInicialDaListaInvertida);
            break;
        case 4:
            printf("\n-> Fazendo analise recursiva");
            resultadoAnaliseRecursiva = analiseRecursiva(noInicialDaListaOriginal);
            printf("\n-> Resultado: %d", resultadoAnaliseRecursiva);
            break;
        case 7:
            break;
        default:
            printf("\n\n Opcao nao valida");
        }
        getchar();
    } while ((opcao != 7));
}

int inicializar(lista **ponteiroParaLista)
{
    lista *percorre, *aux;
    if (*ponteiroParaLista != NULL)
    {
        percorre = *ponteiroParaLista;
        while (percorre != NULL)
        {
            aux = percorre;
            percorre = percorre->prox;
            free(aux);
        }

        *ponteiroParaLista = NULL;
        return 1;
    }
    return 0;
}

int inicializarOcorrencia(listaDeOcorrencia **ponteiroParaLista)
{
    listaDeOcorrencia *percorre, *aux;
    if (*ponteiroParaLista != NULL)
    {
        percorre = *ponteiroParaLista;
        while (percorre != NULL)
        {
            aux = percorre;
            percorre = percorre->prox;
            free(aux);
        }

        *ponteiroParaLista = NULL;
        return 1;
    }
    return 0;
}

int adicionar(int numero, char letra, lista **ponteiroParaLista)
{
    lista *novoNo;
    novoNo = (lista *)malloc(sizeof(lista));
    novoNo->numero = numero;
    novoNo->letra = letra;

    if (*ponteiroParaLista == NULL)
    {
        novoNo->prox = NULL;
        *ponteiroParaLista = novoNo;
    }
    else
    {
        lista *percorre;
        percorre = *ponteiroParaLista;

        while (percorre->prox != NULL)
        {
            // se o numero do novo no for menor que o proximo numero ele entra na frente da lista
            if (novoNo->numero < percorre->numero)
            {
                break;
            }
            percorre = percorre->prox;
        }
        // novoNo recebe como proximo o numero de maior valor
        novoNo->prox = percorre->prox;
        // o endereço do antigo menor numero recebe o endereço do novoNo
        percorre->prox = novoNo;
    }
    return 0;
}

int capturarMaiorOcorrencia(lista *ponteiroParaListaAnalisada, listaDeOcorrencia **ponteiroParaListaResposta)
{

    int numeroDeMaiorOcorrencia, maiorOcorrencia = 0, numeroDeMenorOcorrencia, menorOcorrencia = 0, ocorrencias = 0, numeroEmComparacao;

    lista *percorre1, *percorre2;
    percorre1 = ponteiroParaListaAnalisada;
    percorre2 = ponteiroParaListaAnalisada;
    numeroDeMaiorOcorrencia = percorre1->numero;
    numeroDeMenorOcorrencia = percorre1->numero;

    while (percorre1->prox != NULL)
    {
        numeroEmComparacao = percorre1->numero;
        ocorrencias = 0;

        while (percorre2->prox != NULL)
        {
            if (numeroEmComparacao == percorre2->numero)
            {
                ocorrencias = ocorrencias + 1;
            }

            percorre2 = percorre2->prox;
        }

        if (maiorOcorrencia < ocorrencias)
        {
            maiorOcorrencia = ocorrencias;
            numeroDeMaiorOcorrencia = numeroEmComparacao;
        }
        if (menorOcorrencia > ocorrencias)
        {
            menorOcorrencia = ocorrencias;
            numeroDeMenorOcorrencia = numeroEmComparacao;
        }
        percorre1 = percorre1->prox;
    }

    // cria um novo no
    listaDeOcorrencia *novoNo;
    novoNo = (listaDeOcorrencia *)malloc(sizeof(listaDeOcorrencia));
    novoNo->numero = numeroDeMaiorOcorrencia;
    novoNo->numeroDeOcorrencias = maiorOcorrencia;

    //usa o no inicical vazio
    (*ponteiroParaListaResposta)->numero = numeroDeMenorOcorrencia;
    (*ponteiroParaListaResposta)->numeroDeOcorrencias = menorOcorrencia;
    (*ponteiroParaListaResposta)->prox = novoNo;

    return 0;
}

int imprime(lista *ponteiroParaInicioDaLista)
{
    int i;
    if (ponteiroParaInicioDaLista == NULL)
    {
        return 1; /* lista vazia */
    }
    printf("LISTA ::  ");
    while (ponteiroParaInicioDaLista != NULL)
    {
        printf(" %d", ponteiroParaInicioDaLista->numero);
        printf(" %c\n", ponteiroParaInicioDaLista->letra);
        ponteiroParaInicioDaLista = ponteiroParaInicioDaLista->prox;
    }
    printf("\n");
    return 0; /* sem erro */
}

int imprimeOcorrencia(listaDeOcorrencia *ponteiroParaInicioDaLista)
{
    int i;
    if (ponteiroParaInicioDaLista == NULL)
    {
        return 1; /* lista vazia */
    }
    printf("LISTA ::  ");
    while (ponteiroParaInicioDaLista != NULL)
    {
        printf(" %d", ponteiroParaInicioDaLista->numero);
        printf(" %d\n", ponteiroParaInicioDaLista->numeroDeOcorrencias);
        ponteiroParaInicioDaLista = ponteiroParaInicioDaLista->prox;
    }
    printf("\n");
    return 0; /* sem erro */
}

int inverterLista(lista *ponteiroParaListaOriginal, lista **ponteiroParaListaInvertida)
{
    lista *percorre, *aux_1, *aux_2, *aux_3;
    percorre = ponteiroParaListaOriginal;
    if (percorre == NULL)
    {
        return 1; /*Caso a lista esteja vazia. */
    }
    else if (percorre->prox == NULL)
    {
        return 0; /*Caso a lista tenha apenas um n�. */
    }
    else
    {
        aux_1 = ponteiroParaListaOriginal;
        aux_2 = aux_1->prox;
        aux_3 = aux_2->prox;
        aux_1->prox = NULL;
        aux_2->prox = aux_1;

        while (aux_3 != NULL)
        {
            aux_1 = aux_2;
            aux_2 = aux_3;
            aux_3 = aux_3->prox;
            aux_2->prox = aux_1;
        }

        *ponteiroParaListaInvertida = aux_2;
    }
    return 0;
}

int analiseRecursiva(lista *ponteiroParaListaAnalisada)
{

    lista *percorre, *aux;
    if (*ponteiroParaListaAnalisada != NULL)
    {
        percorre = *ponteiroParaListaAnalisada;
        while (percorre != NULL)
        {
            aux = percorre;
            percorre = percorre->prox;
            free(aux);
        }

        *ponteiroParaListaAnalisada = NULL;
        return 1;
    }
    return 0;
}