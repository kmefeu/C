#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float delta(float A, float B, float C)

{ /* CALCULO DE DELTA  */

    return (B * B) - 4 * A * C;
}

float bhaskara_mais(float A, float B, float D)

{ /* BAHSKARA -B + DELTA */

    float i;

    if (D < 0)
    {
        return (-(B) + (sqrt(D)) * i) / (2 * A);
    }

    else
    {
        return (-(B) + sqrt(D)) / (2 * A);
    }
}

float bhaskara_menos(float A, float B, float D)

{ /* BAHSKARA -B - DELTA */

    float i;

    if (D < 0)
    {
        return (-(B) - (sqrt(D)) * i) / (2 * A);
    }

    else
    {
        return (-(B)-sqrt(D)) / (2 * A);
    }
}

int main()
{

    system("cls");
    
    float a, b, c, rdelta, x1, x2;

    printf("\n\nBem vindo ao algoritimo de calculo de delta de um equacao de segundo grau ax^2 + bx + c.\n\n");

    printf("\n\nPor favor insira um numero do coeficiente de A (Diferente de 0):");
    scanf("%f", &a);

    if (a == 0)
    {
        printf("\n\nO valor do coeficiente A deve ser diferente de zero!\n\n");
    } /* VERIFICA SE A EH DIFERENTE DE 0 */

    else

    {

        printf("\n\nPor favor insira um numero do coeficiente de B:");
        scanf("%f", &b);

        printf("\n\nPor favor insira um numero do coeficiente de C:");
        scanf("%f", &c);

        rdelta = delta(a, b, c);

        if (rdelta < 0)
        {
            printf("\n\nO valor de delta eh:%0.2fi portanto as raizes, X1 e X2, pertecem aos numeros complexos", rdelta);
        }

        else
        {
            printf("\n\nO valor de delta eh:%0.2f portanto as raizes, X1 e X2, pertecem aos numeros reais e sao valores distintos", rdelta);
        }

        x1 = bhaskara_mais(a, b, rdelta);

        x2 = bhaskara_menos(a, b, rdelta);

        if (rdelta < 0)
        {
            printf("\n\nO valor de X1 eh:%0.2f+i\n\nO valor de X2 eh:%f-i\n\n", x1, x2);
        }

        else
        {
            printf("\n\nO valor de X1 eh:%0.2f\n\nO valor de X2 eh:%f\n\n", x1, x2);
        }

        return 0;
    }
}
