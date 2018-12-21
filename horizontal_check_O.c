

int horizontal_check_O(char *ptr)
{

    int a;

    if ( *(ptr++) == 'S' && *(ptr--) == 'S' )
    {
        a = 1;
    }
    else 
    {
        a = 0;
    }

    return a;

}
