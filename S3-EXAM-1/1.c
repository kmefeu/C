#include <stdio.h>
#include <stdlib.h>

typedef struct L
{
    int dado;
    char letra;
    struct L *prox;
} lista;

int inicializar(lista **ponteiroParaLista);
int adicionar(int numero, char letra, lista *ponteiroParaLista);
int capturarMaiorOcorrencia(lista *ponteiroParaListaAnalisada, lista *ponteiroParaListaResposta);
int imprime(lista *ponteiroParaInicioDaLista);
int inverterLista(lista *ponteiroParaListaOriginal, lista **ponteiroParaListaInvertida);
int analiseRecursiva(lista *ponteiroParaListaAnalisada);

int main(void)
{

    int numero, opcao, resultadoAnaliseRecursiva;
    char letra;
    lista *noInicialDaListaOriginal, *noInicialDaListaDeOcorrencia, *noInicialDaListaInvertida;

    // inicia todas as listas zeradas
    inicializar(&noInicialDaListaOriginal);
    inicializar(&noInicialDaListaDeOcorrencia);
    inicializar(&noInicialDaListaInvertida);

    do
    {
        system("cls");
        printf("\n\nOpcoes: \n\n");
        printf("1 -> Adicionar Elementos (20 Elementos)\n");
        printf("2 -> Imprimir Maiores e Menores Ocorencias\n");
        printf("3 -> Gerar e Imprimir Lista inversa\n");
        printf("4 -> Encontrar nós com vogáis e simultaneamente números divisíveis por 10\n");
        scanf("%d", &opcao); /* Ler a opcao do usuario */
        switch (opcao)
        {
        case 1:
            printf("\nNumero para inserir na lista: ");
            scanf("%d", &numero);
            printf("\nLetra para inserir na lista: ");
            scanf("%c", &letra);
            adicionar(numero, letra, noInicialDaListaOriginal);
            break;
        case 2:
            printf("\n-> Buscando maiores e menores ocorrencias");
            capturarMaiorOcorrencia(noInicialDaListaOriginal, noInicialDaListaDeOcorrencia);
            imprime(noInicialDaListaDeOcorrencia);
            break;
        case 3:
            printf("\n-> Invertendo lista");
            inverterLista(noInicialDaListaOriginal, noInicialDaListaInvertida);
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
        getchar(); /* Limpa o buffer de entrada */
    } while ((opcao != 7));
}

int Inicializar2_LS(lista **inicio)
{
    lista *percorre, *aux;
    if (*inicio != NULL)
    {
        percorre = *inicio;
        while (percorre != NULL)
        {
            aux = percorre;
            percorre = percorre->prox;
            free(aux);
        }

        *inicio = NULL;
        return 1; /* inicializa apagando tudo da listsa */
    }
    else
    {
        return 0;
    }
}

int inverterLista(lista **inicio)
{
    Tno_ls *percorre, *aux_1, *aux_2, *aux_3;
    percorre = *inicio;
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
        aux_1 = *inicio;
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

        *inicio = aux_2;
    }
    return 0;
}