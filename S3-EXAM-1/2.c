#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef struct L
{
    int dado;
    char caracter;
    struct L *prox;
} no_ls;

typedef struct Reverse_L
{
    int dado;
    char caracter;
    struct Reverse_L *prox;
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
|               Prototipos das Funcões                |
-----------------------------------------------------*/
///----------|
int AddEl(no_ls **inicio);                              ///A.|
int Mais_Menos(no_ls *inicio);                          ///B.|
int Listar_Mais_Menos();                                ///C.|
int Inverter_ls(no_ls **inicio, Reverse **reverse_ini); ///D.|
int Recursive(no_ls *inicio, int *quant);               ///E.|
///-----------------------------------------------------------------/
int Inicializar_LS(no_ls **inicio);
int Listar_ls(no_ls *inicio);
int Obter_Tamanho_ls(no_ls *inicio, int *tam);
//------------------------------------------------------------------/

int main(void)
{
    int erro, q, quant = 0;
    no_ls *ini;
    Reverse *reverse_ini;
    c.flag = false;
    erro = Inicializar_LS(&ini);
    erro = Inicializar_LS(&reverse_ini);
    do
    {
        system("cls");
        printf("P1 - Estrutura de dados!");
        printf("\n\nOpcoes: \n\n");
        printf("1 -> A) Adicionar 20 elementos a lista!\n");
        printf("2 -> B) Mais e Menos!\n");
        printf("3 -> C) Listar Mais e Menos!\n");
        printf("4 -> D) Inverter lista para uma nova!\n");
        printf("5 -> E) Contagem recursiva!\n");
        printf("6 -> Listar \n:");
        printf("9 -> Sair \n:");

        scanf("%d", &q);
        switch (q)
        {
        case 1:
            erro = AddEl(&ini);
            if (erro == 0)
                printf("Insercao realizada com sucesso\n");
            system("pause");
            break;
        case 2:
            erro = Mais_Menos(ini);
            if (erro == 1)
                printf("Lista vazia!\n");
            system("pause");
            break;
        case 3:
            erro = Listar_Mais_Menos();
            if (erro == 1)
                printf("Execute a opcao 2 antes!\n");
            system("pause");
            break;
        case 4:
            erro = Inverter_ls(&ini, &reverse_ini);
            if (erro == 1)
                printf("Lista vazia!\n");
            system("pause");
            break;

        case 5:
            erro = Recursive(ini, &quant);
            if (erro == 1)
                printf("Lista vazia!\n");
            else
                printf("Existem %d nos com vogais e numeros divisiveis por 10!", quant);
            system("pause");
            break;
        case 6:
            erro = Listar_ls(ini);
            if (erro == 1)
            {
                printf("\nLista vazia. Impossivel listar");
            }
            system("pause");
            break;
        case 9:
            break;
        default:
            printf("\n\n Opcao nao valida");
        }
        getchar();
    } while ((q != 9));

    return 0;
}
///EXERCICIOS!!
///1) A.
int AddEl(no_ls **inicio)
{
    no_ls *aux1;
    no_ls *aux2;
    int i, num;
    char c;

    printf("\nInsira os 20 Elementos! \n");
    for (i = 1; i < 5; i++)
    {
        no_ls *novo_el;
        printf("%d° Elemento: \n", i);
        printf("Dado: \n");
        scanf("%d", &num);
        printf("Caractere: \n");
        fflush(stdin);
        scanf("%c", &c);
        novo_el = (no_ls *)malloc(sizeof(no_ls));
        novo_el->dado = num;
        novo_el->caracter = c;
        if (*inicio == NULL)
        {

            novo_el->prox = NULL;
            *inicio = novo_el;
        }
        else
        {
            no_ls *atual = *inicio;
            no_ls *ant = *inicio;
            while (atual != NULL && atual->dado < novo_el->dado)
            {

                ant = atual;
                atual = atual->prox;
            }

            if (atual == *inicio)
            { // insere no início

                novo_el->prox = *inicio;
                *inicio = novo_el;
            }
            else
            {
                novo_el->prox = ant->prox;
                ant->prox = novo_el;
            }
        }
    }

    return 0;
}

///1) B.
int Mais_Menos(no_ls *inicio)
{
    int i = 0, aux1, cont = 0, cont_Mais = 0, cont_Menos = 1000, Mais, Menos, len;
    no_ls *percorre;
    no_ls *aux2;
    aux2 = inicio;

    if (inicio == NULL)
    {
        return 1;
    }

    while (inicio != NULL)
    {

        aux1 = inicio->dado;
        percorre = aux2;
        while (percorre != NULL)
        {
            if (percorre->dado == aux1)
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
        inicio = inicio->prox;
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
///1) C.
int Listar_Mais_Menos()
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
///1) D.
int Inverter_ls(no_ls **inicio, Reverse **reverse_ini)
{
    int i, len, count = 1;
    no_ls *percorre, *aux_1, *aux_2, *aux_3;
    percorre = *inicio;
    Reverse *no_invertido, *percorre2;
    Obter_Tamanho_LS(*inicio, &len);
    aux_1 = *inicio;

    if (*inicio == NULL)
    {
        return 1;
    }

    else
        while (percorre != NULL)
        {
            aux_1 = *inicio;
            no_invertido = (Reverse *)malloc(sizeof(Reverse));

            for (i = 0; i < len - count; i++)
            {

                aux_1 = aux_1->prox;
            }

            count++;

            no_invertido->dado = aux_1->dado;
            no_invertido->caracter = aux_1->caracter;

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
        printf("\n %d", (*reverse_ini)->dado);
        printf(" %c", (*reverse_ini)->caracter);
        *reverse_ini = (*reverse_ini)->prox;
    }
    printf("\n");
    return 0;
}
///1) E.
int Recursive(no_ls *inicio, int *quant)
{
    char vogais[11] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'}; // size = 10 das vogais
    int size = 10, i;

    if (inicio == NULL)
    {
        return 1;
    }

    for (i = 0; i < size; i++)
    {

        if ((inicio->dado) % 10 == 0)
        {
            if (inicio->caracter == vogais[i])
            {

                *quant = *quant + 1;
            }
        }
    }
    if (inicio->prox == NULL)
    {
        return 0;
    }
    else

        return Recursive((inicio->prox), quant);
}

//Outras funcoes utilizadas para resolucao dos ex!
int Obter_Tamanho_LS(no_ls *inicio, int *tam)
{
    no_ls *percorre;
    *tam = 0;
    if (inicio != NULL)
    {
        percorre = inicio;
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
int Inicializar_LS(no_ls **inicio)
{
    *inicio = NULL;

    return 0; /* sem erro */
}
int Listar_ls(no_ls *inicio)
{
    int i;
    if (inicio == NULL)
    {
        return 1; /* lista vazia */
    }
    printf("LISTA ::  ");
    while (inicio != NULL)
    {
        printf("\n %d", inicio->dado);
        printf(" %c", inicio->caracter);
        inicio = inicio->prox;
    }
    printf("\n");
    return 0; /* sem erro */
}