#include <stdio.h>
#include <stdlib.h>

int *initVet(int *size, int *maxSize);

void printVet(int *v, int size, int maxSize);

int *addVet(int *v, int *size, int *maxSize, int e);

int find(int *v, int size, int e);

int *removeVet(int *v, int *size, int *maxSize, int e);

int menu(int *v, int *size, int *maxSize)
{
    int option, e;

    printf("\n Select a option \n");
    printf("1 - New vector\n");
    printf("2 - Show vector\n");
    printf("3 - Add new element in vector\n");
    printf("4 - Find element in vector\n");
    printf("5 - Delete element in vector\n");
    printf("6 - Finish work\nOption:");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        v = initVet(size, maxSize);
        return 1;
        break;
    case 2:
        printVet(v, *size, *maxSize);
        return 1;
        break;
    case 3:
        printf("\nNew element: ");
        scanf("%d", &e);
        v = addVet(v, size, maxSize, e);
        return 1;
        break;
    case 4:
        printf("\nFind element: ");
        scanf("%d", &e);
        find(v, *size, e);
        return 1;
        break;
    case 5:
        printf("\nChoose element to delete: ");
        scanf("%d", &e);
        v = removeVet(v, (int *)*size, (int *)*maxSize, e);
        return 1;
        break;
    case 6:
        return 0;
        break;
    default:
        printf("\nPlease, insert a valid option!");
        return 1;
        break;
    }
}

int main()
{
    int *v;
    int size, maxSize, m = 1;

    size = 0;
    maxSize = 4;

    printf("Welcome to Application!\n");
    do
    {
        m = menu((int *)&v, &size, &maxSize);

    } while (m == 1);

    printf("\nClosing application");

    return 0;
}

int *initVet(int *size, int *maxSize)
{
    printf("\nNew vector aloced \n");

    // cria/declara um novo ponteiro para um vetor
    int *v = NULL;

    // aloca espaço de memória o novo vetor
    v = (int *)malloc((*maxSize + *size) * sizeof(int));

    return v;
}

void printVet(int *v, int size, int maxSize)
{

    if (size == 0)

    {
        // imprime essa mensagem quando o tamanho do vetor é igual a zero
        printf("\nsize = %d\n", size);
        printf("Empty vector!\n");
    }
    else
    {

        // imprime cada valor dentro do vetor
        for (int i = 0; i < size; i++)
        {
            printf("%d ", v[i]);
        }
    }
}

int *addVet(int *v, int *size, int *maxSize, int e)
{
    printf("\nsize = %d", *size);
    printf("\nmaxSize = %d\n", *maxSize);

    if ((*size) >= *maxSize)
    {
        // Se o vetor já está cheio deve ser criado um novo com o dobro do tamanho do atual
        int *newV = NULL;
        newV = (int *)malloc(((*maxSize) * 2) * sizeof(int));

        // após criar o novo vetor com o dobro do tamanho ele recebe todos os valores do antigo
        for (int i = 0; i < *size; i++)
        {
            newV[i] = v[i];
        }

        printf("\ne = %d\n", e);

        // aqui é adicionado o novo valor no final do vetor
        newV[*size] = e;
        printf("\nnewV[%d]%d\n", *size, newV[*size]);

        // aqui o valor de maxSize é atualizado
        *maxSize = *maxSize * 2;

        // aqui o valor de sizer é atualizado
        *size = *size + 1;

        // retorna o novo vetor
        return newV;
    }
    // aqui é quando o vetor não está totalmente ocupado por tanto é possivel adicionar mais um elemento
    else
    {
        // o elemento deve ser adicionado depois do ultimo espaço já ocupado definido pelo tamanho do vetor

        v[*size] = e;

        // aqui o valor de sizer é atualizado
        *size = *size + 1;

        // retorna o mesmo endeço de memoria do vetor
        return v;
    }
}

int find(int *v, int size, int e)
{
    // percore todo o vetor
    for (int i = 1; i < size + 1; i++)
    {
        // se o valor atual do vetor for igual o valor procurado
        if (v[i] == e)
        {

            // imprima a sua posição no vetor
            printf("\nElement found v[%i]\n", i);

            // retorna sua posição no vetor
            return i;
        }
    }

    printf("\nElement not found.\n");
    return -1;
}

int *removeVet(int *v, int *size, int *maxSize, int e)
{
    int foundAt;
    // percore todo o vetor
    for (int i = 0; i < *size; i++)
    {
        // se o valor atual do vetor for igual o valor procurado
        if (v[i] == e)
        {
            //guarda a posição da ocorrencia
            foundAt = i;
            // verifica se o vetor vai ficar menor do 1/4 do total de memória alocada depois de retirar o valor pedido
            if ((*size - 1) <= (*maxSize / 4))
            {
                int *newV = NULL;
                // aloca no vetor newV um vetor duas vezes menor que o vetor anterior
                newV = (int *)malloc((*maxSize / 2) * sizeof(int));
                // percore todo o vetor antigo para passar os valores para o novo porem retirando o valor E solicitado
                for (int i = 0, j = 0; j < *size; i++, j++)
                {
                    if (i != foundAt)
                    {
                        newV[i] = v[j];
                    }
                    else
                    {
                        j++;
                    }
                }
                // atualiza o tamanho de maxSize
                *maxSize = (*maxSize / 2);
                // atualiza o tamanho de size
                *size = *size - 1;

                printf("\nElement deleted.\n");

                // retorna o endereço do novo vetor sem o elemento e com o maxSize menor
                return newV;
            }
            else
            {
                int *newV = NULL;
                newV = (int *)malloc((*maxSize) * sizeof(int));
                // percore todo o vetor antigo para passar os valores para o novo porem retirando o valor E solicitado
                for (int i = 0, j = 0; j < *size; i++, j++)
                {
                    if (i != foundAt)
                    {
                        newV[i] = v[j];
                    }
                    else
                    {
                        j++;
                    }
                }
                // atualiza o tamanho de size
                *size = *size - 1;

                printf("\nElement deleted.\n");

                // retorna o endereço do novo vetor sem o elemento
                return newV;
            }
        }
    }
    printf("\nElement not found.\n");
    return v;
}