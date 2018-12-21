

int check_O( char *ptr, int row, int col, int n)
{
    int a = 0;

    if ( (row != 0 && col != 0) || ( row != 0 && col != (n-1)) || ( row != (n-1) && col != 0) || ( row != (n-1) && col != (n-1)))
    {
        if ( (col - 1) > 0 && (col + 1) < n)
        {
           a = a + horizontal_check_O(ptr);
        }
        if ( (row - 1) > 0 && (row + 1) < n)
        {
            a = a + vertical_check_O(ptr);
        }
        if ( ((row - 1) > 0 && (row + 1) < n) && ((row - 1) > 0 && (row + 1) < n))
        {
            a = a + diagonal_check_O(ptr);
        }
   
    }

return a;

}

