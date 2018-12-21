#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

    for (i=0; i<n; i++)
    {
        printf("\n");
        if ( (i != 0) && (i != n))
        {
            printf("%s\n", line);
        }
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

int main()
{
    int n =7;
    int i, j;
    char board[n][n];

    for (i=0; i < n; i++)
    {
        for (j=0; j<n; j++)
        {
            board[i][j] = 'O';
        }
    }
    
    drawboard(n, board);

}
