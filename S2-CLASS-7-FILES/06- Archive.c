// Faça um programa que leia um arquivo texto contendo uma lista de compras.
// Cada linha do arquivo possui o nome, quantidade e valor unitário do produto.
// O programa então exibe o total da compra.

#include <stdio.h>
#include <locale.h>

void main() {
   typedef struct Strucprodutos
    {
        char name[100];
        int qtt;
        float price;
    }produtos;

    FILE *archive = fopen("lista.txt", "a+b");

    int result;
    setlocale(LC_ALL, "Portuguese");
    if (archive == NULL){
        printf("Problema na criação do arquivo \n");
        system("pause");
        exit(1);
    }
    produtos produto;
    printf("**Lista de compras**\n");
    printf("Nome do Produto:\n");
    fgets(produto.name, 99, stdin);
    printf("Quantidade:\n");
    scanf("%d",&produto.qtt);
    printf("Valor unitário do produto");
    scanf("%f",&produto.price);

    result = fwrite(&produto, sizeof(produtos),1,archive);

    if(result== EOF){
        printf("Erro na Gravação do produto");
    }
    fclose(archive);

    archive = fopen("lista.txt", "r+b");
    if( archive == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
        getchar();
    }
    printf("\n\n");
    while(!feof(archive)){
        fread(&produto, sizeof(produto),1, archive);
        if(feof(archive)){
            break;
        }
        printf("Produto:%sQuantidade:%d\nPreço: %.2f\n\n", produto.name, produto.qtt, produto.price);
    }

    fclose(archive);
    return 0;    
}