#include <stdio.h>
#include <string.h>

int main()
{

    system("cls");

    char login[10] = "Matheus", senha[10] = "Correa", login_in[10], senha_in[10];

    int ind, corespondencia_login = 0, corespondencia_senha = 0, digitos_login = strlen(login), digitos_senha = strlen(senha);

    printf("\n\nLogin:");
    fgets(login_in, 10, stdin);
    //Leitura Login

    if (strlen(login) == strlen(login_in) - 1)
    {

        printf("\n\nSenha:");
        fgets(senha_in, 10, stdin);
        // Leitura Senha

        if (strlen(senha) == strlen(senha_in) - 1)
        {

            for (ind = 0; ind < digitos_login; ind++)
            {
                if (login[ind] == login_in[ind])
                {
                    corespondencia_login = corespondencia_login + 1;
                }
            }
            // FOR login - Compraração de indice uma a um.

            for (ind = 0; ind < digitos_senha; ind++)
            {
                if (senha[ind] == senha_in[ind])
                {
                    corespondencia_senha = corespondencia_senha + 1;
                }
            }
            // FOR senha - Compraração de indice uma a um.

            // Caso nescessário verificar algum valor salvo na memoria tirar o //

            //printf("\n%s",login);
            //printf("\n%s",login_in);
            //printf("\n%d",digitos_login);
            //printf("\n%i",corespondencia_login);
            //printf("\n-----------\n");
            //printf("\n%s",senha);
            //printf("\n%s",senha_in);
            //printf("\n%d",digitos_senha);
            //printf("\n%i",corespondencia_senha);

            if (digitos_login == corespondencia_login && digitos_senha == corespondencia_senha)
            {
                printf("\n\n\t\t\t---!---Acesso Permitido---!---");
                printf("\n\n\n");
            }
            // IF Validação de login e senha.

            else
            {
                printf("\n\n\t\t\t---!---Login ou senha invalidos---!---");
                printf("\n\n\n");
            }
            // ELSE Validação de login e senha.

        } //IF senha

        else
        {
            printf("\n\n\t\t\t---!---Senha invalida---!---");
            printf("\n\n");
        } // ELSE senha

    } //IF login

    else
    {
        printf("\n\n\t\t\t---!---Login invalido---!---");
        printf("\n\n");
    } // ELSE login

    return 0;
}