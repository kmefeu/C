#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    system("cls");
    
    int contagem = 0, salario_menor_q_100 = 0, filhos = 0, total_filhos = 0, percentual_menor_q_100 = 0;

    float salarios = 0, media_salarios = 0, media_filhos = 0, total_salarios = 0, maior_salario = 0;

    printf("\n\n///---Pesquisa de salarios---///");

    for (contagem = 0; contagem < 3; contagem++)
    {

        printf("\n\nPor favor insira o salario: ");
        scanf("%f", &salarios);

        printf("\n\nPor favor insira o numero de filhos: ");
        scanf("%i", &filhos);

        if (salarios < 100)
        {
            salario_menor_q_100 = salario_menor_q_100 + 1;
        }

        if (salarios > maior_salario)
        {
            maior_salario = salarios;
        }

        total_salarios = total_salarios + salarios;

        total_filhos = total_filhos + filhos;
    }

    media_salarios = total_salarios / contagem;

    media_filhos = total_filhos / contagem;

    percentual_menor_q_100 = (salario_menor_q_100 * 100) / contagem;

    printf("\n\nA media do salario da populacao eh de :R$%0.2f", media_salarios);

    printf("\n\nA media de filhos da populacao eh de :%0.2f", media_filhos);

    printf("\n\nO maior salario eh de :%0.2f", maior_salario);

    printf("\n\nO percentual de pessoas com salario ate R$100 eh de  :%i %%", percentual_menor_q_100);

    printf("\n\nO numero de pessoas com salario ate R$100 eh de  :%i\n\n", salario_menor_q_100);

    return 0;
}