#include <stdio.h>
#include <stdlib.h>

// Input for this function is (turn, board , board size, struct pointer)

int player_move(int turn, char board[n][n], int n, struct Score *scorepointer) 
{

    char letter; 
    int row, column, player;
    char *ptr;

    if ( turn%2 == 1)
    {
        player = 1;
    }
    else 
    {
        player = 2;
    }

    printf("\nIt is player %d's turn. What letter would you like to enter? S/O", player);
    
    while ( letter != 's' && letter != 'S' && letter != 'o' && letter != 'O')
    {
        letter = getchar();
        getchar();
    }
    
    if ( letter == 's')
    {
        letter = 'S';
    }
    else if ( letter == 'o')
    {
        letter = 'O';
    }

    printf("\nYou chose the letter %c", letter);
    do
    {
        printf("\n Please enter the row only.");
        scanf("%d", &row);
        printf(" \n Row = %d", row);
        row = row - 1;

        printf("\n Please enter the column only.");
        scanf("%d", &column);
        printf(" \n Column = %d", column);
        column = column - 1; 
    }while ( !valid_entry(row, column, board));
    
    board[row][column] = response;
    ptr = &board[row][column];
    
    if (letter == 'S')
    { 
        a = check_S(ptr, row, column, n);
    }
    elseif(letter == 'O')
    {
        a = check_O(ptr, row, column, n);
    }

    if ( player == 1)
    {
        (scorepointer->playerone) += a;
    }
    else if 
    {
        (scorepointer->playertwo) += a;
    }


}
