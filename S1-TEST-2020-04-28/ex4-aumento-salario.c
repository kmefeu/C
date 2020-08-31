#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

  system("cls");

  float salario_inicial, salario_final, taxa_aumento = 0.015;

  int ano_referencia, ano_consulta;

  printf("\n\nCalculadora de aumento de salario.\n\n");

  printf("\n\nDigite o salario inicial: ");
  scanf("%f", &salario_inicial);

  printf("\n\nDigite o ano inicial de referencia: ");
  scanf("%i", &ano_referencia);

  printf("\n\nDigite o ano final de consulta: ");
  scanf("%i", &ano_consulta);

  while (ano_referencia <= ano_consulta)
  {

    taxa_aumento = taxa_aumento * 2;

    salario_final = salario_inicial + (taxa_aumento * salario_inicial);

    ano_referencia = ano_referencia + 1;
  }

  printf("\n\nSalario reajustado:R$%f", salario_final);

  printf("\n\n");

  return 0;
}
