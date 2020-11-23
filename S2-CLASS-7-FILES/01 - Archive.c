// Escreva um programa que leia do usuário o nome de um arquivo texto.
// Em seguida, mostre na tela quantas linhas esse arquivo possui.
#include <stdio.h>
#include <string.h>

int main() {
    int numLinhas = 0;
    FILE *descritor;
    char arquivo[50];
    char *caracter;    
    printf("Digite o arquivo que deseja abrir: ");
    gets(arquivo);
    descritor = fopen(arquivo, "r");
    while (!feof(descritor)) {
          fread(caracter, 1, 1, descritor);
          if (*caracter=='\n') {
             numLinhas++;
             }   
   }           
   printf("\nO número de linhas do arquivo é: %d\n", numLinhas);
   getchar();
}

