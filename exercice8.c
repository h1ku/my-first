#include <stdio.h>

int comparaison(char c1[], char c2[])
{
    char * p;
    p = &c1[0];
    int i = 0;
    while(*p)
    {
        if (c1[i] < c2[i])
        {return(-1);}
        else if (c1[i] > c2[i])
        {return(1);}
        i += 1;
        p = p + 1;
    }
    return(0);
}

int main()
{
    int a1, a2, a3;
    char b[10] = "aa";
    char c[10] = "aa"; 
    char d[10] = "ab";
    //a = (*b < *c);
    a1 = comparaison(b,c);
    a2 = comparaison(b,d);
    a3 = comparaison(d,b);
    printf("%d \n",a1);
    printf("%d \n",a2);
    printf("%d",a3);
}