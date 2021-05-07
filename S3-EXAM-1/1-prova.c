/*----------------------------------------------------
|               IMPORTAÇÃO DAS BIBLIOTECAS            |
-----------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------
|               CRIAÇÃO DAS ESTRUTURAS                |
-----------------------------------------------------*/
typedef struct L
{
    int numero;
    char letra;
    struct L *prox;
} listaSimples;

typedef struct Lo
{
    int maisFrequente;
    int maiorFrequencia;
    int menosFrequente;
    int menorFrequencia;

} dadosDeOcorrencia;

/*----------------------------------------------------
|               PROTOTIPOS DAS FUNÇÕES                |
-----------------------------------------------------*/

int inicializar(listaSimples **lista);
int adicionar(int numero, char letra, listaSimples **lista);
int capturarOcorrencia(listaSimples *lista, dadosDeOcorrencia **ocorrencia);
int imprimeLista(listaSimples *lista);
int imprimeOcorrencia(dadosDeOcorrencia *ocorrencia);
int inverterLista(listaSimples *lista, listaSimples **listaInvertida);
int analiseRecursiva(listaSimples *lista);

/*----------------------------------------------------
|               FUNÇÃO PRINCIPAL                      |
-----------------------------------------------------*/

int main(void)
{

    int numero, opcao, resultadoRecursiva;
    char letra;
    listaSimples *original, *invertida;
    dadosDeOcorrencia *ocorrencia;

    printf("P1 LABORATÓRIO DE ESTURUDA DE DADOS");
    printf("MATHEUS CORRÊA RA:202010270");

    do
    {
        system("cls");
        printf("1 A) -> Criar Lista (20 Elementos)\n");
        printf("2 B) -> Capturar Maior Menor\n");
        printf("3 C) -> Imprimir Maior Menor\n");
        printf("4 D) -> Inverter Lista\n");
        printf("5 E) -> Analise Recursiva\n");
        printf("6 F) -> Imprimir Lista\n");
        printf("7 G)-> Fechar\n");
        printf("\n\nOpcoes: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            inicializar(&original);
            for (int i = 0; i < 5; i++)
            {
                printf("\nNumero: ");
                scanf("%d", &numero);
                getchar();
                printf("Letra: ");
                scanf("%c", &letra);
                adicionar(numero, letra, &original);
                imprimeLista(original);
            }
            break;
        case 2:
            printf("\n-> Buscando NUMEROS mais e menos frequentes na lista\n");
            capturarOcorrencia(original, &ocorrencia);
            break;
        case 3:
            imprimeOcorrencia(ocorrencia);
            break;

        case 4:
            inicializar(&invertida);
            printf("\n-> Invertendo lista\n");
            inverterLista(original, &invertida);
            imprimeLista(invertida);
            break;
        case 5:
            printf("\n-> Fazendo analise recursiva\n");
            resultadoRecursiva = analiseRecursiva(original);
            printf("\n-> Resultado: %d", resultadoRecursiva);
            break;
        case 6:
            imprimeLista(original);
            break;
        case 7:
            break;
        default:
            printf("\n\n Opcao nao valida\n");
        }
        printf("\n\n");
        system("pause");
        system("cls");
    } while ((opcao != 7));
}

/*----------------------------------------------------
|               FUNÇÃO INICIALIZAR                   |
-----------------------------------------------------*/

int inicializar(listaSimples **lista)
{
    *lista = NULL;
    return 0;
}

/*----------------------------------------------------
|               FUNÇÃO DE ADICIONAR                   |
-----------------------------------------------------*/

int adicionar(int numero, char letra, listaSimples **lista)
{
    listaSimples *novoNo;
    novoNo = (listaSimples *)malloc(sizeof(listaSimples));
    novoNo->numero = numero;
    novoNo->letra = letra;

    if (*lista == NULL)
    {
        novoNo->prox = NULL;
        *lista = novoNo;
    }
    else
    {
        listaSimples *percorre, *antPercorre;
        percorre = *lista;
        antPercorre = *lista;

        while (novoNo->numero > percorre->numero && percorre != NULL)
        {
            antPercorre = percorre;
            percorre = percorre->prox;
        }
        if (percorre == *lista)
        {
            novoNo->prox = *lista;
            *lista = novoNo;
        }
        else
        {
            novoNo->prox = antPercorre->prox;
            antPercorre->prox = novoNo;
        }

        return 0;
    }
}

