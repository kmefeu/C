// Faça um vetor char de 100 posições e leia quantas vogáis ele tem

#include <stdio.h>
#include<string.h>

int main (){

    system ("cls");

    int rep, a = 0, e = 0, i = 0, o = 0, u = 0;

    char st[100];

    printf("Escreve uma frase: ");
    fgets(st, 100, stdin);

    
    for (rep = 0 ; rep < strlen(st) ; rep++ ){

      st[rep] = tolower(st[rep]);
      
       if (st[rep] == 'a'){ a = a+1;}
       if (st[rep] == 'e'){ e = e+1;}
       if (st[rep] == 'i'){ i = i+1;}
       if (st[rep] == 'o'){ o = o+1;}
       if (st[rep] == 'u'){ u = u+1;}

    }

    printf("\n");
    printf("Contagem A: %i\n",a);
    printf("Contagem E: %i\n",e);
    printf("Contagem I: %i\n",i);
    printf("Contagem O: %i\n",o);
    printf("Contagem U: %i\n",u);

}