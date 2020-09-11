// Make a program that makes simple operations of complex numbers:
// Create and read two complex numbers z and w, composed of the real part and the imaginary part.
// Present the sum, subtraction and product between z and w, in that order, as well as the module of both.

// Fac¸a um programa que fac¸a operac¸o˜es simples de nu´meros complexos:
// Crie e leia dois nu´meros complexos z e w, compostos por parte real e parte ima- gina´ria.
// Apresente a soma, subtrac¸a˜o e produto entre z e w, nessa ordem, bem como o mo´dulo de ambos.

#include <stdio.h>

struct complexNumber
{

    float real; // real

    float complex; // complexo

} z, w;

int main()
{

    system("cls");
    
    printf("Insert Z values: R i\n\n");

    scanf("%f %f", &z.real, &z.complex);

    printf("Insert W values: R i\n\n");

    scanf("%f %f", &w.real, &w.complex);

    printf("\n\nZ + W = (%0.2f) + (%0.2fi)", z.real + w.real, z.complex + w.complex);

    printf("\n\nZ - W = (%0.2f) + (%0.2fi)", z.real - w.real, z.complex - w.complex);

    printf("\n\nW - Z = (%0.2f) + (%0.2fi)", w.real - z.real, w.complex - z.complex);

    printf("\n\nZ * W = (%0.2f) + (%0.2fi)", ((z.real * w.real) + (-1*(z.complex * w.complex))), ((z.real * w.complex) + (z.complex * w.real)));

    printf("\n\n");
    
    return 0;
}