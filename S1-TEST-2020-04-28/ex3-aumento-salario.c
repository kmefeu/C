#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

  system("cls");

  float salario_inicial = 1000, salario_final, taxa_aumento = 0.015;

  int ano_referencia = 1997, ano_consulta = 2020;

  printf("\n\nCalculadora de aumento de salario de 1997 a 2020.\n\n");

  printf("\n\nDigite o salario inicial: ");
  scanf("%f", &salario_inicial);

  while (ano_referencia <= ano_consulta)
  {

    taxa_aumento = taxa_aumento * 2;

    salario_final = salario_inicial + (taxa_aumento * salario_inicial);

    ano_referencia = ano_referencia + 1;
  }

  printf("\n\nSalario reajustado de 1997 para 2020:R$%.2f", salario_final);

  printf("\n\n");

  return 0;
}