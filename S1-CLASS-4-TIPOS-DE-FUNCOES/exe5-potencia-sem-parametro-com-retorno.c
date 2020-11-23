// Sem parametro com retorno

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


int pot (){ 
    

printf("\n\nBem vindo ao algoritimo de calculo de potenciação"); 

int base, exp, res;

printf("\n\nInsira a base e depois aperte espaço e insira o expoente: ");
scanf("%i %i", &base, &exp);

res = pow(base, exp);

return res;}



int main (){
    
system ("cls");

setlocale(LC_ALL, "Portuguese");

int res;

res = pot();

printf ("\n\nO resultado da operação foi de %i",res);

printf ("\n\n");


return 0;}