int valid_entry(int row, int col, char baord[n][n])
{
    if ( board[row][col] == ' ' )
    {
        return 1;
    }
    else 
    {
        printf("\n The square you are trying to use is not empty. Please try again.");
        return 0;
    }

}
