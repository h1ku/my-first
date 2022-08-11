#include <stdio.h>

int fibonacci (int n)
{
    int i, x, y, z;
    x = 1;
    y = 1;
    z = 1;
    for (i = 2; i <= n; i++)
    {
        z = x + y;
        x = y;
        y = z;
    }
    return(x);
}

int main()
{
    int n, x;
    printf("Vous voulez calculer le ... terme de la suite de Fibonacci\n");
    scanf("%d", &n);
    x = fibonacci(n);
    printf("\n %d", x);
    return(0);
}
