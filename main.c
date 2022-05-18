#include <stdio.h>
#include <windows.h>

void showGame(char positions[]);
int checkIfWin(char positions[]);

int main()
{
    int end = 0;
    int move = 0;
    int botMove = 0;
    char positions[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

    while (1)
    {

        Sleep(1000);
        showGame(positions);

        end = checkIfWin(positions);
        if (end == 1)
        {
            printf("\nFim de jogo\n");
            break;
        }

        // jogada do jogador
        while (1)
        {
            scanf("%d", &move);

            if (positions[move - 1] != 'X' && positions[move - 1] != 'O')
            {
                positions[move - 1] = 'X';
                break;
            }

            printf("Escolha outro numero\n");
        }

        showGame(positions);

        end = checkIfWin(positions);
        if (end == 1)
        {
            printf("\nFim de jogo\n");
            break;
        }

        // jogada do bot
        botMove = rand() % 9;
        while (1)
        {
            if (positions[botMove - 1] != 'X' && positions[botMove - 1] != 'O')
            {
                positions[botMove - 1] = 'O';
                break;
            }
            else
            {
                botMove++;
                if (botMove >= 10)
                {
                    botMove = 1;
                }
            }
        }
    }
}

void showGame(char positions[])
{
    printf("\n%c/%c/%c\n%c/%c/%c\n%c/%c/%c\n", positions[0], positions[1], positions[2], positions[3], positions[4], positions[5], positions[6], positions[7], positions[8]);
}

int checkIfWin(char positions[])
{
    for (int i = 0; i < 7; i = i + 3)
    {
        if (positions[i] == positions[i + 1] && positions[i + 1] == positions[i + 2])
        {
            if (positions[i] == 'X')
            {
                printf("Voce ganhou!");
                return 1;
            }
            else if (positions[i] == 'O')
            {
                printf("Voce perdeu!");
                return 1;
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        if (positions[i] == positions[i + 3] && positions[i + 3] == positions[i + 6])
        {
            if (positions[i] == 'X')
            {
                printf("Voce ganhou!");
                return 1;
            }
            else if (positions[i] == 'O')
            {
                printf("Voce perdeu!");
                return 1;
            }
        }
    }

    if (positions[0] == positions[4] && positions[4] == positions[8])
    {
        if (positions[0] == 'X')
        {
            printf("Voce ganhou!");
            return 1;
        }
        else if (positions[0] == 'O')
        {
            printf("Voce perdeu!");
            return 1;
        }
    }
    if (positions[2] == positions[4] && positions[4] == positions[6])
    {
        if (positions[2] == 'X')
        {
            printf("Voce ganhou!");
            return 1;
        }
        else if (positions[2] == 'O')
        {
            printf("Voce perdeu!");
            return 1;
        }
    }
    int check = 0;
    for (int i = 0; i < 9; i++)
    {
        if (positions[i] == 'X' || positions[i] == 'O')
        {
            check++;
        }

        if (check == 9)
        {
            printf("Deu velha!");
            return 1;
        }
    }

    return 0;
}