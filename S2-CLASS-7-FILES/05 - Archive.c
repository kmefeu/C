// Faça um programa que leia números positivos e os converta em binário.
// Cada número binário deverá ser salvo em uma linha de um arquivo texto.
// O program termina quando o usuário digitar um número negativo.

#include <stdio.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL,"portuguese");
    FILE *arch;
    int num, sequencia[1000], count=0;

    arch = fopen("registros.txt", "wb");

    if(arch == NULL) {
        printf("Erro ao criar o arquivo");
        exit(1);
    } else {
         do{
            setbuf(stdin, NULL);
            printf("Digite uma sequência de números (Digite número menor que 0 para encerrar a gravação)\n");
            scanf("%d", &num);
            
            if (num < 0){
                printf("Encerrando o programa");
                break;
            }
            fwrite( &num, sizeof(int), 1, arch );

        }while(num>=0);
    } 
    getchar();
    fclose(arch);
    return 0;
}