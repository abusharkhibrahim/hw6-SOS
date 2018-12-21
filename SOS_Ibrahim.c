#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global Variables
struct Score{
    int playerone;
    int playertwo;
}game;

int check_S(  int row, int col, int n, char board[n][n]);
int check_O(  int row, int col, int n, char board[n][n]);
int diagonal_check_O( int row, int col, int n, char board[n][n]);
int horizontal_check_O( int row, int col, int n, char board[n][n]);
int vertical_check_O(int row, int col,  int n, char board[n][n]);
int horizontal_check_left_S( int row, int col, int n, char board[n][n]);
int horizontal_check_right_S( int row, int col, int n, char board[n][n]);
int vertical_check_down_S( int row, int col, int n, char board[n][n]);
int vertical_check_up_S( int row, int col, int n, char board[n][n]);
int diagonal_check_up_left_S( int row, int col, int n, char board[n][n]);
int diagonal_check_up_right_S( int row, int col, int n, char board[n][n]);
int diagonal_check_down_left_S( int row, int col, int n, char board[n][n]);
int diagonal_check_down_right_S( int row, int col, int n, char board[n][n]);




void drawboard(int n, char board[n][n])
{
    int i, j, k;
    char line[(n*6)];
    k = 0;
    while ( k <= (n*6))
    {
        line[k] = '*';
        k++;
    }

    k = 1;
    printf("\n    ");
    while ( k <= n)
    {
        printf("  %d   ", k);
        k++;
    }
    printf("\n    ");

    k = 1;
    while ( k <= n)
    {
        printf("  -   ");
        k++;
    }
    //printf("\n");

    for (i=0; i<n; i++)
    {

        printf("\n");

        if ( (i != 0) && (i != n))
        {
            printf("%s\n", line);
        }

        printf(" %d| ", (i+1));
        for (j=0; j<n; j++)
        {
            if ( j != (n-1) )
            {
                printf("  %c  *", board[i][j]);
            }
            else if (j == (n-1))
            {
                printf("  %c  ", board[i][j]);
            }
        }
    }
    printf("\n");
}

void init_board(int n, char board[n][n])
{
    int i, j;

    for (i=0; i < n; i++)
    {
        for (j=0; j<n; j++)
        {
            board[i][j] = ' ';
        }
    }
}

int valid_entry(int n, int row, int col, char board[n][n])
{
    if ( row <= n && col <=n)
    {
        if ( board[row][col] == ' ')
        {
            return 1;
        }
        else
        {
            printf("\n The square you are trying to use is not empty. Please try again.");
            return 0;
        }
    }
    else
    {
        printf(" You are trying to input an invalid index. Please try again.");
        return 0;
    }
}

void player_move(int turn, int n, char board[n][n], struct Score *scorepointer)
{

    char letter = 'a';
    int  a, row, column, player;
    char *ptr;

    if ( turn%2 == 1)
    {
        player = 1;
    }
    else
    {
        player = 2;
    }

    printf("\nIt is player %d's turn. What letter would you like to enter? S/O\n", player);

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
        getchar();
        printf(" \n Row = %d", row);
        row = row - 1;

        printf("\n Please enter the column only.");
        scanf("%d", &column);
        getchar();
        printf(" \n Column = %d", column);
        column = column - 1;
    }while ( !valid_entry(n, row, column, board));

    board[row][column] = letter;
   
    if (letter == 'S')
    {
        a = check_S(row, column, n, board);
    }
    else if(letter == 'O')
    {
        a = check_O(row, column, n, board);
    }

    if ( player == 1)
    {
        (scorepointer->playerone) += a;
    }
    else 
    {
        (scorepointer->playertwo) += a;
    }

}

int check_O( int row, int col, int n, char board[n][n])
{
    int a = 0;

//    if ( (row != 0 && col != 0) || ( row != 0 && col != (n-1)) || ( row != (n-1) && col != 0) || ( row != (n-1) && col != (n-1)))
//    {
        if ( (col - 1) >= 0 && (col + 1) <= n)
        {
           a = a + horizontal_check_O(row, col, n, board);
        }
        if ( (row - 1) >= 0 && (row + 1) <= n)
        {
            a = a + vertical_check_O(row, col, n, board);
        }
        if ( ((row - 1) >= 0 && (row + 1) <= n) && ((row - 1) >= 0 && (row + 1) <= n))
        {
            a = a + diagonal_check_O(row, col,  n, board);
        }
   
 //   }

return a;

}

