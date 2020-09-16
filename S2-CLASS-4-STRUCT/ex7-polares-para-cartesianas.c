// 7. Make a program that converts polar coordinates to Cartesian:
// Create and read a point in polar coordinate, consisting of radius (r) and argument (a) in radians.

// Create another point, now in Cartesian coordinate, composed of x and y, knowing that x = r ∗ cosa and y = r ∗ sina.
// In the main program, read a point in polar coordinate and show the coordinates of the point generated in the Cartesian plane.

// 7. Fac¸a um programa que converta coordenadas polares para cartesianas:
// Crie e leia um ponto em coordenada polar, composto por raio (r) e argumento (a) em radianos.

// Crie outro ponto, agora em coordenada cartesiana, composto por x e y, sabendo que x = r ∗ cosa e y = r ∗ sina.
// No programa principal, leia um ponto em coordenada polar e mostre as coordenadas do ponto gerado no plano cartesiano.

#include <stdio.h>
#include <math.h>

struct polarCoordinate
{

    float r; // raio

    float a; // angulo

} polar;

struct cartesianCoordinate
{

    float x; // cordenada x

    float y; // cordenada y

} cartesian;

int main()
{
    system("cls");

    printf("Polar coordinate: Radios Angle:\n\n"); // Cordenada polar: Raio Angulo
    scanf("%f %f", &polar.r, &polar.a);

    printf("\n\nRadios:%0.2f Angle:%0.2f", polar.r, polar.a);

    cartesian.x = polar.r * cos(polar.a);
    cartesian.y = polar.r * sin(polar.a);

    printf("\n\nCartesian coordinate: (%0.2f,%0.2f)", cartesian.x, cartesian.y); // Cordenada Cartesiana: (x,y)

    printf("\n\n");

    return 0;
}