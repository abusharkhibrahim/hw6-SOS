#include <stdio.h>
#include <stdlib.h>

// Input for this function is board and turn

int player_move(int turn, char board[n][n]) 
{
    char letter; 
    int row, column;
    
    printf("\nWhat letter would you like to enter? S/O\n");
    
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

    printf("You chose the letter %c\n", letter);
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

    int index[2] = { row, column }; 
     


}
