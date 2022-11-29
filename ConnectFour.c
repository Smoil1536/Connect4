// Header files
#include <stdio.h>
#include <stdio.h>
#include <time.h>

// Some variables
#define RED "\x1b[31m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
char board[5][6] = {{"OOOOOO"}, {"OOOOOO"},{"OOOOOO"},{"OOOOOO"},{"OOOOOO"}};
char Color1, Color2;

// Functions
void PrintBoard();
char Winner(int, int);
int EvenOdd(int);

// Main function
int main(void)
{
    int column, temp;
    int i = 1, tmp;
    int k;
    char winner;

    printf("Please choose R for red & C for cyan !\n");
    printf("Player 1's color: ");
    scanf("%c", &Color1);

    if(Color1 == 'r' || Color1 == 'R')
        Color2 = 'C';
    else
        Color2 = 'R';
    system("cls || clear");

    while(winner != '1' && winner != '2')
    {
        PrintBoard();
        tmp = EvenOdd(i);
        printf("Enter column (player %d): ",tmp);
        scanf("%d", &column);

        system("cls || clear");
        column--;

        if(column > 5 || column < 0)
        {
            printf("Please enter a valid column number !\n");
            continue;
        }

        for(k = 4; k >= 0; k--)
        {
            if(board[k][column] == 'O')
            {
                temp = 1;
                break;
            }
            else
                temp = 0;
        }

        if(!temp)
            printf("This column is already filled, please try other columns !\n");
        
        if(tmp == 1)
            board[k][column] = '1';
        else
            board[k][column] = '2';

        winner = Winner(k, column);
        i++;
    }
        PrintBoard();

        if(winner == '1')
            printf("Player 1 won the game :)");
        else if(winner == '2')
            printf("Player 2 won the game :)");

    return 0;
}

void PrintBoard()
{
    printf("----------------------\n");

    for(int i = 0; i < 5; i++)
    {
        printf("|");
        for(int j = 0; j < 6; j++)
        {
            // This conditional statement is just for using the right color :|
            if(board[i][j] == '1')
            {
                if(Color1 == 'R' || Color1 == 'r')
                    printf("%s",RED);
                else 
                    printf("%s",CYAN);
            }
            else if(board[i][j] == '2')
            {
                if(Color2 == 'R' || Color2 == 'r')
                    printf("%s",RED);
                else 
                    printf("%s",CYAN);
            }
            printf("  %c", board[i][j]);
            printf("%s", WHITE);
        }
        printf("  |\n");
        if(i!=4)
            printf("|                    |\n");
    }  
    printf("----------------------\n");
}   

int EvenOdd(int i)
{
    if(i%2 == 0)
        return 2;
    else
        return 1;
}

char Winner(int row, int column)
{
    // hmmm...
    int count = 0;

    // Left check
    int tmp = column;
    for(int i = 0; i < 3; i++)
    {
        if(board[row][tmp] != board[row][tmp-1])
        {
            count = 0;
            break;
        }
        else
            count = 1;
        
        tmp--;
    }
    if(count)
        return board[row][column];

    // Right check
    tmp = column;
    for(int i = 0; i < 3; i++)
    {
        if(board[row][tmp] != board[row][tmp+1])
        {
            count = 0;
            break;
        }
        else
            count = 1;
        
        tmp++;
    }
    if(count)
        return board[row][column];

    // we don't need up check xD
    // down check
    tmp = row;
    for(int i = 0; i < 3; i++)
    {
        if(board[tmp][column] != board[tmp+1][column])
        {
            count = 0;
            break;
        }
        else
            count = 1;
        
        tmp++;
    }
    if(count)
        return board[row][column];

    // Diagonal check - 1
    tmp = row;
    int tmp2 = column;
    for(int l = 0; l < 3; l++)
    {
        if(board[tmp][tmp2] != board[tmp+1][tmp2+1])
        {
            count = 0;
            break;
        }
        else
            count = 1;
        
        tmp++;
        tmp2++;
    }
    if(count)
        return board[row][column];

    // Diagonal check - 2
    tmp = row;
    tmp2 = column;
    for(int k = 0; k < 3; k++)
    {
        if(board[tmp][tmp2] != board[tmp-1][tmp2+1])
        {
            count = 0;
            break;
        }
        else
            count = 1;
        
        tmp--;
        tmp2++;
    }
    if(count)
        return board[row][column];

    // Diagonal check - 3
    tmp = row;
    tmp2 = column;
    for(int j = 0; j < 3; j++)
    {
        if(board[tmp][tmp2] != board[tmp+1][tmp2-1])
        {
            count = 0;
            break;
        }
        else
            count = 1;
        
        tmp++;
        tmp2--;
    }
    if(count)
        return board[row][column];

    // Diagonal check - 4
    tmp = row;
    tmp2 = column;
    for(int i = 0; i < 3; i++)
    {
        if(board[tmp][tmp2] != board[tmp-1][tmp2-1])
        {
            count = 0;
            break;
        }
        else
            count = 1;
        
        tmp--;
        tmp2--;
    }
    if(count)
        return board[row][column];

    return 'O';
}