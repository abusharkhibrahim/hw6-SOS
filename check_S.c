

int check_S( char *ptr, int row, int col, int n)


    if ( (row +3) <= n)
    {
        a = a + vertical_check_down_S(ptr,n);

        if ( (col+3) <=n)
        {
            a = a + diagonal_check_down_right_S(ptr,n);
        }
        if  ((col-3) >= 0)
        {
            a = a + diagonal_check_down_left_S(ptr,n);
        }
    }

    if ( (row - 3) >= 0)
    {
        a = a + vertical_check_up_S(ptr,n);

        if ( (col+3) <= n)
        {
            a = a + diagonal_check_up_left_S(ptr,n);
        }
        if ( (col-3) >= 0)
        {
            a = a + diagonal_check_up_left_S(ptr,n);
        }
    }
    
    if ( (row - 3) >= 0)
    {
        a = a + horizontal_check_left_S(ptr,n);
    }

    if ( (row + 3) <= n)
    {
        a = a + horizontal_check_right_S(ptr,n);
    }


    return a;
}
