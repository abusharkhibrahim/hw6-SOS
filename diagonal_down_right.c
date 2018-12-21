int diagonal_check_down_right_S(char *ptr, int n)
{
    int a =0;
    if ( *(ptr += (n+1)) == 'O')
    {
        if ( *(ptr += (2*n+2)) == 'S')
        {
            a = a + 1;
        }
    }
    return a;
}
