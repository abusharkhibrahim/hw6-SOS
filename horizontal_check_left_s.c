int horizontal_check_left_S(char  *ptr, int n)
{
    int a =0;
    if ( *(ptr -= 1) == 'O')
    {
        if ( *(ptr -= 2) == 'S')
        {
            a = a + 1;
        }
    }
    
    return a;
}
