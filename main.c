#include <stdio.h>
#include <stdlib.h>
#include "module.h"

int* simple()
{
    int *p;
    int a = 5, b = 6;
    p = (int*)malloc(2 * sizeof(int));
    *p = a;
    *(p + 1) = b;
    return(p);
}

int main()
{
    //int a = add_one(5);
    //int b = double_it(5);
    //printf("%d \n", a);
    //printf("le double de 5 est %d \n", b);
    
    printf("%d;%d", *simple(), *(simple()+1));
    return(0);
}