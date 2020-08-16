/*
Desenvolva o famoso jogo da forca, onde o sistema deverá permitir o cadastro da palavra a ser 
adivinhada. Deverá ainda contar as tentativas de erros e acertos criando um ranking dos melhores.
O sistema deverá conter um menu interativo para começar um novo jogo, consultar os rankings e 
fornecer ajuda ao usuário caso necessário. Usar funções, ponteiros e escrita/leitura em
arquivos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


void OS();
void display(int displayType);
void option();
void newGame();
void registerWord();
void storeRank(char *player, int *err, int wordSize);
void orderRank();
void showRank();
void help();

int os;
char word[100];

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    display(1);

    OS();

    while (1)
    {
        option();
    }

    return 0;
}

void OS()
{
    display(3);

    printf("\nInsira o valor corespondente ao seu SO: ");
    scanf("%d", &os);

    getchar();

    if (os == 1)
    {
        system("cls");
    }
    else if (os == 2)
    {
        system("clear");
    } else
    {
        printf("\nERRO NO OS\n");
        sleep(2);
        exit(1);
    }
}

void display(int displayType)
{
    switch (displayType)
    {
    case 1:
        printf("************************************\n");
        printf("*    Bem-vindo ao Jogo da Forca    *\n");
        printf("************************************\n");
        break;
    
    case 2:
        printf("************************************\n");
        printf("*        Menu de Utilização        *\n");
        printf("*                                  *\n");
        printf("*       1. Começar Novo Jogo       *\n");
        printf("*       2. Listar Ranking          *\n");
        printf("*       3. Ajuda                   *\n");
        printf("*       4. Sair                    *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        break;

    case 3:
        printf("************************************\n");
        printf("* Sistemas Operacionais Suportados *\n");
        printf("*                                  *\n");
        printf("*            1 - Windows           *\n");
        printf("*            2 - Linux             *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        break;

    case 4:
        printf("************************************\n");
        printf("*      Cadastrar Nova Palavra      *\n");
        printf("************************************\n");
        break;

    case 5:
        printf("************************************\n");
        printf("*        Palavra Cadastrada        *\n");
        printf("************************************\n");
        break;

    case 6:
        printf("************************************\n");
        printf("*   _______                        *\n");
        printf("*  |/      |                       *\n");
        printf("*  |                               *\n");
        printf("*  |                               *\n");
        printf("*  |                               *\n");
        printf("*  |                               *\n");
        printf("*  |                               *\n");
        printf("* _|___                            *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        break;

    case 7:
        printf("************************************\n");
        printf("*   _______                        *\n");
        printf("*  |/      |                       *\n");
        printf("*  |       O                       *\n");
        printf("*  |                               *\n");
        printf("*  |                               *\n");
        printf("*  |                               *\n");
        printf("*  |                               *\n");
        printf("* _|___                            *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        break;

    case 8:
        printf("************************************\n");
        printf("*   _______                        *\n");
        printf("*  |/      |                       *\n");
        printf("*  |       O                       *\n");
        printf("*  |       |                       *\n");
        printf("*  |       |                       *\n");
        printf("*  |                               *\n");
        printf("*  |                               *\n");
        printf("* _|___                            *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        break;

    case 9:
        printf("************************************\n");
        printf("*   _______                        *\n");
        printf("*  |/      |                       *\n");
        printf("*  |       O                       *\n");
        printf("*  |       |                       *\n");
        printf("*  |       |                       *\n");
        printf("*  |        \\                       *\n");
        printf("*  |                               *\n");
        printf("* _|___                            *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        break;

    case 10:
        printf("************************************\n");
        printf("*   _______                        *\n");
        printf("*  |/      |                       *\n");
        printf("*  |       O                       *\n");
        printf("*  |       |                       *\n");
        printf("*  |       |                       *\n");
        printf("*  |      / \\                      *\n");
        printf("*  |                               *\n");
        printf("* _|___                            *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        break;

    case 11:
        printf("************************************\n");
        printf("*   _______                        *\n");
        printf("*  |/      |                       *\n");
        printf("*  |       O                       *\n");
        printf("*  |      \\|                       *\n");
        printf("*  |       |                       *\n");
        printf("*  |      / \\                      *\n");
        printf("*  |                               *\n");
        printf("* _|___                            *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        break;

    case 12:
        printf("************************************\n");
        printf("*   _______                        *\n");
        printf("*  |/      |                       *\n");
        printf("*  |       O                       *\n");
        printf("*  |      \\|/                      *\n");
        printf("*  |       |                       *\n");
        printf("*  |      / \\                      *\n");
        printf("*  |                               *\n");
        printf("* _|___                            *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        break;

    case 13:
        printf("************************************\n");
        printf("*      Número Máximo de Erros      *\n");
        printf("*           FIM DE JOGO            *\n");
        printf("************************************\n");
        break;

    case 14:
        printf("************************************\n");
        printf("*           PARABÉNS!!!            *\n");
        printf("*      Você Acertou a Palavra      *\n");
        printf("************************************\n");
        break;

    case 15:
        printf("************************************\n");
        printf("*      Encerrando o Programa       *\n");
        printf("************************************\n");
        break;

    case 16:
        printf("************************************\n");
        printf("*    Como Jogar o Jogo da Forca    *\n");
        printf("************************************\n");
        printf("************************************\n");
        printf("*                                  *\n");
        printf("*   Primeiramente, um jogador deve *\n");
        printf("* registrar uma palavra para que o *\n");
        printf("* outro jogador tente adivinhar.   *\n");
        printf("*   Depois, o outro jogador insere *\n");
        printf("* uma letra, se a palavra escolhida*\n");
        printf("* conter essa letra, será revelada *\n");
        printf("* a posição da respectiva letra.   *\n");
        printf("*   Caso o jogador insira uma letra*\n");
        printf("* que não está na palavra, ele terá*\n");
        printf("* um erro.                         *\n");
        printf("*   O jogo acaba quando o jogador  *\n");
        printf("* completar a palavra ou atingir 7 *\n");
        printf("* erros.                           *\n");
        printf("*                                  *\n");
        printf("************************************\n");
        break;

    default:
        printf("\nERRO NO DISPLAY\n");
        sleep(2);
        exit(5);
        break;
    }
}

void option()
{
    int option;

    display(2);

    printf("\nDigite a opção desejada: ");
    scanf("%d", &option);

    getchar();

    if (os == 1)
    {
        sleep(1);
        system("cls");
    } else if (os == 2)
    {
        sleep(1);
        system("clear");
    }

    switch (option)
    {
    case 1:
        newGame();
        break;

    case 2:
        showRank();
        break;

    case 3:
        help();
        break;

    case 4:
        display(15);
        sleep(2);

        if (os == 1)
        {
            system("cls");
        } else if (os == 2)
        {
            system("clear");
        }

        exit(0);
        break;
    
    default:
        printf("\nOpção Inexistente!\n");

        if (os == 1)
        {
            sleep(1);
            system("cls");
        } else if (os == 2)
        {
            sleep(1);
            system("clear");
        }

        break;
    }
}

void newGame()
{
    int i, correct = 0, err = 0, end = 0, correctAux = 0;
    char letter, player[100], secretWord[100], secretWordAux[2];

    printf("\nInsira o Nome do Jogador: ");
    fgets(player, 100, stdin);
    strtok(player, "\n");

    sleep(1);

    if (os == 1)
    {
        system("cls");
    }
    else if (os == 2)
    {
        system("clear");
    }

    registerWord();

    for (i = 0; i < strlen(word); i++)
    {
        secretWord[i] = '_';
    }

    while (end == 0)
    {
        display(err + 6);

        printf("\n");

        for (i = 0; i < strlen(word); i++)
        {
            printf("%c ", secretWord[i]);
        }

        printf("\n");
        
        printf("\nInsira uma letra: ");
        scanf("%c", &letter);

        getchar();

        for (i = 0; i < strlen(word); i++)
        {
            if (toupper(letter) == word[i])
            {
                secretWord[i] = toupper(letter);

                correct++;
            }
        }

        if (correct == 0)
        {
            err++;

            printf("\nLETRA INCORRETA\n");

            if (err == 7)
            {                
                end = 1;

                if (os == 1)
                {
                    system("cls");
                }
                else if (os == 2)
                {
                    system("clear");
                }

                display(12);

                printf("\n");

                display(13);

                printf("\nA Palavra era: %s\n", word);

                storeRank(player, &err, strlen(word));

                printf("Pressione \"enter\" para continuar\n");
                getchar();
            }
        } else
        {
            correctAux += correct;
            correct = 0;

            printf("\nLETRA CORRETA\n");

            if (correctAux == strlen(word))
            {
                end = 1;

                if (os == 1)
                {
                    system("cls");
                }
                else if (os == 2)
                {
                    system("clear");
                }

                display(err + 6);

                printf("\n");

                display(14);

                printf("\nA Palavra era: %s\n", word);

                storeRank(player, &err, strlen(word));

                printf("Pressione \"enter\" para continuar\n");
                getchar();
            }
        }

        sleep(1);

        if (os == 1)
        {
            system("cls");
        }
        else if (os == 2)
        {
            system("clear");
        }
    }
}

void registerWord()
{
    int i;

    display(4);

    printf("\nInsira uma palavra (sem acentos): ");
    fgets(word, 100, stdin);
    strtok(word, "\n");

    for (i = 0; i < strlen(word); i++)
    {
        word[i] = toupper(word[i]);
    }

    printf("\n");

    display(5);
    sleep(1);

    if (os == 1)
    {
        system("cls");
    }
    else if (os == 2)
    {
        system("clear");
    }
}

void storeRank(char *player, int *err, int wordSize)
{
    FILE *rank;

    rank = fopen("rank.txt", "a");

    if (rank == NULL)
    {

        printf("\nERRO NA ATUALIZAÇÃO DO RANK\n");
        sleep(2);
        exit(1);

    } else
    {
        fprintf(rank, "%s\n", player);
        fprintf(rank, "%d\n", *err);
        fprintf(rank, "%d\n", wordSize);

        fclose(rank);  
    }

    orderRank();

    printf("\nRanking Atualizado\n\n");
}

void showRank()
{
    FILE *rank;
    char c, line[100];
    int lineCount = 0, i;

    rank = fopen("rank.txt", "r");

    if(rank == NULL)
    {
        printf("\nNão Foi Possível Encontrar o Ranking\n\n");
    } else
    {
        printf("\nPOSIÇÃO  -  JOGADOR  -  ERROS  -  TAMANHO DA PALAVRA\n\n");

        rewind(rank);

        c = fgetc(rank);

        while (c != EOF)
        {
            if (c == '\n')
            {
                lineCount++;
            }

            c = fgetc(rank);
        }

        rewind(rank);

        for (i = 0; i < lineCount / 3; i++)
        {
            printf("%d°", i + 1);

            printf("  -  ");

            fgets(line, 100, rank);
            strtok(line, "\n");
            printf("%s", line);

            printf("  -  ");

            fgets(line, 100, rank);
            strtok(line, "\n");
            printf("%s", line);

            printf("  -  ");

            fgets(line, 100, rank);
            strtok(line, "\n");
            printf("%s", line);

            printf("\n");
        }

        printf("\n");

        fclose(rank);
    }

    printf("Pressione \"enter\" para continuar\n");
    getchar();

    if (os == 1)
    {
        system("cls");
    }
    else if (os == 2)
    {
        system("clear");
    }
}

void orderRank()
{
    FILE *rank, *temp;
    char line[100], c;
    int i, j, aux, lineCount = 0, errors[100], pointerPosition;

    rank = fopen("rank.txt", "r");
    temp = fopen("temp.txt", "w");

    if ((rank == NULL) || (temp == NULL))
    {
        printf("\nERRO AO MODIFICAR O RANK\n");
        sleep(2);
        exit(1);
    } else
    {
        rewind(rank);

        c = fgetc(rank);

        while (c != EOF)
        {
            if (c == '\n')
            {
                lineCount++;
            }

            c = fgetc(rank);
        }

        rewind(rank);

        for (i = 0; i < lineCount / 3; i++)
        {
            fgets(line, 100, rank);
            fgets(line, 100, rank);
            strtok(line, "\n");
            errors[i] = atoi(line);
            fgets(line, 100, rank);
        }

        for (i = 0 ; i < (lineCount / 3) - 1; i++)
        {
            for (j = 0 ; j < (lineCount / 3) - i - 1; j++)
            {
                if (errors[j] > errors[j + 1])
                {
                    aux = errors[j];
                    errors[j] = errors[j + 1];
                    errors[j + 1] = aux;
                }
            }
        }

        rewind(rank);

        i = 0;

        while (i < lineCount / 3)
        {
            pointerPosition = ftell(rank);

            fgets(line, 100, rank);
            fgets(line, 100, rank);
            strtok(line, "\n");

            if (atoi(line) == errors[i])
            {
                fseek(rank, pointerPosition, SEEK_SET);

                fgets(line, 100, rank);
                fprintf(temp, "%s", line);

                fgets(line, 100, rank);
                fprintf(temp, "%s", line);

                fgets(line, 100, rank);
                fprintf(temp, "%s", line);

                i++;

                rewind(rank);
            } else
            {
                fgets(line, 100, rank);
            }
        }
        
        fclose(temp);
        fclose(rank);

        remove("rank.txt");
        rename("temp.txt", "rank.txt");
    }

}

void help()
{
    display(16);

    printf("\nPressione \"enter\" para continuar\n");
    getchar();
    
    if (os == 1)
    {
        system("cls");
    } else if (os == 2)
    {
        system("clear");
    }
}
