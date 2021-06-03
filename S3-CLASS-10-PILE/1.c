#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define tamanho 5

typedef struct Pilha
{
    int Topo;
    char Aluno[tamanho];
} Turma;

int Inicializa_Pilha(Turma *p)
{
    (*p).Topo = -1;
    return 0;
}

int check(Turma p)
{
    if (p.Topo == -1)
        return 0; /* pilha vazia */
    else
    {
        if (p.Topo == tamanho - 1)
            return 1; /* pilha cheia */
        else
            return 2; /* pilha não vazia com capacidade de armazenamento */
    }
}

int Push(Turma *p, int x)
{
    int erro = check(*p);
    if ((erro == 0) || (erro == 2))
    {
        (*p).Topo++;
        (*p).Aluno[(*p).Topo] = x;
        return 0;
    }
    else
        return 1;
}

char Pop(Turma *p) /* POP */
{
    int erro = check(*p);
    if (erro != 0)
    {
        char letra;
        letra = p->Aluno[p->Topo];
        p->Topo--; /* desempilhamento efetuado */
        return letra;
    }
    else
        return 1; /* impossivel desempilhar. Underflow */
}

int listar(Turma p)
{
    int i, erro;
    erro = check(p);
    if ((erro == 1) || (erro == 2))
    {
        for (i = 0; i <= p.Topo; i++)
            printf("%c\\ ", p.Aluno[i]);
        printf(" (Topo)\n");
        return 0;
    }
    else
        return 1; /* nao possivel listar pois a pilha vazia */
}

int main(void)
{
    int erro, q, op, flag = 0, i = 0, j;
    char info, Reconhece[2], Eliminados[tamanho];
    Turma s;
    erro = Inicializa_Pilha(&s);

    do
    {
        system("cls");
        printf("0 -> Gerar dados de entrada\n");
        printf("1 -> Adicionar na pessoa na pilha\n");
        printf("2 -> Desempilha\n");
        printf("3 -> Listar Pilha\n");
        printf("4 -> Procurar Professor\n");
        scanf("%d", &q);

        switch (q)
        {
        case 0:
            int nPessoas = 0;
            printf("Quantas pessoas voce que comparar ?");
            scanf("%d", &nPessoas);
            int matrizRelacao[nPessoas][nPessoas];
            for (int loop = 0; loop < nPessoas; loop++)
            {
                for (int loop2 = 0; loop < nPessoas; loop2++)
                {
                    if (loop != loop2)
                    {
                        printf("\n\nA pessoa %d conhece a pessoa %d ? (1 = S) (2 = N)", loop, loop2);
                        scanf("%d", &matrizRelacao[loop][loop2]);
                    }
                    else
                        matrizRelacao[loop][loop2] = 0;
                }
            }
            for (int loop = 0; loop < nPessoas; loop++)
            {
                for (int loop2 = 0 loop < nPessoas; loop2++)
                {
                    if (loop != loop2)
                    {
                        printf(" %d", matrizRelacao[loop][loop2]);
                    }
                }
                printf("\n\n");
            }

        case 1:
            printf("Inicial do Aluno para insercao na pilha: ");
            fflush(stdin);
            scanf("%c", &info);
            if (isalpha(info) != 0)
            {
                erro = Push(&s, info);
            }
            else
                printf("Insira apenas uma unica letra!\n");
            if (erro == 1)
                printf("\nPilha cheia!");
            system("pause");
            break;

        case 2:
            erro = Pop(&s);
            if (erro == 1)
                printf("\nPilha Vazia!");

            system("pause");
            break;

        case 3:
            erro = listar(s);
            if (erro == 1)
                printf("\nA pilha esta vazia. \n");
            system("pause");
            break;

        case 4:

            if (check(s) != 1)
            {
                printf("\nComplete a turma antes!\n");
                system("pause");
                break;
            }
            else
                do
                {
                    flag = 0;
                    Reconhece[0] = Pop(&s);
                    Reconhece[1] = Pop(&s);

                    if (isalpha(Reconhece[0]) != 0)
                    {
                        flag++;
                        if (isalpha(Reconhece[1]) != 0)
                        {
                            flag++;
                        }
                    }

                    if (flag == 1)
                    {
                        printf("\nSobrou apenas a pessoa : %c\n", Reconhece[0]);
                        printf("\n\n A pessoa '%c' conhecia alguem de sua sala? \n", Reconhece[0]);
                        printf("1 - SIM!\n");
                        printf("2 - NAO!\n");
                        printf("\nlista dos eliminados\n");
                        for (j = 0; j < tamanho - 1; j++)
                        {
                            printf(" - %c\n", Eliminados[j]);
                        }

                        scanf("%d", &op);
                        switch (op)
                        {
                        case 1:
                            printf("\nSe ela conhecia alguem, nesta turma nao havia professor!!\n");
                            system("pause");
                            break;
                        case 2:
                            printf("\nResponda com [1] para SIM e [2] para NAO para quaisquer perguntas a seguir!\n");
                            for (j = 0; j < tamanho - 1; j++)
                            {
                                printf("O eliminado '%c' conhecia o '%c'?\n", Eliminados[j], Reconhece[0]);
                                fflush(stdin);
                                scanf("%d", &op);
                                if (op == 2)
                                {
                                    printf("\nPortanto, se alguem nao conhece o '%c', ele nao pode ser o professor!\n", Reconhece[0]);
                                    return 0;
                                }
                            }
                            printf("\n\nSe todos conheciam '%c', e ele nao conhecia ninguem, ele e o professor da turma!\n", Reconhece[0]);
                            system("pause");
                            break;
                        }
                        break;
                    }

                    if (flag == 2)
                    {

                        printf("\n O aluno '%c' conhece o aluno '%c' ?\n", Reconhece[0], Reconhece[1]);
                        printf("1 - SIM!\n");
                        printf("2 - NAO!\n");
                        scanf("%d", &op);
                        switch (op)
                        {
                        case 1:
                            printf("\nSe '%c' conhece alguem, ele nao e o professor!\n", Reconhece[0]);
                            Eliminados[i] = Reconhece[0];
                            Push(&s, Reconhece[1]);
                            system("pause");
                            break;

                        case 2:
                            printf("\nSe '%c' nao conhece '%c', o '%c' nao pode ser o professor!\n", Reconhece[0], Reconhece[1], Reconhece[1]);
                            Eliminados[i] = Reconhece[1];
                            Push(&s, Reconhece[0]);
                            system("pause");
                            break;
                        }
                        Reconhece[0] = NULL;
                        Reconhece[1] = NULL;
                        i++;
                    }
                } while (check(s) != 1);

            system("pause");
        case 9:
            break;
        default:
            printf("\n\n Opcao invalida\n");
        }
        getchar();
    } while ((q != 9));
    return 0;
}
