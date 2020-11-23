// Dado um arquivo contendo um conjunto de nomes e datas de nmascimento (dia, mês e ano, isto é, trés inteiros seguidos),
// escrever um programa que leia esse arquivo e a data atual e gere outro arquivo contendo o nome e idade.

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>

void main() {
    setlocale(LC_ALL, "Portuguese");
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
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
    int result, age;

    struct {
        char name[100];
        int age;
    } contactAge;

    FILE *font = fopen("contactList.txt", "r+b");
    FILE *archive = fopen("contactAge.txt", "a+b");
    if(font == NULL){
        printf("It happened a problem to open archive\n");
        getchar();
        exit(1);
    }
     while(!feof(font)){
         age = 0;
        fread(&contact, sizeof(contact),1,font);
        if(feof(font)){
            break;
        }
        printf("Nome: %sTelefone: %sData de Nascimento: %d/%d/%d\n\n", contact.name, contact.telnum, contact.datebirth.day, contact.datebirth.month, contact.datebirth.year);
        strcpy(contactAge.name, contact.name);
        age = tm.tm_year - contact.datebirth.year;
        if(tm.tm_mon < contact.datebirth.month){
            age -= 1;
        } else if (tm.tm_mon == contact.datebirth.month) {
        if (tm.tm_mday < contact.datebirth.day) {
            age -= 1;
         }
        }
        contactAge.age = age + 1900;
        result = fwrite(&contactAge, sizeof(contactAge),1,archive);
       if (result == EOF){
           printf("Erro na gravação!\n");
           exit(1);
           continue;
       }
    }

    fclose(font);
    fclose(archive);
}