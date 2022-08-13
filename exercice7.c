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

int main()
{
    //char t[5] = "allo";
    //char * p;
    //p = &t[0];
    //while(*p)
    //{
    //   printf("%s \n", p);
    //   p = p + 1;
    //}
    char a[10] = "hello";
    printf("%d",mylen(a));
    return(0);
}


//Ce que l'exercice m'a appris, c'est qu'en C, les chaines de charactere ne fonctionnent pas comme les listes, lorsque je
//pointe un charactere, c'est tout le mot à partir de ce dernier qui s'affiche. Et la chaine est vide après ce que l'on
//a rentré.