// Escreva uma função que receba como parâmetro o nome de um arquivo texto
//  e retorne qunatas vogais esse arquivo possui.

#include <stdio.h>
#include <locale.h>
#include <string.h>

void main() {
    setlocale(LC_ALL, "Portuguese");

    char archive[100];
    char letra;
    int qtt=0;
    printf("Digite nome do arquivo a ser analisado (ex: arquivotexto.TXT)\n");
    scanf("%s", &archive);
    FILE *analise = fopen(archive, "r");
    
    if(analise == NULL){
        printf("It happened a problem to open archive\n");
        getchar();
        exit(1);
    }
    printf("Abriu o arquivo\n");
     while( (letra = fgetc(analise)) != EOF ) {
        if(letra =='a' || letra =='e' || letra =='i' || letra =='o' || letra =='u')qtt++;
    }
    
    printf("\n\nA quantidade de vogais contidas nesse arquivo é = %d\n\n", qtt);
    fclose(analise);
    return 0;

}
