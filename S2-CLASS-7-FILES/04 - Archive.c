// Elabore um programa no qual o usuário informe o nome de um arquivo
// texto e uma palavra, e o programa informe o número de vezes que aquela
// palavra aparece dentro do arquivo


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void main(){
    FILE *arch;
    char name[100], search[100], line[1000];
    int done = 0, i = 0;

    printf("Enter archive name, do you will go modification \n");
    scanf("%s", &name);
    printf("Now, enter word or letter, you do want searching\n");
    scanf("%s", &search);

    arch = fopen(name, "r");

	search[strlen(search) -1] = 0;    
	do{
        fgets(line, 1000, arch);        
		i++;        
		if(strstr(line, search) != NULL){
            printf("Linha %d: %s", i, line);            
			done++;        
		}    
	}while(!feof(arch));
	if(done == 0)printf("Nao foi encontrada a string");
    return 0;
}