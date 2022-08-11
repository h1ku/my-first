#include <stdio.h>

int print_tableau(int tableau[], int n)
{
    int x;
    for (int i = 0; i < n; i ++)
    {
        x = tableau[i];
        printf("%d,", x);
    } 
    return(0);  
}

int main()
{
    #define n 50;
    int tableau[50];
    for (int i = 0; i < 50; i++)
    {
        tableau[i] = 2*i;
    }
    print_tableau(tableau, 50);
    return(0);
}