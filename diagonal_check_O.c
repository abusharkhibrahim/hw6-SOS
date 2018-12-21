int diagonal_check_O(char *ptr, int n)
{
    int a = 0;
    
    if ( *(ptr += (n+1)) == 'S' && *(ptr -= (n+1)) == 'S')
    {
        a += 1;
    }
    if ( *(ptr += (n-1)) == 'S' && *(ptr -= (n-1)) == 'S')
    {
        a += 1;
    }

    return a;

}
