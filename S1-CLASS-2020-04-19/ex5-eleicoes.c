#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");

    int candidato01 = 0, candidato02 = 0, candidato03 = 0, candidato04 = 0, voto_nulo05 = 0, voto_branco06 = 0, contagem = 0, voto = 0, eleitor = 0;

    printf("\n\n ---BEM VINDO AS ELEICOES!--- \n\nEscolha de 1 a 4 para escolher seu candidato, 5 para votar nulo e 6 para votar em branco.");

    for (contagem = 0; contagem < 5; contagem++)
    {
        eleitor = eleitor + 1;

        printf("\n\nVoce eh o eleitor de numero: %i", eleitor);

        printf("\n\nPor favor insira o seu voto: ");
        scanf("%i", &voto);

        if (voto == 1 || voto == 2 || voto == 3 || voto == 4 || voto == 5 || voto == 6)
        {

            if (voto == 1)
            {
                candidato01 = candidato01 + 1;
            }
            if (voto == 2)
            {
                candidato02 = candidato02 + 1;
            }
            if (voto == 3)
            {
                candidato03 = candidato03 + 1;
            }
            if (voto == 4)
            {
                candidato04 = candidato04 + 1;
            }
            if (voto == 5)
            {
                voto_nulo05 = voto_nulo05 + 1;
            }
            if (voto == 6)
            {
                voto_branco06 = voto_branco06 + 1;
            }
        }

        else
        {
            contagem = contagem - 1;
            eleitor = eleitor - 1;
            printf("\n\n---ATENCAO!---\nValor invalido! Por Favor digite um numero de 1 a 6\n\n");
        }
    }

    printf("\n\n---RESULTADOS---", candidato01);

    printf("\n\n Candidato numero 1  :%i votos", candidato01);
    printf("\n\n Candidato numero 2  :%i votos", candidato02);
    printf("\n\n Candidato numero 3  :%i votos", candidato03);
    printf("\n\n Candidato numero 4  :%i votos", candidato04);
    printf("\n\n            Nulos    :%i votos", voto_nulo05, voto_branco06);
    printf("\n\n           Branco    :%i votos", voto_nulo05, voto_branco06);
 
    printf("\n\n");

    return 0;
}