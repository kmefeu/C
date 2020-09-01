//Algoritimo de calculo de media do semestre para 3 provas para 5 alunos

#include <stdio.h>
#include <stdlib.h>

int main()
{

    system("cls");
    
    float aluno1 = 0, aluno2 = 0, aluno3 = 0, aluno4 = 0, aluno5 = 0, p1, p2, p3, media;

    int contagem = 0, raaluno = 0;

    for (contagem = 1; contagem <= 5; contagem++)
    {

        raaluno = raaluno + 1;

        printf("\n\n Aluno N%i Nota P1:", raaluno);
        scanf("%f", &p1);

        printf("\n\n Aluno N%i Nota P2:", raaluno);
        scanf("%f", &p2);

        printf("\n\n Aluno N%i Nota P3:", raaluno);
        scanf("%f", &p3);

        media = (p1 + p2 + p3) / 3;

        if (contagem == 1)
        {
            aluno1 = media;
        }
        if (contagem == 2)
        {
            aluno2 = media;
        }
        if (contagem == 3)
        {
            aluno3 = media;
        }
        if (contagem == 4)
        {
            aluno4 = media;
        }
        if (contagem == 5)
        {
            aluno5 = media;
        }
    }

    printf("\n\n---RESULTADO---");

    printf("\n\nAluno 1 Media:%0.2f", aluno1);
    printf("\n\nAluno 2 Media:%0.2f", aluno2);
    printf("\n\nAluno 3 Media:%0.2f", aluno3);
    printf("\n\nAluno 4 Media:%0.2f", aluno4);
    printf("\n\nAluno 5 Media:%0.2f", aluno5);

    return 0;
}