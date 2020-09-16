// 12. Choose a card game, based on a “traditional deck” (each card has its suit and its value) or “super trump card” type (each card has a set of attributes). Implement the 2-player card distribution (draw) part, considering that each player will receive 5 cards. Display the cards each player received on the screen.

// 12. Escolha um jogo de cartas, baseado em um “baralho tradicional” (cada carta tem seu naipe e seu valor) ou tipo “super trunfo” (cada carta possui um conjunto de atributos). Implemente a parte de distribuic¸a˜o (sorteio) de cartas para 2 jogadores, considerando que cada jogador ira´ receber 5 cartas. Exiba na tela as cartas que cada um dos jogadores recebeu.

#include <stdio.h>  // Biblioteca para fazer leitura e saida das informações do teclado
#include <string.h> // Biblioteca para fazer operações com strings
#include <locale.h> // Biblioteca para permitir acentos no terminal
#include <time.h>   // Biblioteca para gerar números randomicos
#define n 54

struct card // carta
{
    char name[20]; // nome

    int velocity; // velocidade

    int intelligence; // inteligencia

    int defense; // defesa

    int abiliity; // habilidade

    int strength; // força

} deck[n]; // baralho

int main()
{
    system("cls");
    
    setlocale(LC_ALL, "portuguese");

    int i, ii;

   
   
   
        strcpy(deck[n].name, "Mefeu Super Trunfo");
        deck[n].velocity = 1500;
        deck[n].intelligence = 1500;
        deck[n].defense = 1500;
        deck[n].abiliity = 1500;
        deck[n].strength = 1500;
   
   
    for (i = 0, ii = 0; i < n-1; i++, ii++)
    {

        if (ii == 1)
        {
            strcpy(deck[i].name, "Doug");
        }
        if (ii == 2)
        {
            strcpy(deck[i].name, "Clebão");
        }
        if (ii == 3)
        {
            strcpy(deck[i].name, "Marcião");
        }
        if (ii == 4)
        {
            strcpy(deck[i].name, "Gustavão");
        }
        if (ii == 5)
        {
            strcpy(deck[i].name, "Coelho");
        }
        if (ii == 6)
        {
            ii = 0;
            strcpy(deck[i].name, "Edu");
        }
        if (ii == 7)
        {
            ii = 0;
            strcpy(deck[i].name, "Mefeu");
        }

        deck[i].velocity = (rand() % 1001)+i;
        deck[i].intelligence = (rand() % 1001)+i;
        deck[i].defense = (rand() % 1001)+i;
        deck[i].abiliity = (rand() % 1001)+i;
        deck[i].strength = (rand() % 1001)+i;
    }

    printf("\n\n\n\n-----//=== Player 1 Cards ===// -----");

    for (int i = 0; i < 5; i++)
    {
        ii = (rand() % 55);
        printf("\n\n%s \nPOWER +%d \nVel:%d\nInt:%d\nDef:%d\nAbi:%d\nStr:%d", deck[ii].name,ii, deck[ii].velocity, deck[ii].intelligence, deck[ii].defense, deck[ii].abiliity, deck[ii].strength);
    }

    printf("\n\n\n\n-----//=== Player 2 Cards ===// -----");

    for (int i = 0; i < 5; i++)
    {

        ii = (rand() % 55);
        printf("\n\n%s \nPOWER +%d \nVel:%d\nInt:%d\nDef:%d\nAbi:%d\nStr:%d", deck[ii].name,ii, deck[ii].velocity, deck[ii].intelligence, deck[ii].defense, deck[ii].abiliity, deck[ii].strength);
    }

    printf("\n\n");

    return 0;
}