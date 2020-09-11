// 5. Considering the structure
// struct vector {float x; y float; float z;
// };
// to represent a vector in R3, implement a program that calculates the sum of two vectors.

// 5. Considerando a estrutura
// struct vetor{ float x; float y; float z;
// };
// para representar um vetor no R3, implemente um programa que calcule a soma de dois vetores.

#include <stdio.h>

struct vector
{
    float x;
    float y;
    float z;
} v[3];

int main()
{

    system("cls");
    
    int i = 0;

    for (i = 0; i < 2; i++)
    {

        printf("\n\nv%d: X Y Z\n\n", i + 1);
        scanf("%f%f%f", &v[i].x, &v[i].y, &v[i].z);
    }

    v[2].x = v[0].x + v[1].x;
    v[2].y = v[0].y + v[1].y;
    v[2].z = v[0].z + v[1].z;

    printf("\n\nv1:(%0.2f,%0.2f,%0.2f)", v[0].x,v[0].y,v[0].z);
    printf("\n\nv2:(%0.2f,%0.2f,%0.2f)", v[1].x,v[1].y,v[1].z);
    printf("\n\n v1 + v2 = v3:(%0.2f,%0.2f,%0.2f)", v[2].x,v[2].y,v[2].z);

    printf("\n\n");

    return 0;
}