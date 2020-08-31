#include <stdio.h>

int main()
{
        system("cls");
        
        float numero01, numero02;

        char operador;

        printf("\t\t//---CALCULADORA---//\n\n");

        printf("\t\t---INSTRUCOES---\n");

        printf("'+'  : SOMA\n'-'  : SUBTRACAO\n'*'  : MULTIPLICACAO\n'/'  : DIVISAO\n'%%' : RESTO DA DIVISAO\n");

        printf("\nDigite a expressao : numero operador numero\n\n");

        scanf("%f %c %f", &numero01, &operador, &numero02);

        printf("Calculando: %.2f %c %.2f = ", numero01, operador, numero02);

        switch (operador)
        {
        case '+':
                printf("%.2f\n\n", numero01 + numero02);
                break;

        case '-':
                printf("%.2f\n\n", numero01 - numero02);
                break;

        case '*':
                printf("%.2f\n\n", numero01 * numero02);
                break;

        case '/':
                if (numero02 != 0)
                {
                        printf("%.2f\n\n", numero01 / numero02);
                }
                else
                {
                        printf("Nao existe divisao por 0\n\n");
                        break;
                }

        case '%':
                printf("%d\n\n", (int)numero01 % (int)numero02);
                break;

        default:
                if (numero01 != 0 && operador != '0' && numero02 != 0)
                {
                        printf(" Operador invalido\n\n ");
                }
                else
                {
                        printf(" Fechando calculadora!\n ");
                }
        }

        return 0;
}