/*----------------------------------------------------
| FUNÇÃO DE CAPTURAR NUMEROS MAIS E MENOS FREQUENTES  |
-----------------------------------------------------*/

int capturarOcorrencia(listaSimples *lista, dadosDeOcorrencia **ocorrencia)
{

    int maisFrequente = NULL,
        maiorFrequencia = 0,
        menosFrequente = NULL,
        menorFrequencia = 0,
        frequenciaEmComparacao = 0,
        numeroEmComparacao = NULL;

    listaSimples *percorre1, *percorre2;
    percorre1 = lista;
    percorre2 = lista;

    maisFrequente = percorre1->numero;
    menosFrequente = percorre1->numero;

    while (percorre1 != NULL)
    {
        numeroEmComparacao = percorre1->numero;
        frequenciaEmComparacao = 0;
        percorre2 = lista;

        while (percorre2 != NULL)
        {
            printf("\n %d == %d", numeroEmComparacao, percorre2->numero);
            if (numeroEmComparacao == percorre2->numero)
            {

                frequenciaEmComparacao = frequenciaEmComparacao + 1;
                printf("\n contador == %d", frequenciaEmComparacao++);
            }
            percorre2 = percorre2->prox;
        }

        if (maiorFrequencia < frequenciaEmComparacao)
        {
            maiorFrequencia = frequenciaEmComparacao;
            maisFrequente = numeroEmComparacao;
        }
        if (menorFrequencia > frequenciaEmComparacao && frequenciaEmComparacao == 0)
        {
            menorFrequencia = frequenciaEmComparacao;
            menosFrequente = numeroEmComparacao;
        }
        percorre1 = percorre1->prox;
    }

    dadosDeOcorrencia *novaCapturaDeOcorrencia;
    novaCapturaDeOcorrencia = (dadosDeOcorrencia *)malloc(sizeof(dadosDeOcorrencia));

    novaCapturaDeOcorrencia->maisFrequente = maisFrequente;
    novaCapturaDeOcorrencia->maiorFrequencia = maiorFrequencia;
    novaCapturaDeOcorrencia->menosFrequente = menosFrequente;
    novaCapturaDeOcorrencia->menorFrequencia = menorFrequencia;

    *ocorrencia = novaCapturaDeOcorrencia;

    return 0;
}

/*----------------------------------------------------
|                  IMRPIME LISTA                      |
-----------------------------------------------------*/

int imprimeLista(listaSimples *lista)
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
    printf("\n");
    return 0; /* sem erro */
}

/*----------------------------------------------------
|               IMRPIME OCORRENCIAS                   |
-----------------------------------------------------*/

int imprimeOcorrencia(dadosDeOcorrencia *ocorrencia)
{
    printf("\nMais Frequente: %d [%d]", ocorrencia->maisFrequente, ocorrencia->maiorFrequencia);
    printf("\nMenos Frequente: %d [%d]", ocorrencia->menosFrequente, ocorrencia->menorFrequencia);
}

/*----------------------------------------------------
|               CRIA LISTA INVERTIDA                  |
-----------------------------------------------------*/

int inverterLista(listaSimples *lista, listaSimples **listaInvertida)
{
    listaSimples *percorre, *aux_1, *aux_2, *aux_3;
    percorre = lista;
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
        aux_1 = lista;
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

        *listaInvertida = aux_2;
    }
    return 0;
}

/*----------------------------------------------------
|                 ANALISE RECURSIVA                   |
-----------------------------------------------------*/

int recursiva(listaSimples *percorre, char vogais[], int *contador)
{

    if (percorre->prox != NULL)
    {
        int eVogal = 0;

        for (int i = 0; i < 10; i++)
        {
            if (vogais[i] == percorre->letra)
            {
                eVogal = 1;
                break;
            }
        }

        int resto;
        resto = percorre->numero % 10;

        printf("\nPegou o resto = %d", resto);

        if (resto == 0 && eVogal == 1)
        {
            *contador++;
            printf("\ncontador++");
        }

        percorre = percorre->prox;
        printf("\navancou percorre");

        if (percorre->prox != NULL)
        {
            printf("\nchegou pra chamar a recursiva");
            recursiva(percorre, vogais, contador);
        }
    }
}
int analiseRecursiva(listaSimples *listaAnalisada)
{
    int *contador = 0;
    char vogais[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    listaSimples *percorre;
    percorre = listaAnalisada;
    recursiva(percorre, vogais, contador);

    return *contador;
}