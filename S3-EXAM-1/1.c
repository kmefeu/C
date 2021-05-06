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
int capturarMaiorOcorrencia(lista *ponteiroParaLista, listaDeOcorrencia **ponteiroParaListaResposta);
int imprime(lista *ponteiroParaLista);
int imprimeOcorrencia(listaDeOcorrencia *ponteiroParaLista);
int inverterLista(lista *ponteiroParaLista, lista **ponteiroParaListaInvertida);
int analiseRecursiva(lista *ponteiroParaLista);

int main(void)
{

    int numero, opcao, resultadoAnaliseRecursiva;
    char letra;
    lista *noInicialDaListaOriginal, *noInicialDaListaInvertida;
    listaDeOcorrencia *noInicialDaListaDeOcorrencia;

    noInicialDaListaOriginal = NULL;
    noInicialDaListaInvertida = NULL;
    noInicialDaListaDeOcorrencia = NULL;

    // inicia todas as listas zeradas
    // inicializar(&noInicialDaListaOriginal);
    // inicializarOcorrencia(&noInicialDaListaDeOcorrencia);
    // inicializar(&noInicialDaListaInvertida);

    do
    {
        system("cls");
        printf("1 -> Adicionar Elementos (20 Elementos)\n");
        printf("2 -> Imprimir Lista\n");
        printf("3 -> Imprimir Maiores e Menores Ocorencias\n");
        printf("4 -> Gerar e Imprimir Lista inversa\n");
        printf("5 -> Encontrar nos com vogais e simultaneamente numeros divisiveis por 10\n");
        printf("6 -> Fechar\n");
        printf("\n\nOpcoes: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            for (int i = 0; i < 3; i++)
            {
                printf("\nNumero: ");
                scanf("%d", &numero);
                getchar();
                printf("Letra: ");
                scanf("%c", &letra);
                adicionar(numero, letra, &noInicialDaListaOriginal);
            }
            break;
        case 2:
            imprime(noInicialDaListaOriginal);
            getchar();
            break;

        case 3:
            printf("\n-> Buscando maiores e menores ocorrencias");
            capturarMaiorOcorrencia(noInicialDaListaOriginal, &noInicialDaListaDeOcorrencia);
            imprimeOcorrencia(noInicialDaListaDeOcorrencia);
            getchar();
            break;
        case 4:
            printf("\n-> Invertendo lista");
            inverterLista(noInicialDaListaOriginal, &noInicialDaListaInvertida);
            imprime(noInicialDaListaInvertida);
            getchar();
            break;
        case 5:
            printf("\n-> Fazendo analise recursiva");
            resultadoAnaliseRecursiva = analiseRecursiva(noInicialDaListaOriginal);
            printf("\n-> Resultado: %d", resultadoAnaliseRecursiva);
            break;
        case 6:
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
    novoNo->prox = NULL;

    if (*ponteiroParaLista == NULL)
    {
        *ponteiroParaLista = novoNo;
    }
    else
    {
        lista *percorre;
        int flag;
        percorre = *ponteiroParaLista;

        while (percorre->prox != NULL)
        {
            flag = true;
            // se o numero do novo no for menor que o proximo numero ele entra na frente da lista
            if (novoNo->numero < percorre->numero)
            {
                flag = false;
                break;
            }
            if (flag)
            {
                percorre = percorre->prox;
            }
        }
        if (!flag)
        {

            // novoNo recebe como proximo o numero de maior valor
            novoNo->prox = percorre;
            // o endereço do antigo menor numero recebe o endereço do novoNo
            *ponteiroParaLista = novoNo;
        }
        else
        {
            percorre->prox = novoNo;
        }
    }
    return 0;
}

int capturarMaiorOcorrencia(lista *ponteiroParaLista, listaDeOcorrencia **ponteiroParaListaResposta)
{

    int numeroDeMaiorOcorrencia, maiorOcorrencia = 0, numeroDeMenorOcorrencia, menorOcorrencia = 0, ocorrencias = 0, numeroEmComparacao;

    lista *percorre1, *percorre2;
    percorre1 = ponteiroParaLista;

    numeroDeMaiorOcorrencia = percorre1->numero;
    numeroDeMenorOcorrencia = percorre1->numero;

    while (percorre1 != NULL)
    {
        numeroEmComparacao = percorre1->numero;
        ocorrencias = 0;
        percorre2 = ponteiroParaLista;

        while (percorre2 != NULL)
        {

            if (numeroEmComparacao == percorre2->numero)
            {
                ocorrencias++;
            }
            percorre2 = percorre2->prox;
        }

        if (maiorOcorrencia <= ocorrencias)
        {
            maiorOcorrencia = ocorrencias;
            numeroDeMaiorOcorrencia = numeroEmComparacao;
        }
        if (menorOcorrencia >= ocorrencias)
        {
            menorOcorrencia = ocorrencias;
            numeroDeMenorOcorrencia = numeroEmComparacao;
        }
        percorre1 = percorre1->prox;
    }

    // cria um novo no
    listaDeOcorrencia *novoNo, *novoNo2;
    novoNo = (listaDeOcorrencia *)malloc(sizeof(listaDeOcorrencia));
    novoNo->numero = numeroDeMaiorOcorrencia;
    novoNo->numeroDeOcorrencias = maiorOcorrencia;

    // cria um novo no
    novoNo2 = (listaDeOcorrencia *)malloc(sizeof(listaDeOcorrencia));
    novoNo2->numero = numeroDeMenorOcorrencia;
    novoNo2->numeroDeOcorrencias = menorOcorrencia;
    novoNo2->prox = NULL;

    // vincula os nos
    novoNo->prox = novoNo2;

    // passa o endereço da nova lista
    *ponteiroParaListaResposta = novoNo;

    printf("\nBRASIL SIL!");
    return 0;
}

int imprime(lista *ponteiroParaLista)
{
    int i;
    if (ponteiroParaLista == NULL)
    {
        return 1; /* lista vazia */
    }
    printf("\nLISTA ::  \n");
    while (ponteiroParaLista != NULL)
    {
        printf("\n %d", ponteiroParaLista->numero);
        printf(" %c\n", ponteiroParaLista->letra);
        ponteiroParaLista = ponteiroParaLista->prox;
    }
    printf("\n");
    return 0; /* sem erro */
}

int imprimeOcorrencia(listaDeOcorrencia *ponteiroParaLista)
{
    int i;
    if (ponteiroParaLista == NULL)
    {
        return 1; /* lista vazia */
    }
    printf("\nLISTA ::  \n");
    while (ponteiroParaLista != NULL)
    {
        printf("\nNumero: %d", ponteiroParaLista->numero);
        printf("\nOcorrencias: %d\n", ponteiroParaLista->numeroDeOcorrencias);
        ponteiroParaLista = ponteiroParaLista->prox;
    }
    printf("\n");
    return 0; /* sem erro */
}

int inverterLista(lista *ponteiroParaLista, lista **ponteiroParaListaInvertida)
{
    lista *percorre, *aux_1, *aux_2, *aux_3;
    percorre = ponteiroParaLista;
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
        aux_1 = ponteiroParaLista;
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

int recursiva(lista *percorre, char vogais[], int *contador)
{

    if (percorre != NULL)
    {
        int eVogal = false;

        for (int i = 0; i < 5; i++)
        {
            if (vogais[i] == percorre->letra)
            {
                eVogal = true;
                break;
            }
        }

        int resto;

        resto = percorre->numero % 10;
        printf("\nPegou o resto = %d", resto);

        if (resto == 0 && eVogal)
        {
            printf("\n Entrou no if ");
            *contador++;
        }

        printf("\nsaiu do if atribuindo novo percorre");
        percorre = percorre->prox;
        printf("\nchegou pra chamar a recursiva");
        if (percorre->prox != NULL)
        {
            recursiva(percorre, vogais, contador);
        }
    }
}
int analiseRecursiva(lista *ponteiroParaListaAnalisada)
{
    int *contador = 0;
    char vogais[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    lista *percorre;
    percorre = ponteiroParaListaAnalisada;
    recursiva(percorre, vogais, contador);

    return *contador;
}