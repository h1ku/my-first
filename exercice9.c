#include <stdio.h>

int mylen(char t[])
{
    char * p;
    p = &t[0];
    int taille = 0;
    while(*p)
    {
        taille += 1;
        p = p + 1;
    }
    return(taille);
}

int est_palindrome(char c[])
{
    int taille = mylen(c);
    for(int i = 0; i<taille; i++)
    {
        if (c[i] != c[taille - 1 - i])
        {
            return(0);
        }
    }
    return(1);
}


int main()
{
    int a = est_palindrome("lol");
    int b = est_palindrome("le");
    printf("%d, %d", a,b);
    return(0);    
}   