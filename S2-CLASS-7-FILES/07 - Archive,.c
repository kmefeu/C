// Faça um programa que permita que o usuário entre com diversos
// nomes e telefone para cadastro. Crie um arquivo com essas informações,
// uma por linha. O usuário finaliza a entrada com o valor 0 para o telefone.


#include <stdio.h>
#include <locale.h>

void main(){

    setlocale(LC_ALL,"Portuguese");

    struct {
        char name[100];
        char telnum[100];
        struct
        {
            int day;
            int month;
            int year;
        }datebirth;
        
    } contact;
    int result, compare;
    FILE *archive = fopen("contactList.txt", "a+b");

    if (archive == NULL){
        printf("it happened a probllem to open archive.\n");
        system("pause");
        exit(1);
    }


    printf("Register to contact\n\n");
    do{
        setbuf(stdin, NULL);
        printf("Enter 0 in telephone number to finish.\n");
        printf("Enter contact name:\n");
        fgets(contact.name, 99, stdin);
        setbuf(stdin, NULL);
        printf("Enter contact telephone number:\n");
        fgets(contact.telnum, 99, stdin);
        compare = strncmp(contact.telnum, "0", 1);
        if(compare == 0){
            break;
        }
        printf("Date of birth:\n");
        printf("Enter month of birth:\n");
        scanf("%d", &contact.datebirth.month);
        printf("Enter day of birth:\n");
        scanf("%d",&contact.datebirth.day);
        printf("Enter year of birth:\n");
        scanf("%d", &contact.datebirth.year);
       result = fwrite(&contact, sizeof(contact),1,archive);
       if (result == EOF){
           printf("Erro na gravação!\n");
           printf("Tente novamente!!\n\n");
           continue;
       }
       printf("Next!\n\n");

    }while(contact.telnum!=0);

    fclose(archive);

    return 0;

    
}