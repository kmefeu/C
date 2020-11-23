// Um arquivo texto possui uma matriz de valores inteiroes dentro dele.
// Os dois primeiros números são as dimensões da matriz (linhas e colunas), enquanto
// o restante dos números são os valores de cada elemento da matriz. Escreva uma funçõa
// que receba o nome do arquivo e retorne o ponteiro para uma matriz alocada dinamicamente contendo os valores
// lidos do arquivo.

#include <stdio.h>
#include <locale.h>

int **AlocaMatriz(int m, int n){
  int **M;
  int i;
 
  M = (int **)malloc(sizeof(int *)*m);
  if(M == NULL){
    printf("Memoria insuficiente.\n");
    exit(1);
  }
  for(i = 0; i < m; i++){
    M[i] = (int *)malloc(sizeof(int)*n);
    if(M[i] == NULL){
      printf("Memoria insuficiente.\n");
      exit(1);
    }
  }
  return M;
}

int main() {
    FILE *archive;
    char archivename[100];
    int **matriz, linha, coluna, i, j;
    printf("Digite o nome do arquivo contendo a matriz:\n");
    scanf("%s",&archivename);
    archive = fopen("matriz.txt", "r");
    // printf("%c\n", fgetc(archive));
    if(archive == NULL){
        printf("It happened a problem to open archive\n");
        getchar();
        exit(1);
    }
    while(!feof(archive)){
        linha = (int)fgetc(archive) - 48;
        coluna = (int)fgetc(archive) - 48;
        matriz = AlocaMatriz(linha, coluna);
        for (i = 0; i < linha; i++)
        {
            for (j = 0; j < coluna; j++)
            {
                matriz[i][j] = (int)fgetc(archive) - 48;
            }
        }    

        fgetc(archive);
         if(feof(archive)){
            break;
        }
    }

    printf("Leitura realiza.\n");
    printf("A Matriz tem a seguinte configuração.\n");
    printf("MATRIZ %dx%d:\n",linha,coluna);
    for (i = 0; i < linha ; i++)
    {
        for ( j = 0; j < coluna; j++)
        {
           printf("%d ", matriz[i][j]);
        }
        printf("\n");        
    }
    fclose(archive);
    return 0;    
}