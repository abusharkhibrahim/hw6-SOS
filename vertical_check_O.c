

int vertical_check_O(char *ptr, int n)
{
    int a;
    
    if ( *(ptr += n) == 'S' && *(ptr -= n) == 'S')
    {
        a = 1;
    }
    else
    {
        a = 0;
    }

    return a;

}
