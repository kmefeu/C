#include <stdio.h>
#include <stdlib.h>

// variaveis globais
char jogadorX = 'X', jogadorO = 'O';
char jogo[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void tabuleiro(char jogo[3][3])
{ //gera o tabuleiro do jogo
    system("cls");
    printf("\t  0   1    2\n");
    printf("\t0 %c | %c | %c \n", jogo[0][0], jogo[0][1], jogo[0][2]);
    printf("\t ____________\n");
    printf("\t1 %c | %c | %c \n", jogo[1][0], jogo[1][1], jogo[1][2]);
    printf("\t ____________\n");
    printf("\t2 %c | %c | %c \n", jogo[2][0], jogo[2][1], jogo[2][2]);
}
int verificarJogador(char jogador)
{ //Recebe como parametro o jogador para verificar se ganhou
    if ((jogo[0][0] == jogador && jogo[0][1] == jogador && jogo[0][2] == jogador) || (jogo[1][0] == jogador && jogo[1][1] == jogador && jogo[1][2] == jogador) || (jogo[2][0] == jogador && jogo[2][1] == jogador && jogo[2][2] == jogador) || (jogo[0][0] == jogador && jogo[1][0] == jogador && jogo[2][0] == jogador) || (jogo[0][1] == jogador && jogo[1][1] == jogador && jogo[2][1] == jogador) || (jogo[0][2] == jogador && jogo[1][2] == jogador && jogo[2][2] == jogador) || (jogo[0][0] == jogador && jogo[1][1] == jogador && jogo[2][2] == jogador) || (jogo[0][0] == jogador && jogo[1][1] == jogador && jogo[2][0] == jogador))
    {
        return 1; // caso realizado parametros retornar "true"
    }
    else
        return 0; // caso nao tenha realizado os parametros retornar "false"
}
int executarJogo()
{
    int lin, col, x, jogadas = 0;
    do
    {
        tabuleiro(jogo);
        for (x = 0; x < 3; x++)
        { //sao 9 jogadas
            printf("Selecione a linha desejada de 0 a 2:");
            scanf("%d", &lin);
            printf("selecione a coluna desejada de 0 a 2:");
            scanf("%d", &col);
            if ((lin < 0 || lin > 2) || (col < 0 || col > 2))
            { //verificando cordenadas
                printf("Cordenadas incorretas ou preenchidas \n");
                jogadas -= 1;
            }
            else if ((jogo[lin][col] == jogadorX) || (jogo[lin][col] == jogadorO)) //verificando se a cordenada esta ocupada
            {
                printf("\n casa ocupada \n");
                x -= 1;
                continue; //caso ocupada retorna ao inicio do "do"
            }
            if (jogadas % 2 == 0) //Define qual o jogador
            {
                jogo[lin][col] = jogadorX; //caso par 0,2,4,... jogador X
                jogadas++;
            }
            else
            {
                jogo[lin][col] = jogadorO; // caso impar 1,3,5... jogador O
                jogadas++;
            }
            tabuleiro(jogo); // chama funçao para montar o tabuleiro

            if (verificarJogador(jogadorX)) //Verificar se jogador X venceu
            {
                printf("jogador X ganhou");
                return 0; // Caso venceu finalizar
            }
            else if (verificarJogador(jogadorO)) //Verificar se jogador O venceu
            {
                printf("jogador O ganhou");
                return 0; // Caso venceu finalizar
            }
        }
    } while (x < 3);    //continuar ate 9 rodadas
    printf("DEU VEIA"); //exceder 9 rodadas acabar o jogo
}
int main()
{
    char res;
    printf("\nDeseja jogar ? [S/N]\n");
    scanf("%c", &res);
    if ((res == 's') || (res == 'S'))
    {
        executarJogo();
    }
    else
    {
        return 0; // Caso venceu finalizar "int main()"
    }
}
