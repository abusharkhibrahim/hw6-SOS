int vertical_check_up_S( char *ptr, int n)
{
    int a =0;
    if ( *(ptr -= n) == 'O')
    {
        if ( *(ptr -= (n*2)) == 'S')
        {
            a = a + 1;
        }
    }
    
    return a;
}