int check_S( int row, int col, int n, char board[n][n])
{
    int a =0;
    if ( (row +2) <= n)
    {
        a = a + vertical_check_down_S(row, col, n, board);

        if ( (col+2) <=n)
        {
            a = a + diagonal_check_down_right_S(row, col,  n, board);
        }
        if  ((col-2) >= 0)
        {
            a = a + diagonal_check_down_left_S(row, col, n, board);
        }
    }

    if ( (row - 2) >= 0)
    {
        a = a + vertical_check_up_S(row, col, n, board);

        if ( (col+2) <= n)
        {
            a = a + diagonal_check_up_right_S(row, col, n, board);
        }
        if ( (col-2) >= 0)
        {
            a = a + diagonal_check_up_left_S(row, col, n, board);
        }
    }
    
    if ( (col - 2) >= 0)
    {
        a = a + horizontal_check_left_S(row, col, n, board);
    }

    if ( (col + 2) <= n)
    {
        a = a + horizontal_check_right_S(row, col,  n, board);
    }


    return a;
}

int diagonal_check_O( int row, int col, int n, char board[n][n])
{
    int a = 0;

    if ( board[row+1][col+1] == 'S' && board[row-1][col-1] == 'S')
    {
        a += 1;
    }
    if ( board[row-1][col+1] == 'S' && board[row+1][col-1] == 'S')
    {
        a += 1;
    }

    return a;

}

int horizontal_check_O( int row, int col, int n, char board[n][n])
{

    int a;

    if ( board[row][col-1] == 'S' && board[row][col+1] == 'S' )
    {
        a = 1;
    }
    else 
    {
        a = 0;
    }

    return a;

}

int vertical_check_O( int row, int col, int n, char board[n][n])
{
    int a;

    if ( board[row-1][col] == 'S' && board[row+1][col] == 'S')
    {
        a = 1;
    }
    else
    {
        a = 0;
    }

    return a;

}

int horizontal_check_left_S( int row, int col, int n, char board[n][n])
{
    int a =0;
    if ( board[row][col-1] == 'O')
    {
        if ( board[row][col-2] == 'S')
        {
            a = a + 1;
        }
    }

    return a;
}

int horizontal_check_right_S( int row, int col, int n, char board[n][n])
{
    int a =0;
    if ( board[row][col+1]== 'O')
    {
        if ( board[row][col+2]== 'S')
        {
            a = a + 1;
        }
    }

    return a;
}

int vertical_check_down_S( int row, int col, int n, char board[n][n])
{
    int a = 0;
    if ( board[row+1][col]== 'O')
    {
        if ( board[row+2][col] == 'S')
        {
            a = a + 1;
        }
    }
    
    return a;

}

int vertical_check_up_S( int row, int col, int n, char board[n][n])
{
    int a =0;
    if ( board[row-1][col] == 'O' && board[row-2][col] == 'S')
    {
        a = a + 1;
    }

    return a;
}


int diagonal_check_up_left_S( int row, int col, int n, char board[n][n])
{
    int a =0;
    if ( board[row-1][col-1] == 'O')
    {
        if ( board[row-2][col-2] == 'S')
        {
            a = a + 1;
        }
    }
    return a;
}

int diagonal_check_up_right_S( int row, int col, int n, char board[n][n])
{
    int a =0;
    if ( board[row-1][col+1] == 'O')
    {
        if ( board[row-2][col+2] == 'S')
        {
            a = a + 1;
        }
    }
    return a;
}

int diagonal_check_down_left_S( int row, int col, int n, char board[n][n])
{
    int a =0;
    if ( board[row+1][col-1] == 'O')
    {
        if ( board[row+1][col-2] == 'S')
        {
            a = a + 1;
        }
    }
    return a;
}

int diagonal_check_down_right_S( int row, int col, int n, char board[n][n])
{
    int a =0;
    if ( board[row+1][col+1] == 'O')
    {
        if ( board[row+2][col+2] == 'S')
        {
            a = a + 1;
        }
    }
    return a;
}





int main()
{
   
    struct Score game = { 0, 0};
    struct Score *ptr;
    ptr = &game;
    int turn =1;
    int n;

    printf("\n Welcome to SOS please enter enter the board size (integer value >3)");
    while ( n < 3)
    {
        scanf("%d", &n);
        getchar();
    }
    int i, j;
    char board[n][n];
    init_board(n, board);    

    while (turn <= (n*n))
    {
        printf("\n       * Player 1 * Player 2 \n");
        printf("*****************************\n");
        printf(" Score *    %d    *    %d   *\n", (ptr->playerone), (ptr->playertwo));
        printf("*****************************\n");
        
        drawboard(n, board);
        player_move( turn, n, board, ptr);
        turn++;
    }
}
