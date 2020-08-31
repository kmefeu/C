#include <stdio.h>

int main()
{
        int dia, mes, ano;

        system("cls");

        printf("\t\t//---DESCUBRA O PROXIMO DIA---//\n\n");

        printf("\t\t//---------INSTRUCOES--------//\n\n");

        printf("\nPor favor digite no formato dia mes ano:\n\n");

        scanf("%i %i %i", &dia, &mes, &ano);

        if (dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12)
        {

                if (dia == 28 || dia == 30 || dia == 31)
                {

                        switch (dia)
                        {
                        case 28:
                                if (mes == 2)
                                {
                                        mes = mes + 1;
                                        dia = 1;
                                };
                                break;

                        case 30:
                                if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
                                {
                                        mes = mes + 1;
                                        dia = 1;
                                };
                                break;

                        case 31:
                                if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 10)
                                {
                                        mes = mes + 1;
                                        dia = 1;
                                }

                                else
                                {
                                        ano = ano + 1;
                                        mes = 1;
                                        dia = 1;
                                };
                                break;
                        }
                }

                else
                        dia = dia + 1;

                printf("\n\n---RESULTADO---\n\nO proximo dia eh:\n\nDia:%i\n\nMes:%i\n\nAno:%i\n\n", dia, mes, ano);
        }

        else
        {
                printf("\n\nValor Invalido!\n\n");
        }

        printf("\n\n");
}