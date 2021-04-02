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
        addVet(v, size, maxSize, e);
        return 1;
        break;
    case 4:
        printf("\nFind element: ");
        scanf("%d", &e);
        find(&v, *size, e);
        return 1;
        break;
    case 5:
        printf("\nChoose element to delete: ");
        scanf("%d", &e);
        removeVet(v, *size, *maxSize, e);
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

void main()
{
    int *v;
    int size, maxSize, m = 1;

    size = 0;
    maxSize = 4;

    printf("Welcome to Application!\n");
    do
    {
        m = menu(&v, &size, &maxSize);

    } while (m == 1);

    printf("\nClosing application");
}

int *initVet(int *size, int *maxSize)
{
    printf("\nNew vector aloced \n");

    // cria/declara um novo ponteiro para um vetor
    int *v = NULL;

    // aloca espaço de memória o novo vetor
    v = malloc((*maxSize + *size) * sizeof(int));

    return &v;
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
        or (int i = 0; i < size; i++)
        {
            printf("%d ", v[i]);
        }
    }
}

int *addVet(int *v, int *size, int *maxSize, int e)
{
    printf("\nsize = %d", *size);
    printf("\nmaxSize = %d", *maxSize);

    if ((*size) >= *maxSize)
    {
        // Se o vetor já está cheio deve ser criado um novo com o dobro do tamanho do atual
        int *newV = malloc((*maxSize * 2) * sizeof(int));

        // após criar o novo vetor com o dobro do tamanho ele recebe todos os valores do antigo
        for (int i = 0; i < *size; i++)
        {
            newV[i] = v[i];
        }

        printf("e = %d\n", e);

        // aqui é adicionado o novo valor no final do vetor
        newV[*size] = &e;
        printf("newV[%d]%d\n", *size, newV[*size]);

        // aqui o valor de maxSize é atualizado
        *maxSize = *maxSize * 2;

        // aqui o valor de sizer é atualizado
        *size = *size + 1;

        // aqui o ponterio antigo recebe o endereço do novo vetor (Não sei se isso funciona)
        v = &newV;
        return v;
    }
    // aqui é quando o vetor não está totalmente ocupado por tanto é possivel adicionar mais um elemento
    else
    {
        // o elemento deve ser adicionado depois do ultimo espaço já ocupado definido pelo tamanho do vetor

        v[*size] = e;

        // aqui o valor de sizer é atualizado
        *size = *size + 1;

        // retorna o mesmo endeço de memoria do vetor(?)
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
    // percore todo o vetor
    for (int i = 0; i < *maxSize; i++)
    {
        // se o valor atual do vetor for igual o valor procurado
        if (v[i] == e)
        {
            free(v[i]);
            *size = *size - 1;
        }
    }

    // Retornar o vetor com as posições atualizadas. Conforme a proptype

    return 1;
}
