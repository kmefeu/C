//Sem retorno e com parametos

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

 float distancia ( float x1, float x2, float y1, float y2){

float d;


d = sqrt((pow((x2-x1),2)) + (pow((y2-y1),2)));

printf ("\n\n A distancias dos pontos 1 e 2 é de: %f", d);

return 0;}


int main (){

system("cls");

float x1, x2, y1, y2;

printf("\n\nInsira as cordenadas do ponto 1 (de espaço para separar x1 de y1):");
scanf("%f %f", &x1, &y1);

printf("\n\nInsira as cordenadas do ponto 2 (de espaço para separar x2 de y2):");
scanf("%f %f", &x2, &y2);

distancia (x1,x2,y1,y2);


return 0;}