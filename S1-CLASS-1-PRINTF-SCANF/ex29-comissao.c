#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    
    float s, v, c,sf;
    
    printf("\nSalario:");
    scanf("%f", &s);

    printf("\nVendas:");
    scanf("%f", &v);
    
    c = (v * 0.4);
    sf  = (s + c);
    
    printf("\nComissao R$%0.2f", c);
    
    printf("\n\nTotal R$%0.2f", sf);

    printf("\n\n");
    
    return 0;
}
